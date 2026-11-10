//rock paper scissors
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int computerchoice, userchoice;
    
    
    srand(time(0));

    do
    {
        
        computerchoice = (rand() % 3) + 1;

        printf("\n=== rock, paper, scissors ===\n"
               "1. rock\n"
               "2. paper\n"
               "3. scissors\n"
               "Enter your choice (1-3): ");
        scanf("%d", &userchoice);

        
        if (userchoice < 1 || userchoice > 3) {
            printf("Saisie invalide. Choisissez 1, 2 ou 3.\n");
            continue; 
        }

        
        printf("You chose %d, Computer chose %d\n", userchoice, computerchoice);

        // Compare choices using '==' and remove trailing semicolons!
        if (userchoice == computerchoice)
        {
            printf("Result: Tie!\n");
        } 
        else if ((userchoice == 1 && computerchoice == 3) || 
                 (userchoice == 2 && computerchoice == 1) || 
                 (userchoice == 3 && computerchoice == 2))
        {
            printf("Result: User wins!\n");
        } 
        else 
        {
            printf("Result: Computer wins!\n");
        }

       
    } while (userchoice >= 1 && userchoice <= 3);

    return 0;
}