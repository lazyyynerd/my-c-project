#include <stdio.h>
#include <windows.applicationmodel.activation.h>
int main()
{
   char x;
   do {
   printf("choisissez a b ou q");
   scanf("%c",&x);
   switch (x)
   {
   case 'a':
    printf("choix a");
    break;
   case 'b':
   printf("choix b");
   break;
   case 'q':
   printf("choix q");
   break;
   default:
    Beep(750,500);
    printf("saisie invalid");
   break;
   } 
  }while (x !='a' && x!= 'b' && x!= 'q' );
}