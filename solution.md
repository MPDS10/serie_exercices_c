# Solution du travail pratique 1

## Identification
* nom : SOW
* prenom: MAME PENDA DIENG
* code permanent : SOWM65600301
 
## Vérifications et état du projet

Indiquez tous les éléments qui ont été complétés dans la liste ci-bas en
insérant un `X` entre les crochets. Si un élément n'a pas été complété,
expliquez pourquoi (supprimer ce paragraphe lors de la remise).

* [X] Le nom du dépôt GitLab est exactement `inf3135-aut2023-tp1`
* [X] L'URL du dépôt GitLab est exactement (remplacer `utilisateur` par votre
  nom identifiant GitLab) `https://gitlab.info.uqam.ca/utilisateur/inf3135-aut2023-tp1`
* [X] Les utilisateurs `blondin_al` et `dogny_g` ont accès au projet en mode
  *Developer*
* [X] Le dépôt GitLab est un *fork* de [ce
  dépôt](https://gitlab.info.uqam.ca/inf3135-aut2023/inf3135-aut2023-tp1)
* [X] Le dépôt GitLab est privé
* [X] Le dépôt contient au moins un fichier `.gitignore`.
* [X] Le fichier `Makefile` permet de compiler les solutions
* [X] Les sections incomplètes de ce fichier ont été complétées.

## Solution de la question 1
**Programme Factoriel en C** 
Le programme `factoriel.c` permet de calculer le factoriel d'un nombre entier tout en respectant certaines règles. 
### Compilation du Programme 
Pour compiler le programme,  on entre la commande suivante :
`gcc -o factorial -w -Wall factorial.c`

   ou
`make factorial`

une fois entrée , l'exécutable sera généré :
`gcc -o factorial factorial.c`



### Exécution du Programme 
Pour exécuter le programme, utilisez la commande suivante :

`./factorial <argument>`

### les formats d'entrée/sortie : 

- En entrée le programme n'accepte qu'un argument ce dernier doit être une entier entre 0 et 20

  si l'argument respecte les conditions alors 
 
- le programme affiche en sortie le factoriel de l'argument saisi qui lui aussi est un entier.
### les cas d'erreur gérés : 

-lorsque l'utilisateur entre plus d'un argument alors le message d'erreur: `"error: exactly one argument must be provided\n"` est affiché et retourne 1

-lorsque ce dernier saisi un nombre entier inferieur à 0 ou superieur à 20 alors le message d'erreur : `"error: the argument must be an integer between 0 and 20\n"` est affiché retourne 1

-si l'utilisateur entre un caractère special ou une chaine de caractère un message d'erreur similaire au précédent : `"error: the argument must be an integer between 0 and 20\n"` sera affiché retourne 1


### Quelques exemples d'utilisation:


- Pour calculer le factoriel de 2 :

`[entrée : ./factorial  2]  [sortie : 2]`

- Pour un argument invalide (par exemple, -1) :

`[entrée : ./factorial -1] [sortie : error: the argument must be an integer between 0 and 20 ]`


- Pour un argument non numérique (par exemple, '@') :

`[entrée : ./factorial @] [sortie : error: The argument must be an integer between 0 and 20]`

### NB:
les messages d'erreurs sont en anglais car je suivais les instructions du professeur


## Solution de la question 2
**Programme mystery en c**
le programme mystery.c supprime les espaces en surplus(debut et fin) d'une chaine de caractères

### Compilation du Programme 
Pour compiler le programme,  on entre la commande suivante :
`gcc -o mystery -w -Wall mystery.c`

   ou


`make mystery`

une fois entrée , l'exécutable sera généré :
`gcc -o mystery mystery.c`

### Exécution du Programme 
Pour exécuter le programme, utilisez la commande suivante :
`echo 'chaine de caractere' | ./mystery`

### les formats d'entrée/sortie : 
- En entrée, le programme n'accepte qu'une chaine de caractére precisement un tableau de 4096 caractères

Si la chaine de caractères respecte les conditions alors:

-le programme affiche en sortie la chaine de caractères sans les espaces intulies

###quelques exemples d'utilisation : 
- Pour une chaine de caractère sans espaces en surplus :

`[entrée : echo 'Espace' | ./mystery] [sortie :Espace]`
`[entrée : echo ' debutEspace' | ./mystery] [sortie :debutEspace]` 
`[entrée : echo 'EspaceFin ' | ./mystery] [sortie :EspaceFin]`

### NB:
les messages d'erreurs sont en anglais car je suivais les instructions du professeur

## Solution de la question 3

**Programme HW en C** 
Le programme `hw.c` permet de resoudre une grille de differents mot melangé afin de trouver le mot caché tout s'assurant que les obligations soient respectées. 

### Compilation du Programme 
Pour compiler le programme,  on entre la commande suivante :

`gcc -o hw -w -Wall hw.c`

   ou


`make hw`

une fois entrée , l'exécutable sera généré :
`gcc -o hw hw.c`

### Exécution du Programme 
Pour exécuter le programme, utilisez la commande suivante :

`./hw < repertoireOuSeTrouveLeFichier/leFichierALire.txt`
exemple : 
`./hw < examples/4x4hw.txt`

### les formats d'entrée/sortie : 

- En entrée le programme Lit un fichier contenant les mots melangés à partir de l'entrée standard

  si l'argument respecte les conditions alors 
 
- le programme affiche en sortie un mot caché .

### Quelques exemples d'utilisation:


- Pour trouver le mot dans  :

`[entrée : ./hw < examples/4x4hw.txt]  [sortie : LINUX]`

- Pour trouver le mot dans :

`[entrée : ./hw < examples/5x5hw.txt] [sortie : ZZZZ ]`

- Pour trouver le mot dans :

`[entrée : ./hw < examples/fruits-legumes.txt] [sortie : POMMEDETERRE ]`


- Pour trouver le mot dans:

`[entrée : ./hw < examples/musique.txt] [sortie : MANDOLINE]`


### NB:
les messages d'erreurs sont en anglais car je suivais les instructions du professeur


## Solution de la question 4

**Programme motzkin en C** 
Le programme `motzkin.c` permet de representer un graphique generé dans un fichier .SVG grâce à des direction spécifiques à respecter

### Compilation du Programme 
Pour compiler le programme,  on entre la commande suivante :
`gcc -o motzkin -w -Wall motzkin.c`

   ou


`make motzkin`

une fois entrée , l'exécutable sera généré :
`gcc -o motzkin motzkin.c`

### Exécution du Programme 
Pour exécuter le programme, utilisez la commande suivante :

`./motzkin <argumentValide>` ou `./motzkin <argumentValide \< nomDuFichierAGenerer>`

### les formats d'entrée/sortie : 

- En entrée le programme n'accepte qu'un argument ce dernier doit être un caractère et pas n'importe lequel , il doit être parmi ces caractères "U,u,R,r,D,d"

  si l'argument respecte les conditions alors 
 
- le programme genere un fichier .SVG contenant le graphique composé de directions inscrites précédemment 

### les cas d'erreur gérés : 

-lorsque l'utilisateur entre plus d'un argument alors le message d'erreur: `"error: exactly one argument must be provided\n"` est affiché et retourne 1

-lorsque ce dernier saisi un caractere dans l'argument different de ces caractères "U,u,R,r,D,d"  alors le message d'erreur : `"error: unrecognized step"` ainsi que le manuel seront affichés puis retourne 1

-si l'utilisateur entre un argument de plus de 40 directions alors le message d'erreur :  `"error: the path cannot be wider than 40"` ainsi que le manuel seront affichés puis retourne 1

-lorsque l'utilisateur met la direction u plusieurs fois de suite alors le message d'erreur : `"error: the path cannot end above the horizontal axis"` ainsi que le manuel seront affichés puis retourne 1

-lorsque l'utilisateur met la direction d plusieurs fois de suite alors le message d'erreur : `"error: the path cannot end above the horizontal axis"` ainsi que le manuel seront affichés puis retourne 1

### Quelques exemples d'utilisation:

- lorsque l'argument contient plus de 40 caractères
`[entrée : ./motzkin uuuuuuuuuuuuuurrrrrddddddddddddddddddddddd]  [sortie : "error: the path cannot be wider than 40 "]`

- lorsque l'on met la direction U,u plusieurs fois de suite 
`[entrée : ./motzkin uuuuud]  [sortie :  "error: the path cannot end above the horizontal axis" ]`

- lorsque l'on met la direction D,d plusieurs fois de suite 
`[entrée : ./motzkin udddd]  [sortie : "the path cannot go below the horizontal axis" ]`

- lorsque l'on rentre un argument different de U,u,R,r,D,d
`[entrée : ./motzkin e]  [sortie : "error: unrecognized step" ]`

- Pour un argument invalide (par exemple, espace vide) :
`[entrée : ./motzkin ] [sortie : "error: exactly one argument must be provided\n"]`

- Pour un argument valide respectant les conditions de representation:

`[entrée : ./motzkin urd ][sortie : un fichier motzkin.svg est generé avec le graphique]`
`[entrée : ./motzkin urd < urd.svg ][sortie : un fichier motzkin.svg est generé avec le graphique]`

### NB:
les messages d'erreurs sont en anglais car je suivais les instructions du professeur
je n'ai pas pu transformer le makefile comme je voulais (manque de temps)
