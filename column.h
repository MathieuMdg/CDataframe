#ifndef FONCTIONS_H
#define FONCTIONS_H


// Definition du type structure
typedef struct {
    char* CHAINE;
    int TAILLE_LOGIQUE;
    int TAILLE_PHYSIQUE;
    int* DONNEES;
}COLUMN;

// Création d'une colonne
COLUMN* create_column(char* title);

// Ajouter une valeur dans une colonne
int insert_value(COLUMN* col, int value);

// Supprimer l'espace mémoire occupé par une colonne
void delete_column(COLUMN *col);

// Afficher les valeurs contenues dans une colonne
void print_col(COLUMN* col);

// Determiner le nombre d'occurence d'une valeur dans une colonne
int occurence(COLUMN* colonne, int val);

// Retourner la valeur à une position donnée dans une colonne donnée
int positionx(COLUMN* colonne, int position);

// Indique le bombre de valeur supérieure à x
int sup_x(COLUMN* colonne, int x);

// Indique le nombre de valeur inférieure à x
int inf_x(COLUMN* colonne, int x);

// Change le nom d'une colone
void rename_columns_name(COLUMN* col);

// Determine si une valeur est présente dans une colonne
int value_research(COLUMN* col, int value);

// Supprime une ligne dans une colonne
void delete_line(COLUMN* col);

// Affiche les lignes d'une colonne situées dans un interval donné
int print_Col_lines(COLUMN* col, int value1, int value2);

// Affiche le menu
void menu();

#endif