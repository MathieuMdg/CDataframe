// Commentaire : Fichier regroupant l'ensemble des fonctions de gestion des colonnes et les définitions des types utilisés pour les colonnes



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


COLUMN* create_column(ENUM_TYPE type, char* title);

int insert_value(COLUMN *col, void *value, ENUM_TYPE col_type);

void delete_column(COLUMN *col);

void print_col(COLUMN* col);

int occurence(COLUMN* colonne, int val);

int sup_x(COLUMN* colonne, int x);

int inf_x(COLUMN* colonne, int x);

void rename_columns_name(COLUMN* col);

void delete_line(COLUMN* col);

int print_Col_lines(COLUMN* col, int value1, int value2);

void menu();

void print_answer(char* string);

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

int search_value_in_column(COLUMN *col, void *val);

void erase_index(COLUMN *col);

int check_index(COLUMN *col);

void update_index(COLUMN *col);

void print_col_by_index(COLUMN *col);

void* type_choice(COLUMN* col);

void init_CData();

void full_CData();

#endif