#include <stdio.h>

int main(void) {
    int a = 17;
    int b = 5;
    
    printf("Somme = %d\n", a + b);
    printf("Différence = %d\n", a - b);
    printf("Produit = %d\n", a * b);
    printf("Quotient = %d (entier), %2f (flottant)\n", a / b, (float)a / (float)b);
    printf("Reste = %d\n", a % b);
    return 0;
}