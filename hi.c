#include <stdio.h>
int main()
{
    int P,S;
    printf("bonjour");
    printf("donner le prix");
    scanf("%d",&P);
    S=P;
    while (P!=0)
    {
      printf("donner le prix");
      scanf("%d",&P);
      S=S+P;
    }
    printf("la somme est;%d" ,S);
    return(0);
}