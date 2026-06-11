#include <stdio.h>
#include <stdlib.h>

int* creer_tableau(int n) {
int *tableau = malloc(n * sizeof(int)); // Allouer de la mémoire dynamiquement
if (tableau == NULL) {
fprintf(stderr, "Echec de l'allocation memoire.\n");
exit(EXIT_FAILURE);
}
for (int i = 0; i < n; i++) tableau[i] = i;
return tableau; // On retourne l'adresse du tableau alloué
}

int main(void) {
int *t = creer_tableau(5);
printf("%d\n", t[0]); // Que se passe-t-il ?
free(t); // Libérer la mémoire allouée
return 0;
}