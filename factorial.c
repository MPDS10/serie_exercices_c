/**
 * auteur : mame penda dieng sow
 * code permanent : SOWM65600301
 * programme : factorial.c 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Déclaration de la fonction de validation d'arguments
 void validerArguments(int);
 
//Déclaration de la fonction de calcul du factoriel
 unsigned long long calculFactoriel(unsigned int);

//methode main
 int main(int argc, char *argv[]) {
    
      //verification du nombre d'arguments
      validerArguments(argc);

      //cette partie verifie si le premier caractère de la chaine n'est pas un chiffre
       if (!isdigit(argv[1][0])) {
         fprintf(stderr, "error: The argument must be an integer between 0 and 20\n");
         return 1;
       }
     
      // Conversion de l'argument en entier 
       int  N = atoi(argv[1]);
         
       if (N < 0 || N > 20) {
            fprintf(stderr, "error: The argument must be an integer between 0 and 20\n");
            return 1;
        }

   // Vérification la limite de N si <0 et >20 
       if (N < 0 || N > 20) {
           fprintf(stderr, "error: The argument must be an integer between 0 and 20\n");
           return 1;        
       }

    // Calculez le factoriel de N
       unsigned long long  factoriel =  calculFactoriel(N);

    // Affichez le résultat
       printf("%llu\n", factoriel);

        return 0;

}
 
/**
 * methode qui verifie si le nombre d'argument est valide
 * @param argc le nombre d'arguments
*/
void validerArguments (int argc){
    if (argc != 2) {
        fprintf(stderr, "error: Exactly one argument must be provided\n");
	exit(1);
    }
}
/**
* methode qui va calculer le factoriel de l'argument entré
* @param nombre limite
*/ 
unsigned long long calculFactoriel(unsigned int nombre){
    unsigned long long  factoriel = 1;
   
    for (unsigned int i = 1; i <= nombre; i++) {
         factoriel *= i;
    }
    
    return factoriel;
}
