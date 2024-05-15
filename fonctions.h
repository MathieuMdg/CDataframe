#ifndef CDATAFRAME_H
#define CDATAFRAME_H

struct maillon
{
    int NUMBER_COLONNE;
    struct mailllon *SUCC;
    COLUMN* COLUMN;
};


typedef struct maillon maillon;

// Affiche le CDatafram en entier
void print_CData_chaine(maillon * CData);

// Affiche les colonnes situées dans un interval donné
void print_CData_selected_column(maillon* CData);

// Affiche les lignes situées dans un interval donné
void print_CData_selected_lines(maillon* CData);

// Affiche le nombre de ligne contenu dans le CDataframe
void print_CData_number_lines(maillon* CData);

// Affiche le nombre de colonne contenu dans le CDataframe
void print_CData_number_column(maillon* CData);


#endif //CDATAFRAME_CDATAFRAME_H
