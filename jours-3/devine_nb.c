#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jouer(int secret)
{
    int essai;
    int tentatives = 0;

    do {
        printf("Entrez un nombre : ");
        if (scanf("%d", &essai) != 1) {
            int c;
            printf("Entrée invalide. Veuillez entrer un nombre entier.\n");
            while ((c = getchar()) != '\n' && c != EOF) {
            }
            continue;
        }

        tentatives++;
        if (essai < secret) {
            printf("Trop petit.\n");
        } else if (essai > secret) {
            printf("Trop grand.\n");
        }
    } while (essai != secret);

    return tentatives;
}

int main(void)
{
    int max = 100;
    int niveau;

    srand((unsigned)time(NULL));

    printf("Choisissez un niveau de difficulté :\n");
    printf("1) 1-50\n");
    printf("2) 1-100\n");
    printf("3) 1-1000\n");
    printf("Votre choix : ");
    if (scanf("%d", &niveau) != 1) {
        niveau = 2;
    }

    switch (niveau) {
        case 1:
            max = 50;
            break;
        case 3:
            max = 1000;
            break;
        default:
            max = 100;
            break;
    }

    int secret = rand() % max + 1;
    printf("Je pense à un nombre entre 1 et %d.\n", max);

    int essais = jouer(secret);
    printf("Bravo ! Vous avez trouvé en %d essai%s.\n", essais, essais > 1 ? "s" : "");

    return 0;
}
