#ifndef FONCTIONS_H
#define FONCTIONS_H


enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;


union column_type{
    unsigned int UINT_VALUE;
    signed int INT_VALUE;
    char CHAR_VALUE;
    float FLOAT_VALUE;
    double DOUBLE_VALUE;
    char* STRING_VALUE;
    void* STRUCT_VALUE;
};
typedef union COLUMN_TYPE COL_TYPE ;


// Définition du type COLUMN
struct column {
    char* CHAINE;
    unsigned int TAILLE_LOGIQUE;
    unsigned int TAILLE_PHYSIQUE;
    ENUM_TYPE COLUMN_TYPE;
    COL_TYPE ** DONNEES;
    unsigned long long int * INDEX;

    int VALID_INDEX;
    // index valid
    // 0 : no index
    // -1 invalid index
    // 1 : valid index

    int SORT_DIR;
    // direction de tri Ascendant ou descendant
    // 0 : ASC
    // 1 : DESC
};
typedef struct column COLUMN;







// Création d'une colonne
COLUMN* create_column(ENUM_TYPE type, char* title);

// Ajouter une valeur dans une colonne
int insert_value(COLUMN *col, void *value);

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

// Affichage des réponses
void print_answer(char* string);

// Convertir une valeur en chaine de caractère
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

// Créer un tableau d'index pour trier les valeurs dans un ordre donnée
void sort(COLUMN* col, int sort_dir);

int partition(COL_TYPE * arr[], unsigned long long int index[], int low, unsigned int high);

void insertion(COL_TYPE * arr[], unsigned long long int index[], unsigned int n);

void echanger(int *a, int *b);

void print_col_by_index(COLUMN *col);

void sort_index(COLUMN* col, int sort_dir);




// Affiche un message d'erreur
void init_CData();

#endif