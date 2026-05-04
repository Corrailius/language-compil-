#include <stdio.h>

int main(void) {
printf(" == Tailles des types ( == \n");
printf("char : %zu octet(s)\n", sizeof(char));
printf("short : %zu octet(s)\n", sizeof(short));
printf("int : %zu octet(s)\n", sizeof(int));
printf("long : %zu octet(s)\n", sizeof(long));
printf("float : %zu octet(s)\n", sizeof(float));
printf("double : %zu octet(s)\n", sizeof(double));
return 0;
}