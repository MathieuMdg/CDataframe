#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "CDataframe.h"

// Affiche le CDatafram en entier
void print_CData_chaine(LNODE * CData);

// Affiche les colonnes situées dans un interval donné
void print_CData_selected_column(LNODE* CData);

// Affiche les lignes situées dans un interval donné
void print_CData_selected_lines(LNODE* CData);

// Affiche le nombre de ligne contenu dans le CDataframe
void print_CData_number_lines(LNODE* CData);

// Affiche le nombre de colonne contenu dans le CDataframe
void print_CData_number_column(LNODE* CData);

// Créer un nouveau LNODE du CDataframe
LNODE * CData_create_column();


#endif //CDATAFRAME_CDATAFRAME_H
