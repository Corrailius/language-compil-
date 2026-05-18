#include <stdio.h>

double moyenne(int t[], int n) {
int somme = 0;
for (int i = 0; i < n; i++) somme += t[i];
    return (double)somme / n;
}

void min_max(int t[], int n, int *pmin, int *pmax) {
    *pmin = *pmax = t[0];
    for (int i = 1; i < n; i++) {
        if (t[i] < *pmin) *pmin = t[i];
        if (t[i] > *pmax) *pmax = t[i];
    }
}

int main(void) {
    int notes[6] = { 14, 17, 9, 12, 18, 11 };
    int mn, mx;
    min_max(notes, 6, &mn, &mx);
    printf("Min=%d, Max=%d, Moy=%.2f\n", mn, mx, moyenne(notes, 6));
    return 0;
}