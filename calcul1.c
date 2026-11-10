#include <stdio.h>
#include <stdlib.h>
int main() {
char choice;
float n1,n2,calcul;

do
{
        printf("=== calcul Basic ===\n"
           "1.addition\n"
           "2.soustraction\n"
           "3.multiplication\n"
           "4.division\n"
           "Entrer voutre choix (1-4): ");
    scanf(" %c", &choice);
    switch (choice)
    {
    case '1':
        printf("entrer 1ER nombre\n");
        scanf(" %f",&n1);
        printf("entrer 2eme nombre\n");
        scanf(" %f",&n2);
        calcul = n1 + n2;
        printf("la somme est %f", calcul);
        break;
    case '2':
        printf("entrer 1er nombre\n");
        scanf(" %f", &n1);
        printf("entrer 2eme nombre\n");
        scanf(" %f",&n2);
        calcul = n1-n2;
        printf("le resultat est %f", calcul);
        break;
    case '3':
        printf("entrer 1er nombre\n");
        scanf(" %f", &n1);
        printf("entrer 2eme nombre\n");
        scanf(" %f",&n2);
        calcul = n1 * n2;
        printf("le resultat est %f", calcul);
        break;
    case '4':
        printf("entrer 1er nombre\n");
        scanf(" %f", &n1);
        printf("entrer 2eme nombre\n");
        scanf(" %f",&n2);
        if (n2=0)
        {
            printf("error syntaxe\n");
            printf("saisir un nombre different de 0\n");
            scanf(" %f", &n2);
            calcul = n1 / n2;
            printf("le resulta est %f", calcul);
        } else {
            calcul = n1 / n2;
            printf(" %f",calcul);
        }
               
    default:
        printf("saisie invalide\n");
        break;
    }
} while (choice != '1' && choice != '2' && choice != '3' && choice != '4');
return 0;
}