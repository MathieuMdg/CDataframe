#ifndef FONCTIONS_H
#define FONCTIONS_H


// Definition du type structure
typedef struct {
    char* CHAINE;
    int TAILLE_LOGIQUE;
    int TAILLE_PHYSIQUE;
    int* DONNEES;
}COLUMN;



COLUMN* create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);


#endif