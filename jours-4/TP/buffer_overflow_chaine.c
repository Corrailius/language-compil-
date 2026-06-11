#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
char *nom = (char *) malloc(10 * sizeof(char)); // Allouer de la mémoire pour 10 caractères
strcpy(nom, "Alexandre"); // "Alexandre" = 9 chars + '\0'

printf("%s\n", nom);
free(nom);
return 0;
}