#include <stdio.h>

void afficher(void) {
int a = 10;
int b = 20;
int c = 30;
printf("a : valeur=%d, adresse=%p\n", a, (void*)&a);
printf("b : valeur=%d, adresse=%p\n", b, (void*)&b);
printf("c : valeur=%d, adresse=%p\n", c, (void*)&c);
// a, b, c sont detruites automatiquement a la sortie de l
}

int main(void) {
afficher();
afficher(); // les adresses peuvent etre reutilisees !
return 0;
}

/*
1. Les adresses de a, b, c sont-elles consecutives ? Quelle est la
difference entre elles ?
    - les addresses de a, b, c sont generalemnt proches et souvent consecutives sur la pile.
    - la difference correspond a la taille d'un int (généralement 4 octets).

2. Dans quel sens la stack grandit-elle sur votre machine ?
   - Sur la plupart des machines x86/x86_64, la pile grandit vers les
     adresses plus faibles.

3. Que devient la variable a une fois la fonction ''afficher'' terminee ?
   - Elle est détruite et son espace mémoire peut être réutilisé par d'autres appels de fonction.
*/