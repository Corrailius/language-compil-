#include <stdio.h>

void min_max(int tab[], int n, int *pmin, int *pmax)
{
    if (n <= 0 || tab == NULL || pmin == NULL || pmax == NULL) {
        return;
    }

    int min = tab[0];
    int max = tab[0];

    for (int i = 1; i < n; i++) {
        if (tab[i] < min) {
            min = tab[i];
        }
        if (tab[i] > max) {
            max = tab[i];
        }
    }

    *pmin = min;
    *pmax = max;
}

double moyenne(int tab[], int n)
{
    if (n <= 0 || tab == NULL) {
        return 0.0;
    }

    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += tab[i];
    }

    return (double)sum / n;
}

int main(void)
{
    int values[] = { 10, 5, 7, 3, 9 };
    int n = sizeof(values) / sizeof(values[0]);
    int minValue = 0;
    int maxValue = 0;

    min_max(values, n, &minValue, &maxValue);
    printf("min = %d, max = %d\n", minValue, maxValue);
    printf("average = %.2f\n", moyenne(values, n));

    return 0;
}
