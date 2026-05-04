#include <stdio.h>

int main() {
    int a, b;
    printf("Entrez deux nombres entiers : ");
    scanf("%d %d", &a, &b);
    
    int somme = a + b;
    int difference = a - b;
    int produit = a * b;
    double quotient = (b != 0) ? (double)a / b : 0; // Éviter la division par zéro

    printf("Somme : %d\n", somme);
    printf("Différence : %d\n", difference);
    printf("Produit : %d\n", produit);
    if (b != 0) {
        printf("Quotient : %.2f\n", quotient);
    } else {
        printf("Division par zéro n'est pas autorisée.\n");
    }

    return 0;
}