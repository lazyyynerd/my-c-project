#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.applicationmodel.activation.h>
int main()
{
   int num;
   int guess;
   printf("===GUESSING GAME===");
   srand(time(NULL));
   num== (rand()% 20) + 1;
   printf("guess a number from 1 to 20");
   scanf("%d", &guess);
   if (guess == num)
   {
        printf("you guessed right!");
   } 
     else {
            printf("you guessed wrong");
            Beep(750,500);
         }
   return(0);
}