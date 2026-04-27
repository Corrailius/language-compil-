#include <stdio.h>

int main(void) {
char prenom[] = "Alice";
int age = 20;
float taille = 1.75f;
char initiale = 'A';
printf("+-----------------------------+\n");
printf("|   Fiche d'identite          |\n");
printf("+-----------------------------+\n");
printf("|   Prenom   : %s             |\n", prenom);
printf("|   Age      : %d ans         |\n", age);
printf("|   Taille   : %.2f m         |\n", taille);
printf("|   Initiale : %c             |\n", initiale);
printf("+-----------------------------+\n");
printf("|   Code de sortie : %d       |\n", 0);
printf("+-----------------------------+\n");

return 0;
};