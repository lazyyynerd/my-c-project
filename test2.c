#include <stdio.h>

int main() {
    // Déclaration d'un tableau pour stocker les 5 notes
    float notes[5];
    float somme = 0;
    float moyenne = 0;
    int compteur_moyenne = 0;

    printf("=== GESTION DES NOTES ===\n\n");
    for (int i = 0; i < 5; i++) {
        printf("Entrez la note de l'etudiant %d : ", i + 1);
        scanf("%f", &notes[i]);
    }
    for (int i = 0; i < 5; i++) {
        somme = somme + notes[i];
    }

    // Calcul de la moyenne
    moyenne = somme / 5;
    printf("\nMoyenne de la classe : %.2f / 20\n", moyenne);

    // 3. Compter les étudiants qui ont la moyenne (>= 10)
    for (int i = 0; i < 5; i++) {
        if (notes[i] >=10) {
            compteur_moyenne++;
        }
    }

    printf("Nombre d'etudiants ayant la moyenne : %d / 5\n", compteur_moyenne);

    return 0;
}
