/**
 * auteur : mame penda dieng sow
 * programme : hw.c 
 *
 */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_ORDRE 15
#define MAX_NB_MOTS 100

// Structure pour représenter la grille
struct Grille
{
    unsigned int ordre; // La taille de la grille (ordre x ordre)
    char lettres[MAX_ORDRE][MAX_ORDRE]; // Les lettres de la grille
    bool selectionnes[MAX_ORDRE][MAX_ORDRE]; // Indique quelles lettres sont sélectionnées
};

/**
 * Inverse une chaîne de caractères en supprimant les caractères vides.
 *
 * @param chaine La chaîne de caractères à inverser.
 */
void inverserChaine(char *chaine){
    if (chaine == NULL){
        return; // Vérification pour éviter les pointeurs nuls
    }

    int longueur = strlen(chaine);
    int debut = 0;
    int fin = longueur - 1;

    // Inverser la chaîne tout en supprimant les caractères vides
    while (debut < fin){
        while (debut < fin && isspace(chaine[debut])){
            debut++;
        }
        while (debut < fin && isspace(chaine[fin])){
            fin--;
        }
        if (debut < fin){
            char temp = chaine[debut];
            chaine[debut] = chaine[fin];
            chaine[fin] = temp;
            debut++;
            fin--;
        }
    }
}


/**
 * Lit la grille et les mots cachés à partir de l'entrée standard.
 *
 * @param grille La structure Grille pour stocker la grille.
 * @param motsCaches Un tableau pour stocker les mots cachés.
 * @param nombreMots Un pointeur vers un entier pour stocker le nombre de mots cachés.
 */
void lireGrilleEtMots(struct Grille *grille, char motsCaches[MAX_NB_MOTS][MAX_ORDRE], int *nombreMots){
    char tampon[MAX_ORDRE];
    grille->ordre = strlen(fgets(tampon, MAX_ORDRE, stdin)) - 1;

    unsigned int ligne = 0;
    while (grille->ordre > ligne){
        for (unsigned int colonne = 0; colonne < grille->ordre; colonne++){
            grille->lettres[ligne][colonne] = tampon[colonne];
            grille->selectionnes[ligne][colonne] = false;
        }
        fgets(tampon, MAX_ORDRE, stdin);
        ligne++;
    }

    do{
        strcpy(motsCaches[*nombreMots], tampon);
        (*nombreMots)++;

        strcpy(motsCaches[*nombreMots], tampon);
        inverserChaine(motsCaches[*nombreMots]);
        (*nombreMots)++;

    } while (fgets(tampon, MAX_ORDRE, stdin) != NULL);
}

/**
 * Vérifie si un mot est présent dans la grille.
 *
 * @param grille La structure Grille contenant la grille de lettres.
 * @param mot Le mot à rechercher dans la grille.
 * @return true si le mot est trouvé, false sinon.
 */
bool chercherMot(struct Grille *grille, char *mot){
    unsigned int longueurMot = strlen(mot) - 1;

    // Parcourir la grille
    for (unsigned int i = 0; i < grille->ordre; i++){
        for (unsigned int j = 0; j < grille->ordre; j++){
            if (grille->lettres[i][j] == mot[0]){
                // Essayer de trouver le mot dans toutes les directions

                // Horizontale droite
                if (j + longueurMot <= grille->ordre){
                    bool trouve = true;
                    for (unsigned int k = 0; k < longueurMot; k++){
                        if (grille->lettres[i][j + k] != mot[k]){
                            trouve = false;
                            break;
                        }
                    }
                    if (trouve){
                        // Marquer les lettres comme utilisées
                        for (unsigned int k = 0; k < longueurMot; k++){
                            grille->selectionnes[i][j + k] = true;
                        }
                        return true;
                    }
                }

                // Verticale bas
                if (i + longueurMot <= grille->ordre){
                    bool trouve = true;
                    for (unsigned int k = 0; k < longueurMot; k++){
                        if (grille->lettres[i + k][j] != mot[k]){
                            trouve = false;
                            break;
                        }
                    }
                    if (trouve){
                        // Marquer les lettres comme utilisées
                        for (unsigned int k = 0; k < longueurMot; k++){
                            grille->selectionnes[i + k][j] = true;
                        }
                        return true;
                    }
                }

                // Diagonale bas droite
                if (i + longueurMot <= grille->ordre && j + longueurMot <= grille->ordre){
                    bool trouve = true;
                    for (unsigned int k = 0; k < longueurMot; k++){
                        if (grille->lettres[i + k][j + k] != mot[k]){
                            trouve = false;
                            break;
                        }
                    }
                    if (trouve){
                        // Marquer les lettres comme utilisées
                        for (unsigned int k = 0; k < longueurMot; k++){
                            grille->selectionnes[i + k][j + k] = true;
                        }
                        return true;
                    }
                }
            }
        }
    }

    return false; // Le mot n'a pas été trouvé
}

/**
 * Affiche la grille de lettres.
 *
 * @param grille La structure Grille contenant la grille de lettres.
 */
void afficherGrille(struct Grille *grille){
    for (unsigned int i = 0; i < grille->ordre; i++){
        for (unsigned int j = 0; j < grille->ordre; j++){
            printf(" %c ", grille->lettres[i][j]);
            printf(" %d ", grille->selectionnes[i][j]);
        }
        printf("\n");
    }
}

/**
 * Résout la grille de mots cachés en recherchant chaque mot.
 *
 * @param grille La structure Grille contenant la grille de lettres.
 * @param motsCaches Un tableau de mots cachés à rechercher.
 * @param nombreMots Le nombre de mots cachés à rechercher.
 */
void resoudreGrille(struct Grille *grille, char motsCaches[MAX_NB_MOTS][MAX_ORDRE], int nombreMots){
    for (int i = 0; i < nombreMots; i++){
        chercherMot(grille, motsCaches[i]);
    }

    // Afficher les lettres restantes dans l'ordre
    for (unsigned int i = 0; i < grille->ordre; i++){
        for (unsigned int j = 0; j < grille->ordre; j++){
            if (!grille->selectionnes[i][j]){
                printf("%c", grille->lettres[i][j]);
            }
        }
    }
    printf("\n");
}

int main(void){
    struct Grille grille;
    char motsCaches[MAX_NB_MOTS][MAX_ORDRE];
    int nombreMots = 0;

    // Lire la grille et les mots cachés depuis l'entrée standard
    lireGrilleEtMots(&grille, motsCaches, &nombreMots);

    // Résoudre la grille de mots cachés
    resoudreGrille(&grille, motsCaches, nombreMots);
    

    return 0;
}
