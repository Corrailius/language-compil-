#include <stdio.h>

int main(void)
{
    int n;

    do {
        printf("Entrez un nombre (0 pour quitter) : ");
        if (scanf("%d", &n) != 1) {
            return 1;
        }

        if (n != 0) {
            printf("Table de multiplication de %d:\n", n);
            for (int i = 1; i <= 10; i++) {
                printf("%d x %d = %d\n", n, i, n * i);
            }
        }
    } while (n != 0);

    return 0;
}
