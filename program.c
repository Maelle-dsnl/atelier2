#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int scoreJoueur = 0;
    int scoreOrdi = 0;
    int manche = 1;
    int choixJoueur;
    int choixOrdi;

    // Initialisation du générateur aléatoire
    srand(time(NULL));

    printf("=== PIERRE FEUILLE CISEAUX LÉZARD SPOCK ===\n");
    printf("Règles :\n");
    printf("1 = Pierre, 2 = Feuille, 3 = Ciseaux, 4 = Lézard, 5 = Spock\n");
    printf("Arrêt : 2 points d'écart ou 7 manches max.\n\n");

    // Condition d'arrêt : 2 points d'écart OU manche > 7
    while (abs(scoreJoueur - scoreOrdi) < 2 && manche <= 7) {
        printf("--- Manche %d/7 ---\n", manche);

        // Saisie du joueur
        printf("Votre choix (1, 2, 3, 4 ou 5) : ");
        if (scanf("%d", &choixJoueur) != 1) {
            while (getchar() != '\n'); // Vider le tampon en cas d'erreur
            continue;
        }

        // Choix aléatoire de l'ordinateur entre 1 et 5
        choixOrdi = (rand() % 5) + 1;
        printf("L'ordinateur a choisi : %d\n", choixOrdi);

        // Détermination du gagnant
        if (choixJoueur == choixOrdi) {
            printf("Égalité !\n");
        } 
        // 10 combinaisons gagnantes pour le joueur :
        // 1 (Pierre) bat 3 (Ciseaux) et 4 (Lézard)
        // 2 (Feuille) bat 1 (Pierre) et 5 (Spock)
        // 3 (Ciseaux) bat 2 (Feuille) et 4 (Lézard)
        // 4 (Lézard) bat 2 (Feuille) et 5 (Spock)
        // 5 (Spock) bat 1 (Pierre) et 3 (Ciseaux)
        else if ((choixJoueur == 1 && (choixOrdi == 3 || choixOrdi == 4)) ||
                 (choixJoueur == 2 && (choixOrdi == 1 || choixOrdi == 5)) ||
                 (choixJoueur == 3 && (choixOrdi == 2 || choixOrdi == 4)) ||
                 (choixJoueur == 4 && (choixOrdi == 2 || choixOrdi == 5)) ||
                 (choixJoueur == 5 && (choixOrdi == 1 || choixOrdi == 3))) {
            printf("Vous gagnez cette manche !\n");
            scoreJoueur++;
        } else {
            printf("L'ordinateur gagne cette manche !\n");
            scoreOrdi++;
        }

        printf("Score actuel -> Vous: %d | Ordi: %d\n\n", scoreJoueur, scoreOrdi);
        manche++;
    }

    // Bilan de la partie
    printf("=== FIN DE LA PARTIE ===\n");
    printf("Score final -> Vous: %d | Ordi: %d\n", scoreJoueur, scoreOrdi);

    if (scoreJoueur > scoreOrdi) {
        printf("Bravo, vous avez gagné la partie !\n");
    } else if (scoreOrdi > scoreJoueur) {
        printf("L'ordinateur remporte la partie...\n");
    } else {
        printf("Match nul parfait !\n");
    }

    return 0;
}