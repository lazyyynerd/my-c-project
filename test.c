//convertion code hexa,reel,ASCII
#include <stdio.h>
int main()
{
    int A;
    float R;
    char C;
   printf("===CONVERTION HEXA,REEL,ASCII===");
    //convertion de entier -->hexadecimal
    printf("entrer un nombre entier");
    scanf("%x", &A);
    printf("la valeur est ; %x", A);
    //convertion de reel-->entier
    printf("entrer un nombre reel");
    scanf("%f", &R);
    printf("la valeur est ; %d", (int)R);
    //convertion de char-->ASCII
    printf("entrer caractere");
    scanf("%c", &C);
    printf("la valeur est ; %d", C);
    return(0);
}