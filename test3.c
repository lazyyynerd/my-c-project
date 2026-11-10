#include <stdio.h>
#include <stdlib.h>
#include <windows.applicationmodel.activation.h>
int main() {
char c;
float met,kmet,convert;
printf("==CONVERTION KM OU M===");
do {
printf("choisir l'unite a convertir, saisir m ou km (saisir m pour convertir en metre et k pour convertir en kilometre)");
scanf(" %c",&c);
    switch (c)
 {
    case 'm':
        printf("donner la valeur en km");
        scanf("%f",&kmet);
        convert = kmet*1000;
        printf("la valeur est %f", convert);
        break;
    case 'k':
        printf("donner la valeur en m");
        scanf("%f",&met);
        convert= met/1000;
        printf("la valeur est %f", convert);    
        break;
    default:
        printf("saisie invalide");
        break;
  }
} while (c != 'm' && c != 'k');
return(0);
}
