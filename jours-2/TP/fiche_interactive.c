#include <stdio.h>

int main(void) {
int age;
float moyenne;
char prenom[30];

printf("Quel est ton prenom ? ");
scanf("%29s", prenom);

printf("Quel age as-tu ? ");
scanf("%d", &age);

printf("Quelle est ta moyenne ? ");
scanf("%f", &moyenne);

printf("Bonjour %s, %d ans, tu as %.2f de moyenne. \n", prenom, age, moyenne);
return 0;
}