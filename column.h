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
int occurence(COLUMN* colonne, int val);
int positionx(COLUMN* colonne, int position);
int sup_x(COLUMN* colonne, int x);
int inf_x(COLUMN* colonne, int x);
void print_CData(COLUMN** CData,int nbre_colonne);
void add_line(COLUMN** CData, int nbre_colonne);
void rename_columns_name(COLUMN** CData, int nbre_colonne);
void value_research(COLUMN** CData, int nbre_colonne, int value);
void print_lines(COLUMN** CData, int nbre_colonne);

#endif