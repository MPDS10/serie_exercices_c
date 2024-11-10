/**
 * auteur : mame penda dieng sow
 * code permanent : SOWM65600301
 * programme : mystery.c 
 */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

//cette methode permettra d'effacer les espaces du debut de la phrase
void effacerEspacedebut(char*);

//cette methode permettra d'effacer les espaces de la fin de la phrase
void effacerEspaceFin(char*);
  
//cette fonction appelle les deux fonctions qui permettront d'effacer les espaces de debut et de fin de la phrase
void effacerEspaceDebutEtFin(char*);


//methode main
int main(void) {
  
  char b[4096];
  
  while (fgets(b,sizeof(b),stdin)){
    effacerEspaceDebutEtFin(b);
    puts(b);
  }

  return 0;
}


/**
* cette methode permettra d'effacer les espaces du debut de la phrase
* @param *s chaine caractere
*/
void effacerEspaceDebut(char *s) {
  char *d = s;
   
  while (isspace(*s) && *s != '\0') {
        s++;
    }
   
  memmove(d, s, strlen(s) + 1);
}


/**
 * cette methode permettra d'effacer les espaces de la fin de la phrase
 * @param *s chaine caractere
 */
void effacerEspaceFin(char *s){
  char *t = s + strlen(s) - 1;
  
  while (t >= s && isspace(*t)) {
        t--;
    }
    
  t[1] = '\0';
}

/**
* cette fonction appelle les deux fonctions qui permettront d'effacer les espaces de debut et de fin de la phrase
* @paramv*s chaine de caractere
*/
void effacerEspaceDebutEtFin(char *s){
 effacerEspaceDebut(s);
  
 effacerEspaceFin(s);
}
