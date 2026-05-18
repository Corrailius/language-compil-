#include <stdio.h>
#include <string.h>

int somme(int x[], int length){
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += x[i];
    }
    return sum;
}
int moyenne(int x[], int length){
    int sum = somme(x, length);
    return sum / length;
}
int minimum(int x[], int length){
    int min = x[0];
    for (int i = 1; i < length; i++) {
        if (x[i] < min) {
            min = x[i];
        }
    }
    return min;
}
int maximum(int x[], int length){
    int max = x[0];
    for (int i = 1; i < length; i++) {
        if (x[i] > max) {
            max = x[i];
        }
    }
    return max;
}

int main(void) {
    int note[8] = { 12, 15, 8, 10, 18, 20, 5, 14 };
    char prenom[20] = "Ayoub"; // taille 20, contient 'A','y
    printf("Bonjour %s\n", prenom);
    printf("Longueur : %zu\n", strlen(prenom)); // 5
    char autre[20];
    strcpy(autre, "Adam"); // copier
    if (strcmp(prenom, autre) == 0) { // comparer
        printf("Prenoms identiques\n");
    } else {
        printf("Prenoms differents\n");
    }
    printf("Somme : %d\n", somme(note, 8));
    printf("Moyenne : %d\n", moyenne(note, 8));
    printf("Minimum : %d\n", minimum(note, 8));
    printf("Maximum : %d\n", maximum(note, 8));
    return 0;
}
