#ifndef FONCTIONS_H
#define FONCTIONS_H


// Definition du type structure
typedef struct {
    char* CHAINE;
    int TAILLE_LOGIQUE;
    int TAILLE_PHYSIQUE;
    int* DONNEES;
}COLUMN;

struct maillon
{
    int INDEX;
    struct mailllon *SUCC;
    COLUMN* COLUMN;
};
typedef struct maillon maillon;

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
void rename_columns_name(COLUMN* col);
int value_research(COLUMN* col, int value);
void print_lines(COLUMN** CData, int nbre_colonne);
void print_colonne(int nbre_colonne);
int equal_x(COLUMN** CData, int nbre_colonne);
int CData_sup_x(COLUMN** CData, int nbre_colonne);
int CData_inf_x(COLUMN** CData, int nbre_colonne);


void print_CData_chaine(maillon * CData);
void print_CData_selected_column(maillon* CData);
int print_Col_lines(COLUMN* col, int value1, int value2);
void print_CData_selected_lines(maillon* CData);
void menu();
void print_CData_number_lines(maillon* CData);
void print_CData_number_column(maillon* CData);

#endif