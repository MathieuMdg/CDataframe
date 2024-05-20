# CDataframe

-Etudiants : Mathieu Mendouga, Théophile SALLES

-Lien vers le dépot Gith : https://github.com/MathieuMdg/CDataframe

-Idée de réalisation du projet : Le CDataframe est représenté comme un tableau dynamique ce qui permet de modifer et d'acceder à toutes les colonnes facilement. Il est ainsi possible d'acceder à toutes les colonnes et de les modifier avec des fonctions permettant par exemple de changer le nom, les valeurs, ...


  Le menu présente toutes les fonctionnalités demandées par le projet. Pour y accéder, il faut entrer dans la console le numéro ou la lettre correspondant à la fonctionnalité désirée. Nous avons décidé d'implémenter une liste doublement chaînée pour représenter le CDataframe. Les fonctions prévues pour la gestion de cette liste sont contenues dans le fichier liste.h (tous les prototypes se trouvent dans le fichier fonction.c). Il est possible de sauvegarder et d'importer des CDataframe à partir de fichier .csv. Pour cela il faut renseigner le chemin jusqu'au fichier Cdataframe. Il nous était possible de créer une liste de CDataframe afin de pouvoir en modifier plusieurs. Cependant, notre programme dispose de fonctionnalités de sauvegarde et d'import de fichiers .csv, il est donc possible de sauvegarder son CDataframe une fois terminé pour pouvoir le "charger" plus tard dans le programme. Nous avons travaillé sur des colonnes permettant de stocker tout type de donnée. Au sujet des fonctionnalités de comparaison (telles que x présent, nombre supérieur à x,...) nous avons décidé de rester sur des comparaisons d'entier pour ne pas trop s'éloigner du type basique des colonnes. 
