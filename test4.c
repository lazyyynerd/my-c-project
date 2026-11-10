#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#ifdef _WIN32
#include <windows.h> // Pour Sleep() sur Windows
#else
#include <unistd.h>  // Pour sleep() sur Linux/macOS
#endif

void vider_ecran() {
    // Efface l'écran selon l'OS pour que l'horloge "rafraîchisse" sa position
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    printf("=== HORLOGE DIGITALE ===\n");
    printf("Appuyez sur Ctrl+C pour quitter.\n\n");

    while (1) {
        // 1. Récupérer l'heure système actuelle
        time_t temps_actuel;
        time(&temps_actuel);
        
        // Convertir en structure de temps locale (heures, minutes, secondes)
        struct tm *info_temps = localtime(&temps_actuel);

        // 2. Afficher l'heure au format HH:MM:SS
        // %02d force l'affichage sur 2 chiffres (ex: 09 au lieu de 9)
        vider_ecran();
        printf("=====================\n");
        printf("  %02d:%02d:%02d\n", 
               info_temps->tm_hour, 
               info_temps->tm_min, 
               info_temps->tm_sec);
        printf("=====================\n");

        // 3. Attendre 1 seconde avant la prochaine boucle
        #ifdef _WIN32
            Sleep(1000); // En millisecondes pour Windows
        #else
            sleep(1);    // En secondes pour Linux/macOS
        #endif
    }

    return 0;
}