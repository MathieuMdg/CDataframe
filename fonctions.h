#ifndef CDATAFRAME_H
#define CDATAFRAME_H
#include "CDataframe.h"

// Affiche le CDatafram en entier
void print_CData_chaine(CDATAFRAME* CData);

// Affiche les colonnes situées dans un interval donné
void print_CData_selected_column(CDATAFRAME* CData);

// Affiche les lignes situées dans un interval donné
void print_CData_selected_lines(CDATAFRAME* CData);

// Affiche le nombre de ligne contenu dans le CDataframe
void print_CData_number_lines(CDATAFRAME* CData);

// Affiche le nombre de colonne contenu dans le CDataframe
void print_CData_number_column(LNODE* CData);

// Créer un nouveau LNODE du CDataframe
LNODE * CData_create_column();

void save_into_csv(CDATAFRAME *cdf, char *file_name);


#endif //CDATAFRAME_CDATAFRAME_H
