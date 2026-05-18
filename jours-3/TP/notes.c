#include <stdio.h>

int main(void) {
    int note;
    printf("Note (0-20) : ");
    scanf("%d", &note);
    if (note < 0 || note > 20) {
        printf("Note invalide\n");
    } else if (note > 10) {
        printf("Admis\n");
    } else {
        printf("Non admis\n");
    }
    return 0;
}