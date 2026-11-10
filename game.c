#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.applicationmodel.activation.h>
int main() {
    int num;
    int tentative;
    int coups = 0;

    srand(time(NULL));

    
    // (10 - 0 + 1) = 11, so rand() % 11 gives a number from 0 to 10
    num = rand() % 11; 

    printf("=== GUESSING GAME2 ===\n");
    printf("Devinez le nombre entre 0 et 10 !\n\n");

    // Boucle de jeu : tourne tant que le joueur n'a pas trouvé
    do {
        printf("Votre proposition : ");
        scanf("%d", &tentative);
        coups++;

        if (tentative > num) {
            printf("C'est moins !\n");
            Beep(1000,500);
        } else if (tentative < num) {
            printf("C'est plus !\n");
            Beep(2000,500);
        } else {
            printf("Bravo ! Vous avez trouve le nombre mystere en %d coups !", coups);
            Beep(3000,500);
        }

    } while (tentative != num);

    return 0;
}