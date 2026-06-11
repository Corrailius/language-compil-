#include <stdio.h>
#include <stdlib.h> // pour malloc et free

int main(void) {
int n;

printf("Combien de notes ? ");
scanf("%d", &n);

// Reserver n * sizeof(int) octets sur le tas
int *notes = (int *) malloc(n * sizeof(int));

if (notes == NULL) {
printf("Echec d'allocation\n");
return 1;
}

// Remplir et utiliser
for (int i = 0; i < n; i++) {
notes[i] = 10 + i;
}

// Afficher
for (int i = 0; i < n; i++) {
printf("notes[%d] = %d\n", i, notes[i]);
}

// RENDRE la memoire au systeme
free(notes);
notes = NULL; // eviter de reutiliser un pointeur liber
return 0;
}

/*
    Tout malloc se termine par un free
    Toujours verifier si malloc retourne NULL
    Mettre le pointeur a NULL apres free
*/