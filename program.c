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

    printf("=== PIERRE FEUILLE CISEAUX (Étape 2) ===\n");
    printf("Règles : 1 = Pierre, 2 = Feuille, 3 = Ciseaux\n");
    printf("Arrêt : 2 points d'écart ou 7 manches maximum.\n\n");

    // Condition de l'étape 2 :
    // On continue TANT QUE l'écart est strictement inférieur à 2 ET la manche <= 7
    while (abs(scoreJoueur - scoreOrdi) < 2 && manche <= 7) {
        printf("--- Manche %d/7 ---\n", manche);

        // Saisie du joueur
        printf("Votre choix (1, 2 ou 3) : ");
        if (scanf("%d", &choixJoueur) != 1) {
            // Vider le tampon en cas de saisie invalide
            while (getchar() != '\n');
            continue;
        }

        // Choix aléatoire de l'ordinateur (1, 2 ou 3)
        choixOrdi = (rand() % 3) + 1;
        printf("L'ordinateur a choisi : %d\n", choixOrdi);

        // Détermination du gagnant de la manche
        if (choixJoueur == choixOrdi) {
            printf("Égalité !\n");
        } else if ((choixJoueur == 1 && choixOrdi == 3) ||
                   (choixJoueur == 2 && choixOrdi == 1) ||
                   (choixJoueur == 3 && choixOrdi == 2)) {
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