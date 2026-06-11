#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *tab = NULL;
    long long somme = 0;

    // Demander le nombre d'entiers a stocker
    printf("Combien d'entiers voulez-vous stocker ? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        fprintf(stderr, "Nombre d'entiers invalide.\n");
        return 1;
    }

    // Allouer de la memoire pour n entiers
    tab = malloc(n * sizeof(int));
    if (tab == NULL) {
        fprintf(stderr, "Echec de l'allocation memoire.\n");
        return 1;
    }

    // Saisir les valeurs et calculer la somme
    for (int i = 0; i < n; i++) {
        printf("Valeur %d: ", i + 1);
        if (scanf("%d", &tab[i]) != 1) {
            fprintf(stderr, "Entree invalide.\n");
            free(tab);
            return 1;
        }
        somme += tab[i];
    }

    // Afficher les valeurs saisies, la somme et la moyenne
    printf("\nValeurs saisies:\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", tab[i]);
    }

    // Afficher la somme et la moyenne
    printf("\nSomme = %lld\n", somme);
    printf("Moyenne = %.2f\n", (double)somme / n);
    
    // free la memoire allouee
    free(tab);
    return 0;
}
