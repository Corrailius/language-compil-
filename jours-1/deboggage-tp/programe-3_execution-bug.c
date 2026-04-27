#include <stdio.h>

int main() {
    int a = 10;
    int b = 0;
    int result = a / b;
    if (b == 0) {
        printf("Erreur: Division par zéro!\n");
        return 1; // Code d'erreur
    }
    printf("Resultat: %d\n", result);
    return 0;
}