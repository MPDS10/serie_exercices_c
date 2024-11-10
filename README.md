# Travail pratique 1 : Introduction au langage C

Ce document décrit le travail pratique 1 du cours [INF3135 Construction et
maintenance de logiciels](https://etudier.uqam.ca/cours?sigle=INF3135) au
trimestre d'automne 2023. Le cours est enseigné par Alexandre Blondin Massé et
Gnagnely Serge Dogny, chargés de cours au [département
d'informatique](http://info.uqam.ca/), à l'[Université du Québec à
Montréal](https://uqam.ca/).

Le travail doit être remis au plus tard le **17 octobre à 23h59**. À partir de
minuit, une pénalité de **2 points** par heure de retard sera appliquée.

## Objectifs pédagogiques

Les principaux objectifs pédagogiques de ce travail sont les suivants:

- Vous initier au langage de **programmation C**;
- Consolider votre utilisation du logiciel de contrôle de versions **Git** lors
  d'un développement en **solitaire**;
- Vous familiariser à la compilation d'un programme à l'aide d'un **Makefile**;
- Vous habituer à décomposer un programme en **petites fonctions**;
- Vous familiariser avec le passage d'arguments par **adresse**;
- Vous familiariser avec l'utilisation de l'**entrée standard** (`stdin`) et de
  la **sortie standard** (`stdout`);
- Vous familiariser avec le traitement des **arguments** d'un programme et des
  **codes de retour**

## Description du travail

Vous devez répondre aux quatre questions contenues dans le fichier
[`questions.md`](./questions.md), en vous assurant de respecter tous les
critères d'évaluation. Vos solutions seront divisées en deux composantes:

* Vous devez fournir un programme C pour chaque question (`factorial.c`,
  `mystery.c`, `hw.c` et `motzkin.c`), qui peut être compilé à l'aide du
  [`Makefile`](./Makefile) présent dans le répertoire courant:
  ```sh
  $ make factorial
  $ make mystery
  $ make hw
  $ make motzkin
  ```
  Si le programme ne compile pas pour une question donnée, la note de 0 sera
  attribuée à cette question.
* Vous devez également expliquer chacune de vos quatre réponses, en modifiant
  le fichier [`solution.md`](./solution.md). Vous devez notamment y expliquer
  comment compiler et exécuter votre programme, préciser si votre programme a
  des limites ou est incomplet et fournir quelques exemples d'exécution. La
  qualité des réponses dans le fichier `solution.md` sera évaluée autant que
  les programmes C, il est donc important de soigner la rédaction et le format,
  ainsi que la qualité du français.

## Préparation et installation

Afin de compléter ce travail pratique, vous devez suivre les étapes suivantes:

1. Créez un clone (*fork*) du [dépôt du
   projet](https://gitlab.info.uqam.ca/inf3135-aut2023/inf3135-aut2023-tp1).
2. Assurez-vous que le dépôt soit privé, pour éviter le plagiat.
3. Donnez accès à votre dépôt aux utilisateurs `blondin_al` et `dogny_g` en
   mode `Developer`.
4. Familiarisez-vous avec le contenu du dépôt, en étudiant chacun des fichiers.
5. Commencez votre développement en versionnant fréquemment l'évolution de
   votre projet avec Git. La qualité de votre versionnement sera évaluée, il
   est donc important de bien décomposer votre travail en petites étapes,
   illustrées par des *commits* atomiques et ayant un message cohérent.
6. Complétez le fichier `solution.md` en respectant le format Markdown et en
   tenant compte des instructions données dans chaque question.
7. Complétez les programmes [`factorial.c`](./factorial.c),
   [`mystery.c`](./mystery.c), [`hw.c`](./hw.c) et [`motzkin.c`](./motzkin.c).

### Clone et création du dépôt

Vous devez cloner le dépôt fourni et l'héberger sur la plateforme [Gitlab du
département](https://gitlab.info.uqam.ca/). Votre dépôt devra se nommer
**exactement** `inf3135-aut2023-tp1` et l'URL devra être **exactement**
`https://gitlab.info.uqam.ca/utilisateur/inf3135-aut2023-tp1`, où
`utilisateur` doit être remplacé par votre code MS de l'UQAM ou par votre nom
d'utilisateur. Il devra être **privé** et accessible seulement par vous et par
les utilisateurs `blondin_al` et `dogny_g`.

Vous devez également installer les sous-modules Git permettant d'utiliser Bats.
Pour cela, il suffit d'entrer la commande

```sh
$ git submodule update --init
```

### Makefile

Un Makefile est disponible dans le répertoire courant pour faciliter la
compilation de chacun des 4 programmes. Vous pouvez le modifier si vous
souhaitez automatiser des tâches répétitives. En revanche, assurez-vous que la
commande suivante permette de produire les 4 exécutables:

```sh
$ make factorial mystery hw motzkin
```

### Fichier `solution.md`

Vous devez compléter le fichier `solution.md` livré dans le dépôt en suivant
les instructions. Assurez-vous de préciser les éléments suivants:

- Comment compiler le programme;
- Comment l'exécuter;
- Quels sont les formats d'entrées et de sorties;
- Quels sont les cas d'erreur gérés.
- Quelques exemples d'utilisation de votre programme.

Vous devez utiliser la syntaxe Markdown pour écrire une documentation claire et
lisible. Avant la remise, assurez-vous que le rendu de votre document sur
GitLab est celui auquel vous vous attendez.

Évitez d'abuser du gras, de l'italique et du HTML brut dans le fichier
`README.md`. Exploitez au maximum les listes à puces et formatez les noms de
fichier et le code à l'aide des apostrophes inversés. Finalement, soignez la
qualité de votre français, qui sera prise en considération dans le fichier
`README.md`.

### Git

Il est important de suivre l'évolution de votre projet à l'aide de Git. Vous
devez cloner (à l'aide du bouton *fork*) le sujet du travail pratique et
ajouter vos modifications à l'aide de *commits*. En particulier, il est
possible que nous apportions des corrections ultérieures à l'énoncé que vous
pourrez récupérer facilement si nous avons un historique **commun**.

Les messages de *commit* doivent suivre la convention de Chris Beams décrite
sur la page [How to write a Git commit
message](https://chris.beams.io/posts/git-commit/). Ils doivent donc avoir un
format très spécifique et refléter réellement les changements qui ont été
apportés.

Finalement, n'oubliez pas d'inclure un fichier `.gitignore` en fonction de
votre environnement de développement: il est important de ne pas versionner de
fichiers inutiles (les fichiers binaires, les fichiers de configuration de
votre IDE, etc.). Évitez les fichiers `.gitignore` génériques qu'on peut
trouver un peu partout sur Internet. Ne mettez que les motifs qui vous
dérangent dans votre développement.

## Pénalités

Attention! Les critères suivants doivent obligatoirement être respectés, à
défaut de quoi une pénalité pouvant aller **jusqu'à 50%** du travail sera
appliquée:

* Le nom de votre dépôt GitLab est exactement `inf3135-aut2023-tp1`
* L'URL de votre dépôt GitLab est exactement (remplacer `utilisateur` par votre
  nom identifiant GitLab)
  `https://gitlab.info.uqam.ca/utilisateur/inf3135-aut2023-tp1`
* Les utilisateurs `blondin_al` et `dogny_g` ont accès au projet en mode
  *Developer*
* Votre dépôt GitLab est un *fork* de [ce
  dépôt](https://gitlab.info.uqam.ca/inf3135-aut2023/inf3135-aut2023-tp1)
* Votre dépôt GitLab est privé

Un aide-mémoire est présent dans le fichier `solution.md` pour que vous
puissiez vérifier ces points avant la remise.

## Remise

La remise se fait automatiquement en ajoutant les utilisateurs `blondin_al` et
`dogny_g` en mode *Developer*, vous n'avez rien de plus à faire. À moins
d'indication contraire de votre part, ce sera le dernier (*commit*) disponible
sur votre branche `master` qui sera considéré pour la correction.
