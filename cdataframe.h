// Commentaire : Fichier regroupant l'ensemble des définitions nécessaires pour la chaîne doublement chainée du CDataframe et les fonctions de gestion du CDataframe


#ifndef CDATAFRAME_CDATAFRAME_H
#define CDATAFRAME_CDATAFRAME_H
#include "column.h"


typedef struct LNODE {;
    int NUMBER_COLONNE;
    struct LNODE *SUCC;
    struct LNODE * PREC;
    COLUMN* COLUMN;
} LNODE;


typedef struct list_ {
    LNODE *head;
    LNODE *tail;
} LIST;
typedef LIST CDATAFRAME;



int get_cdataframe_cols_size(CDATAFRAME *cdf);

CDATAFRAME* load_from_csv(char *file_name, ENUM_TYPE *dftype, int size);

COLUMN* acces_column_by_name(CDATAFRAME* cdata, char* column_name);

int add_lines(CDATAFRAME* CData);

CDATAFRAME* fill_CDataframe(CDATAFRAME* Cdata);

int load_from_cqv_insert_value(COLUMN* col, char* str, ENUM_TYPE col_type);

CDATAFRAME* fill_CDataframe_auto(CDATAFRAME* Cdata);

void print_CData_chaine(CDATAFRAME* CData);

void print_CData_selected_column(CDATAFRAME* CData);

void print_CData_selected_lines(CDATAFRAME* CData);

void print_CData_number_lines(CDATAFRAME* CData);

void save_into_csv(CDATAFRAME *cdf, char *file_name);

#endif //CDATAFRAME_CDATAFRAME_H

