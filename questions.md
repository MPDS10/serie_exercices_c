# Questions

## Question 1: Fonction factorielle (15 points)

Proposez un programme C dont l'exécutable est nommé `factorial`, qui prend
comme unique argument un nombre entier `N`, où `0 <= N <= 20` et qui affiche
sur `stdout` la factorielle du nombre `N`. Le programme retourne alors `0` pour
indiquer qu'il s'est terminé correctement.

Dans le cas où le nombre d'arguments fourni n'est pas correct, ou dans le cas
où l'argument fourni n'est ni un nombre, ni un entier entre `0` et `20`, la
valeur `1` est retournée, puis un message d'erreur est affiché sur `stderr`
expliquant le problème.

Voici quelques exemples du comportement attendu en cas de succès:

```sh
$ ./factorial 0
1
$ ./factorial 1
1
$ ./factorial 20
2432902008176640000
$ echo $?
0
```

Et en cas d'erreur:

```sh
$ ./factorial; echo $?
error: exactly one argument must be provided
1
$ ./factorial ab; echo $?
error: the argument must be an integer between 0 and 20
1
$ ./factorial 21; echo $?
error: the argument must be an integer between 0 and 20
1
```

Les éléments suivants seront évalués dans cette question.

a) (9 points) Le programme compile sans avertissement. Il s'exécute selon les
contraintes décrites plus haut. L'affichage se fait sur le bon canal selon la
situation (utilisation correcte ou erronées). Les bons codes d'erreur sont
retournés.

b) (2 point) Le code source du programme est soigné et lisible. Il est bien
indenté, bien aéré, utilise des identifiants pertinents et est bien factorisé.
Les fonctions sont documentées à l'aide de *docstrings* décrivant les
paramètres d'entrée et les valeurs de retour.

c) (2 points) Les *commits* faits pour résoudre cette question sont atomiques,
avec des messages soignés et représentatifs des modifications apportées.

d) (2 points) La description du fonctionnement du programme dans `solution.md`
explique clairement comment compiler et exécuter le programme. Des exemples
d'exécution sont fournis à l'appui autant pour les utilisations correctes que
les utilisations erronées.

## Question 2: Code mystérieux (15 points)

Considérez le fichier [`mystery.c`](mystery.c), qui contient le code source
d'un programme écrit en C. Supposons qu'on le compile en un exécutable nommé
`mystery`.

1) Décrivez en une phrase ce que fait le programme `mystery`. Formulez votre
   réponse de façon précise.
2) Complétez le fichier [`mystery.bats`](mystery.bats) avec des tests qui
   illustrent le fonctionnement du programme. Assurez-vous de couvrir une bonne
   diversité de scénarios (nombre d'arguments passés au programme, entrée ou
   non dans chacune des boucles `while` du programme, cas limites).
   Assurez-vous que la réponse en 1) est cohérente avec vos tests.
3) Réécrivez (factorisez) le programme afin qu'il soit plus facile à
   comprendre, en renommant les fonctions et les variables utilisées, en
   divisant la fonction `mystery` en plusieurs petites fonctions, en ajoutant
   des *docstrings* qui expliquent les paramètres des fonctions, etc.
   Assurez-vous que les tests réussissent encore, quitte à en ajouter au
   besoin. Attention! le comportement du programme doit demeurer exactement le
   même qu'avant la réécriture du code.

Les éléments suivants seront évalués dans cette question.

a) (3 points) La description du comportement du programme est correcte, précise
et complète.

b) (5 points) Les tests proposés couvrent les principaux scénarios
d'utilisation, autant correcte que erronée. Il y a peu de redondance entre les
différents tests. Leur présentation est soignée.

c) (5 points) La réécriture du programme respecte le comportement original. En
particulier, il compile toujours sans erreur et sans avertissement. De plus, il
est mieux structuré: avec une meilleure décomposition de la fonction
principale, avec des identifiants mieux nommés. Le style du code est plus
propre.

d) (2 points) Les *commits* faits pour résoudre cette question sont atomiques,
avec des messages soignés et représentatifs des modifications apportées.

## Question 3: Résolution d'un mot caché (30 points)

Complétez le programme `hw.c` qui permet de résoudre un mot caché. Plus
spécifiquement, votre programme doit lire sur `stdin` la grille de lettres,
suivie de la liste des mots cachés et écrire sur `stdout` la solution de la
grille de mots cachés. Par exemple, supposons qu'on prenne le fichier
[`4x4hw.txt`](4x4hw.txt) disponible dans le dépôt. Alors on s'attend au
comportement suivant:

```sh
$ cat 4x4hw.txt
NUIT
LOIL
INUX
SREV
VERS
NUIT
LOI
$ cat 4x4hw.txt | ./hw
LINUX
```

Ci-haut, les 4 premières lignes

```
NUIT
LOIL
INUX
SREV
```

représentent la grille 4 x 4 qui doit être solutionnée, puis les 3 lignes
suivantes

```
VERS
NUIT
LOI
```

la liste des mots cachés dans la grille. Le programme doit donc retrouver ces
mots, puis afficher dans l'ordre (ligne par ligne, de gauche à droite) les
lettres restantes, qui forment le mot caché `LINUX`.

Vous pouvez consulter les règles habituelles des mots cachés sur
[Wikipedia](https://fr.wikipedia.org/wiki/Mots_cach%C3%A9s). Par contre,
afin de simplifier un peu votre travail, vous pouvez faire les suppositions
suivantes:

* Les grilles sont toujours carrées;
* Elles ont entre 1 et 12 lignes/colonnes;
* Chaque mot caché apparaît exactement une fois dans la grille;
* Chaque mot caché peut apparaître à l'horizontale, à la verticale ou en
  diagonal, écrit à l'endroit ou à l'envers;
* Les mots cachés ne sont jamais superposés dans la grille. Autrement dit, vous
  pouvez prendre pour acquis qu'on ne biffera jamais deux fois la même lettre
  (contrairement aux règles des mots croisés qui permettent d'utiliser
  plusieurs fois la même lettre).
* La grille fournie sur `stdin` a toujours un format valide: elle est carrée et
  ne contient que des lettres majuscules entre `A` et `Z`. Autrement dit, vous
  n'avez pas à valider si la grille est bel et bien carrée, ni si elle comprend
  des caractères interdits.
* La liste des mots cachés fournie sur `stdin` contient toujours des mots ayant
  un format valide (seulement des lettres majuscules entre `A` et `Z`), chaque
  mot de la liste étant séparé par le caractère `\n`. Autrement dit, vous
  n'avez pas à valider la liste de mots, vous pouvez supposer qu'elle est
  toujours correcte.

Les éléments suivants seront évalués dans cette question.

a) (3 points) La documentation du fonctionnement du programme (comment le
compiler, comment l'exécuter, avec des exemples d'utilisation) est claire et
complète.

b) (15 points) Le programme compile sans erreur et sans avertissement. Il a le
comportement attendu sur des grilles carrées d'ordre entre 1 et 12.

c) (8 points) Le style du programme est soigné. Le code est bien indenté et
bien aéré, les identifiants sont bien choisis. La solution est bien divisée en
petites fonctions, qui effectuent un traitement spécifique. Toutes les
fonctions sont documentées avec une *docstring* expliquant les paramètres et
les valeurs de retour. Le code contient peu ou pas de valeurs magiques.

d) (4 points) Les *commits* faits pour résoudre cette question sont atomiques,
avec des messages soignés et représentatifs des modifications apportées.

**Suggestion**. Bien que ce ne soit pas obligatoire, une solution possible
repose sur les déclarations suivantes, que vous pouvez utiliser et modifier
à votre guise:

```c
// The maximum order of the grid
#define MAX_ORDER 12

// A grid
struct Grid {
  // The order of the grid
  unsigned int order;
  // The letters in the grid
  char letters[MAX_ORDER][MAX_ORDER];
  // Has the letter been picked?
  bool picked[MAX_ORDER][MAX_ORDER];
};
```

## Question 4: Dessiner des chemins de Motzkin en SVG (40 points)

En combinatoire, un *chemin de Motzkin* est un chemin de longueur `n` qu'on
peut tracer sur une grille et qui respecte les contraintes suivantes:

* Seulement 3 déplacements sont permis: en direction *nord-est* `(1,1)`, en
  direction *est* `(1,0)` et en direction *sud-est* `(1,-1)`;
* Le chemin doit commencer au point `(0,0)`;
* Le chemin doit terminer au point `(n,0)`;
* Le chemin ne peut jamais passer sous le segment qui relie les points `(0,0)`
  et `(n,0)`.

Par exemple, l'ensemble de tous les chemins de Motzkin de longueur `4` est
illustré ci-bas (tiré de la [page de Wikipedia sur les nombres de
Motzkin](https://en.wikipedia.org/wiki/Motzkin_number)):

![Les 9 chemins de Motzkin de longueur
4](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b7/Motzkin4.svg/1280px-Motzkin4.svg.png)

Dans cette question, vous devez écrire un programme nommé `motzkin` qui prend
en argument un mot de Motzkin et qui génère une image SVG du chemin de Motzkin
correspondant. Plus spécifiquement, votre programme sera invoqué à l'aide de la
syntaxe

```sh
$ ./motzkin LETTRES
```

où `LETTRES` est une suite de lettres choisies parmi l'ensemble `{u,d,r}` et
devra produire sur `stdout` un fichier SVG représentant le mot de Motzkin dont
les déplacements sont interprétés comme suit:

* `u` (*up*): déplacement en direction *nord-est*;
* `d` (*down*): déplacement en direction *sud-est*;
* `r` (*right*): déplacement en direction *est*.

Par exemple, votre programme devrait produire un fichier similaire à
[`urudd.svg`](./urudd.svg) si vous entrez la commande suivante:

```sh
$ ./motzkin urudd > urudd.svg
```

![Le chemin de Motzkin `urudd`](./urudd.svg)

Un deuxième exemple:

```sh
$ ./motzkin uuuuddddrr > uuuuddddrr.svg
```

permet de produire l'image [`uuuuddddrr.svg`](./uuuuddddrr.svg).

Par ailleurs, contrairement à la question 3, vous devez valider les cas erronés
dans ce programme. Plus spécifiquement, les cas d'erreur suivants doivent être
considérés:

* Si le programme n'a pas d'argument fourni, le programme doit afficher sur
  `stderr` le message `"error: wrong number of arguments"`, afficher le manuel
  d'utilisation et arrêter son exécution;
* Si le mot passé utilise une lettre invalide telle que `a` (différente de `u`,
  `d` et `r`), alors le programme doit afficher sur `stderr` le message "error:
  unrecognized step a", afficher le manuel d'utilisation et arrêter son
  exécution;
* Si le mot de Motzkin est invalide (parce qu'il passe sous le segment `(0,0) -
  (n,0)` ou parce qu'il ne termine pas en `(n,0)`), un message d'erreur en
  conséquence (`"error: the path cannot go below the horizontal axis"`,
  `"error: the path cannot end above the horizontal axis"`) doit être affiché,
  suivi du manuel d'utilisation, puis le programme doit arrêter son exécution.
* Finalement, si le chemin est trop long (largeur qui dépasse 40), il faut
  également arrêter l'exécution du programme en affichant l'erreur (`"error:
  the path cannot be wider than 40"`) et le manuel d'utilisation.

Vous pouvez utiliser le manuel d'utilisation suivant ou en écrire un plus
complet si vous le souhaitez:

```
NAME
    ./motzkin - draw a Motzkin path

SYNOPSIS
    ./motzkin STEPS

DESCRIPTION
    Draws the Motzkin path described by STEPS
    The allowed steps are
      r or R for a (1,0) step
      u or U for a (1,1) step
      d or D for a (1,-1) step
```

Les éléments suivants seront évalués dans cette question.

a) (5 points) La documentation du fonctionnement du programme (comment le
compiler, comment l'exécuter, avec des exemples d'utilisation) est claire et
complète.

b) (20 points) Le programme compile sans erreur et sans avertissement. Il a le
comportement attendu autant dans les cas d'utilisation correcte que lorsqu'il y
a des erreurs.

c) (10 points) Le style du programme est soigné. Le code est bien indenté et
bien aéré, les identifiants sont bien choisis. La solution est bien divisée en
petites fonctions, qui effectuent un traitement spécifique. Toutes les
fonctions sont documentées avec une *docstring* expliquant les paramètres et
les valeurs de retour. Le code contient peu ou pas de valeurs magiques.

d) (5 points) Les *commits* faits pour résoudre cette question sont atomiques,
avec des messages soignés et représentatifs des modifications apportées.

**Suggestion**. Bien que ce ne soit pas obligatoire, une solution possible
repose sur les déclarations suivantes, que vous pouvez utiliser et modifier
à votre guise:

```c
// The usage string
#define USAGE "NAME\n\
    %s - draw a Motzkin path\n\
\n\
SYNOPSIS\n\
    %s STEPS\n\
\n\
DESCRIPTION\n\
    Draws the Motzkin path described by STEPS\n\
    The allowed steps are\n\
      r or R for a (1,0) step\n\
      u or U for a (1,1) step\n\
      d or D for a (1,-1) step\n"

// A Motzkin step
enum step {
  // Moving right (east)
  RIGHT,
  // Moving up (north-east)
  UP,
  // Moving down (south-east)
  DOWN
};

// A Motzkin path
struct motzkin_path {
  // The width of the Motzkin path
  unsigned int width;
  // The height of the Motzkin path
  unsigned int height;
  // The steps
  enum step steps[MAX_WIDTH];
};
```
