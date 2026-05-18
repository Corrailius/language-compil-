#include <stdio.h>
void doubler(int x) {
    x = x * 2;
    return x;
}
int minimum(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}
int maximum(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}
int valeur_absolue(int x) {
    if (x < 0) {
        return -x;
    } else {
        return x;
    }
}
int est_pair(int x) {
    return x % 2 == 0;
}
long factorielle(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorielle(n - 1);
    }
}
int main(void) {
    int valeur = 10;
    int result = 20;
    doubler(valeur);
    minimum(valeur, result);
    maximum(valeur, result);
    valeur_absolue(-5);
    est_pair(valeur);
    factorielle(5);
    printf("valeur = %d\n", valeur);
    printf("minimum = %d\n", minimum(valeur, result));
    printf("maximum = %d\n", maximum(valeur, result));
    printf("valeur absolue = %d\n", valeur_absolue(-5));
    printf("est pair = %s\n", est_pair(valeur) ? "true" : "false");
    printf("factorielle = %ld\n", factorielle(5));

    return 0;
}
