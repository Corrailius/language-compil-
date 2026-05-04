#include <stdio.h>
int main(void) {
    double a, b;
    char op;
    printf("Calculatrice C\n");
    printf("Operande 1 : ");
    scanf("%lf", &a);
    printf("Operateur (+ - * /) : ");
    scanf(" %c", &op);
    printf("Operande 2 : ");
    scanf("%lf", &b);
    double resultat = 0;
    if (op == '+') resultat = a + b;
    else if (op == '-') resultat = a - b;
    else if (op == '*') resultat = a * b;
    else if (op == '/') resultat = (b != 0) ? a / b : 0;
    else { printf("Operateur inconnu\n"); return 1; }
    printf("Resultat : %.2f %c %.2f = %.2f\n", a, op, b, resultat);
    return 0;
}