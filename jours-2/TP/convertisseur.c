#include <stdio.h>

int main(void) {
    double A;
    int unite;
    
    printf("Veillez entrer une Unité:\n 1: km\n 2: miles\n 3: °C\n 4: °F\n 5: lb\n 6: kg\n 0: Quitter\n");
    scanf("%d", &unite);
    if (unite < 0 || unite > 6) {
        printf("Unité non reconnue.\n");
        return 1;
    } else if (unite == 0) {
        printf("Au revoir!\n");
        return 0;
    } else {
        printf("Veillez entrer une Valeur: ");
        scanf("%lf", &A);
    }
        
    start:
        switch (unite)
        {
            case 1: // km
                printf("%.2lf km = %.2lf miles\n", A, A * 0.621371);
                goto start;
    
            case 2: // miles
                printf("%.2lf miles = %.2lf km\n", A, A * 1.60934);
                goto start;
    
            case 3: // °C
                printf("%.2lf °C = %.2lf °F\n", A, (A * 9/5) + 32);
                goto start;
    
            case 4: // °F
                printf("%.2lf °F = %.2lf °C\n", A, (A - 32) * 5/9);
                goto start;
    
            case 5: // lb
                printf("%.2lf lb = %.2lf kg\n", A, A * 0.453592);
                goto start;
    
            case 6: // kg
                printf("%.2lf kg = %.2lf lb\n", A, A * 2.20462);
                goto start;
            
            case 0: // Quitter
                printf("Au revoir!\n");
                return 0;
            
            default:
                printf("Unité non reconnue.\n");
                printf("Veuillez entrer une unité valide (km, miles, C, F, lb, kg).\n");
                goto start;
        }
}