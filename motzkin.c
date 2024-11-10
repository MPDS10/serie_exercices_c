
/**
 * auteur : mame penda dieng sow
 * programme : motzkin.c 
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

//The usage string
#define USAGE "NOM\n\
    %s - DESSINER UN CHEMIN MOTZINK\n\
\n\
SYNOPSIS\n\
    %s PAS \n\
\n\
DESCRIPTION\n\
    Dessinez le chemin motzink descris par les pas \n\
    Les pas permis sont\n\
      R or r pour un (1,0) pas\n\
      U or u pour un (1,1) pas\n\
      D or d pour un  (1,-1) pas\n"


//definition de la longueur maximale de l'argument 
#define LARGEUR_MAX 40 
 
//Direction du motzink
enum Direction {
  // direction vers la droite (est)
  DROITE,
  // direction vers le haut (nord-est)
  HAUT,
  
  //direction vers le bas (sud-est)
  BAS
};


//Chemin Motzink
struct chemin_motzink {
  // longeur du chemin motzink
  unsigned int largeur;
  // Hauteur chemin motzink
   int hauteur;
  // Direction
  enum Direction directions[LARGEUR_MAX];
};

//la methode gererErreur permet d'envoyer un message d'erreur et le manuel lorsque les conditions ne sont pas respectes
void gererErreur(char *messageErreur);

//la methode limiterArguments indique au programme que l'utilisateur ne doit depasser le nombre d'arguments
void limiterArguments(int);

//la methode representerMotzink permettra de faire le grapgique de motzink grace aux directions
struct chemin_motzink representerMotzink(char *representation);

//methode qui va permettre de creer et de generer le fichier
void creerFichierMotzink(struct chemin_motzink *chemin);

//methode main
int main(int argc, char* argv[]) {
   limiterArguments(argc);
   
   char *pas = argv[1];
   struct chemin_motzink chemin = representerMotzink(pas);
   
   creerFichierMotzink(&chemin);
   
   return 0;
}


//methode qui gere les messages d'erreur 
void gererErreur(char *messageErreur){
 	
     fprintf(stderr, "error: %s\n" , messageErreur);
	
     fprintf(stderr, "MANUEL:\t %s \n", USAGE);

     exit(1);
}


//methode qui limite le nombre d'argument à 2
void limiterArguments(int argc){
 if(argc != 2){
    
   gererErreur("wrong number of arguments");

 }
}

//methode qui permet de representer motzink
struct chemin_motzink representerMotzink(char *representation){
        struct chemin_motzink chemin;
	chemin.largeur = 0;
	chemin.hauteur = 0;
	
//la boucle permettra de parcourir le tableau representation
	for(size_t i = 0; i < strlen(representation); i++){
	enum Direction directions;
	switch(representation[i]) {
                case 'r':
		case 'R':
		  directions = DROITE;
	        break;
	       

	        case 'u':
		case 'U':
		  directions = HAUT;
		break;

		case 'd':
		case 'D':
		 directions = BAS;
	        break;

		default:
		 gererErreur("unrecognized step ");
	}

	//on stocke et on met a jour la hauteur et la largeur
	chemin.directions[chemin.largeur]= directions;
	 
	chemin.largeur++;

	//on met à jour en fonction de l'etape
	if(directions == HAUT){
	  
          chemin.hauteur++;
	
	}else if(directions == BAS){
      
	   chemin.hauteur--;
	
	    if(chemin.hauteur < 0){
	  
	       gererErreur("the path cannot go below the horizontal axis");
	}
	    //on verifie la largeur maximale
	
	}if(chemin.largeur > LARGEUR_MAX){
	
	   gererErreur("the path cannot be wider than 40");
	} 

     }
	//on verifie la hauteur a la fin du chemin
	if(chemin.hauteur != 0){
	gererErreur("the path cannot end above the horizontal axis");
	}
  return chemin;
}


//methode qui cree et genere le fichier svg
void creerFichierMotzink(struct chemin_motzink *chemin){

   //ouverture ou creation du fichier motzink.svg et gestion des exceptions
   FILE *fichier = fopen("motzkin.svg","w");
   
   if(fichier == NULL){
      
      gererErreur("file can't be created");
     
   }   


//initialisation des coordonnées
  int x = 10;
 
  int y = chemin->largeur * 10;
 
 //creation de l'en tête du fichier, elle definit la largeur et la hauteur du fichier en fonction de la largeur du chemin
   fprintf(fichier, "<svg xmlns='http://www.w3.org/2000/svg' width='%d' height='%d'>\n", (chemin->largeur+1) * 20 , chemin->largeur * 20);
 
 //commencer le fichier SVG
   fprintf(fichier, "<path d='M %d %d" , x, y);

//generer les chemins en fonction des etaes
 for(unsigned int i = 0; i < chemin->largeur; i++){
 enum Direction pas = chemin->directions[i];
	switch (pas){
	case DROITE:
		x += 20;
		break;
	case HAUT:
		x += 20;
		y -= 20;
		break;
	case BAS:
	        x += 20;
		y += 20;
		break;	
     }
    fprintf(fichier, " %c %d %d", (i == 0) ? 'L' : 'l', x, y);
}

//on declare que la couleur de la ligne sera noir et que son epaisseur sera de 2 pixels

fprintf(fichier, "' stroke='black' stroke-width='2' fill='none'/>\n");


fprintf(fichier, "</svg>\n");


//fermeture du fichier
fclose(fichier);
}
