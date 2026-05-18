#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int jouer(int secret)
{
    int essai;
    int tentatives = 0;

    do {
        printf("Entrez un nombre entre 1 et 100 : ");
        if (scanf("%d", &essai) != 1) {
            int c;
            while ((c = getchar()) != EOF && c != '\n');
            printf("Entrée invalide. Veuillez saisir un entier.\n");
            continue;
        }

        tentatives++;

        if (essai < secret) {
            printf("trop petit\n");
        } else if (essai > secret) {
            printf("trop grand\n");
        }
    } while (essai != secret);

    return tentatives;
}

int main(void)
{
    srand((unsigned)time(NULL));
    int secret = rand() % 100 + 1;
    int tentatives = jouer(secret);

    printf("Bravo ! Vous avez trouve le nombre en %d tentative%s.\n",
           tentatives,
           tentatives > 1 ? "s" : "");

    return 0;
}
