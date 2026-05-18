/*
 * nombre_secret.c - Jeu du nombre secret avec interface TUI retro
 * Compilation : gcc -o nombre_secret nombre_secret.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#endif

/* ── ANSI color codes ─────────────────────────────────────────── */
#define RESET    "\033[0m"
#define BOLD     "\033[1m"
#define PURPLE   "\033[35m"
#define BPURPLE  "\033[1;35m"
#define GREEN    "\033[32m"
#define BGREEN   "\033[1;32m"
#define YELLOW   "\033[33m"
#define BYELLOW  "\033[1;33m"
#define RED      "\033[31m"
#define WHITE    "\033[97m"
#define GRAY     "\033[90m"
#define CYAN     "\033[36m"

/* ── Box-drawing characters ───────────────────────────────────── */
#define H   "\xe2\x94\x80"   /* ─ */
#define V   "\xe2\x94\x82"   /* │ */
#define TL  "\xe2\x94\x8c"   /* ┌ */
#define TR  "\xe2\x94\x90"   /* ┐ */
#define BL  "\xe2\x94\x94"   /* └ */
#define BR  "\xe2\x94\x98"   /* ┘ */
#define TM  "\xe2\x94\xac"   /* ┬ */
#define BM  "\xe2\x94\xb4"   /* ┴ */
#define ML  "\xe2\x94\x9c"   /* ├ */
#define MR  "\xe2\x94\xa4"   /* ┤ */
#define MM  "\xe2\x94\xbc"   /* ┼ */
#define MH  "\xe2\x94\x80"   /* ─ (alias) */

/* ── Largeur du panneau (en caracteres) ───────────────────────── */
#define WIDTH 50

/* ── Utilitaires ──────────────────────────────────────────────── */
static void clear_screen(void)
{
    printf("\033[2J\033[H");
}

static void print_hline(const char *left, const char *mid, const char *right, int w)
{
    printf(PURPLE "%s", left);
    for (int i = 0; i < w; i++) printf(H);
    printf("%s" RESET "\n", right);
    (void)mid;
}

/* Imprime une ligne du panneau avec contenu centre ou aligne a gauche */
static void print_row(const char *color, const char *text)
{
    /* Calcule la longueur visible (sans codes ANSI) */
    int len = 0;
    const char *p = text;
    while (*p) {
        if (*p == '\033') { while (*p && *p != 'm') p++; }
        else { len++; }
        if (*p) p++;
    }
    int padding = WIDTH - len - 2; /* -2 pour les bordures */
    if (padding < 0) padding = 0;

    printf(PURPLE V RESET " %s%s", color, text);
    for (int i = 0; i < padding - 1; i++) printf(" ");
    printf(RESET " " PURPLE V RESET "\n");
}

static void print_empty_row(void)
{
    printf(PURPLE V RESET);
    for (int i = 0; i < WIDTH - 2; i++) printf(" ");
    printf(PURPLE V RESET "\n");
}

/* ── Bandeau titre ASCII ──────────────────────────────────────── */
static void print_title(void)
{
    printf("\n");
    printf(BPURPLE "  ███╗   ██╗ ██████╗ ███╗   ███╗██████╗ ██████╗ ███████╗\n" RESET);
    printf(BPURPLE "  ████╗  ██║██╔═══██╗████╗ ████║██╔══██╗██╔══██╗██╔════╝\n" RESET);
    printf(BPURPLE "  ██╔██╗ ██║██║   ██║██╔████╔██║██████╔╝██████╔╝█████╗  \n" RESET);
    printf(PURPLE  "  ██║╚██╗██║██║   ██║██║╚██╔╝██║██╔══██╗██╔══██╗██╔══╝  \n" RESET);
    printf(PURPLE  "  ██║ ╚████║╚██████╔╝██║ ╚═╝ ██║██████╔╝██║  ██║███████╗\n" RESET);
    printf(GRAY    "  ╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝╚═════╝ ╚═╝  ╚═╝╚══════╝\n" RESET);
    printf(GRAY    "            " CYAN "S E C R E T   G A M E  v1.0" RESET "\n\n");
}

/* ── Menu principal ───────────────────────────────────────────── */
static int show_menu(void)
{
    clear_screen();
    print_title();

    print_hline(TL, NULL, TR, WIDTH - 2);
    print_row(BPURPLE, "MENU PRINCIPAL");
    print_hline(ML, NULL, MR, WIDTH - 2);
    print_empty_row();
    print_row(BGREEN, "\xe2\x97\x8f ACTIF");   /* ● ACTIF */
    print_empty_row();
    print_row(WHITE,  "[1]  1 - 50    " GRAY "(Facile)" RESET);
    print_row(WHITE,  "[2]  1 - 100   " GRAY "(Normal)" RESET);
    print_row(WHITE,  "[3]  1 - 1000  " GRAY "(Difficile)" RESET);
    print_empty_row();
    print_row(GRAY,   "[0]  Quitter");
    print_empty_row();
    print_hline(ML, NULL, MR, WIDTH - 2);
    print_row(GRAY, "Tip: " WHITE "Utilisez les touches 1, 2, 3 ou 0." RESET);
    print_hline(BL, NULL, BR, WIDTH - 2);

    printf(PURPLE "\n  Choix : " RESET);

    int choix = 0;
    char buf[32];
    if (fgets(buf, sizeof(buf), stdin)) {
        choix = atoi(buf);
    }
    return choix;
}

/* ── Affiche le panneau de jeu ────────────────────────────────── */
static void print_game_header(int max, int essais)
{
    char buf[64];

    print_hline(TL, NULL, TR, WIDTH - 2);
    print_row(BPURPLE, "PARTIE EN COURS");
    print_hline(ML, NULL, MR, WIDTH - 2);
    print_empty_row();

    snprintf(buf, sizeof(buf), "Plage : " CYAN "1 — %d" RESET, max);
    print_row("", buf);

    snprintf(buf, sizeof(buf), "Essais : " YELLOW "%d" RESET, essais);
    print_row("", buf);

    print_empty_row();
    print_hline(ML, NULL, MR, WIDTH - 2);
}

/* ── Boucle de jeu ────────────────────────────────────────────── */
static int jouer(int secret, int max)
{
    int essai;
    int tentatives = 0;
    char buf[64];
    char last_msg[128] = "";
    char last_color[32] = "";

    do {
        clear_screen();
        print_title();
        print_game_header(max, tentatives);

        if (strlen(last_msg) > 0) {
            print_row(last_color, last_msg);
            print_empty_row();
        } else {
            print_empty_row();
            print_row(GRAY, "Entrez votre premier essai ci-dessous.");
            print_empty_row();
        }

        print_hline(ML, NULL, MR, WIDTH - 2);
        print_row(GRAY, "Tip: " WHITE "Haut=trop petit  Bas=trop grand" RESET);
        print_hline(BL, NULL, BR, WIDTH - 2);

        printf(PURPLE "\n  Votre nombre : " RESET);

        if (!fgets(buf, sizeof(buf), stdin)) break;
        char *end;
        long n = strtol(buf, &end, 10);
        if (end == buf || (*end != '\n' && *end != '\0')) {
            snprintf(last_msg, sizeof(last_msg), RED "\xe2\x9c\x97" RESET "  Entree invalide. Entrez un entier." RESET);
            strncpy(last_color, "", sizeof(last_color));
            continue;
        }
        essai = (int)n;
        tentatives++;

        if (essai < secret) {
            snprintf(last_msg, sizeof(last_msg),
                YELLOW "\xe2\x96\xb2" RESET YELLOW "  %d — Trop petit !" RESET, essai);
            strncpy(last_color, "", sizeof(last_color));
        } else if (essai > secret) {
            snprintf(last_msg, sizeof(last_msg),
                CYAN "\xe2\x96\xbc" RESET CYAN "  %d — Trop grand !" RESET, essai);
            strncpy(last_color, "", sizeof(last_color));
        }
    } while (essai != secret);

    return tentatives;
}

/* ── Ecran de victoire ────────────────────────────────────────── */
static void show_win(int secret, int essais)
{
    clear_screen();
    print_title();

    print_hline(TL, NULL, TR, WIDTH - 2);
    print_row(BGREEN, "VICTOIRE !");
    print_hline(ML, NULL, MR, WIDTH - 2);
    print_empty_row();

    char buf[128];
    snprintf(buf, sizeof(buf), BGREEN "\xe2\x9c\x94" RESET GREEN "  Le nombre etait : %d" RESET, secret);
    print_row("", buf);

    snprintf(buf, sizeof(buf),
        "  Trouve en : " BYELLOW "%d essai%s" RESET,
        essais, essais > 1 ? "s" : "");
    print_row("", buf);

    /* Etoiles selon performance */
    int etoiles = (essais <= 5) ? 3 : (essais <= 10) ? 2 : 1;
    char stars[64] = "  ";
    for (int i = 0; i < 3; i++) {
        if (i < etoiles) strncat(stars, BYELLOW "\xe2\x98\x85 " RESET, sizeof(stars) - strlen(stars) - 1);
        else             strncat(stars, GRAY "\xe2\x98\x86 " RESET, sizeof(stars) - strlen(stars) - 1);
    }
    print_row("", stars);

    print_empty_row();
    print_hline(ML, NULL, MR, WIDTH - 2);
    print_row(GRAY, "Appuyez sur Entree pour rejouer...");
    print_hline(BL, NULL, BR, WIDTH - 2);

    printf(PURPLE "\n  > " RESET);
    char buf2[8];
    fgets(buf2, sizeof(buf2), stdin);
}

/* ── Point d'entree ───────────────────────────────────────────── */
int main(void)
{
    srand((unsigned)time(NULL));

    /* Active les codes ANSI sur Windows (si supporte) */
#ifdef _WIN32
    #include <windows.h>
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD mode = 0;
    GetConsoleMode(hOut, &mode);
    SetConsoleMode(hOut, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
#endif

    while (1) {
        int choix = show_menu();
        int max;

        switch (choix) {
            case 1:  max = 50;   break;
            case 2:  max = 100;  break;
            case 3:  max = 1000; break;
            case 0:
                clear_screen();
                printf(PURPLE "\n  Au revoir !\n\n" RESET);
                return 0;
            default:
                continue;
        }

        int secret = rand() % max + 1;
        int essais = jouer(secret, max);
        show_win(secret, essais);
    }

    return 0;
}
