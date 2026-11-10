#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
   float F,C,K;
   char k,f,c,temp,val;
   printf("===CONVERTION KELVIN,CELSUIS,FAHRENHEIT===\n");
   
   do
   {
    printf("\tvoulez vous convertir en fahrenheit,kelvin ou celsuis?\n" "\t tapez 'f','k','c'.\n");
   scanf(" %c",&temp);
    switch (temp)
    {
    case 'k':
        printf("est ce que votre temperature est en Celsius? tapez 'y' ou 'n'");
        scanf(" %c",&val);
        if (val =='y')
        {
           printf("donner la valeur");
           scanf("%f",&C);
           K = C +273.15;
           printf("la valeur en kelvin est %f",K);
        } else { 
            printf("donner la valeur");
            scanf("%f",&F);
            K = ((F-32.0)*5.0/9.0)+273.15;
            printf("la valeur est %f", K);
        }
        break;
    case 'f':
        printf("est ce que votre temperature est en Celsius tapez 'y' ou 'n'");    
        scanf(" %c",&val);
        if (val =='y')
        {
            printf("donner la valeur");
            scanf("%f",&C);
            F = (C*(9.0/5.0))+32.0;
            printf("la valeur est %f", F);
        } else {
            printf("donner la valeur");
            scanf("%f",&K);
            F = ((K-273.15)*9.0/5.0)+32.0;
            printf("la valeur est %f", F);
        }
        break;
    case 'c':
        printf("est ce que votre temperature est en fahrenheit tapez 'y' ou 'n'");
        scanf(" %c",&val);
        if (val =='y')
        {
           printf("donner la valeur");
           scanf("%f", &F);
           C = (F-32.0)*5.0/9.0;
           printf("la valeur est %f", C);
        } else {
            printf("donner la valeur");
            scanf("%f",&K);
            C = K - 273.15;
            printf("la valeur est %f", C);
        }
        break;   
    default:
        printf("saisie invalide");
        break;
    }
   } while (temp != 'k' && temp != 'c' && temp != 'f');
  return 0; 
}