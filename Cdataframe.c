#include "column.h"
#define REALOC_SIZE 256
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



// Fonction qui prend un titre de colonne et renvoie un pointer sur la colonne.
COLUMN* create_column(char* title) {
    COLUMN* ptr_colonne = (COLUMN*)malloc(sizeof(COLUMN));
    ptr_colonne->CHAINE = title;
    ptr_colonne->TAILLE_LOGIQUE = 0;
    ptr_colonne->TAILLE_PHYSIQUE = REALOC_SIZE;
    ptr_colonne->DONNEES= NULL;
    return ptr_colonne;
}

int insert_value(COLUMN* colonne, int value) {
    if (colonne->DONNEES == NULL) {
        colonne->DONNEES = (int *) malloc(REALOC_SIZE * sizeof(int));
        colonne->TAILLE_PHYSIQUE = REALOC_SIZE;
    }
    if (colonne->TAILLE_LOGIQUE == colonne->TAILLE_PHYSIQUE) {
        colonne->TAILLE_PHYSIQUE += REALOC_SIZE;
        colonne->DONNEES = realloc(colonne->DONNEES, colonne->TAILLE_PHYSIQUE + REALOC_SIZE);
    }
    colonne->DONNEES[colonne->TAILLE_LOGIQUE] = value;
    colonne->TAILLE_LOGIQUE++;
    return 1;
}

void print_col(COLUMN* col) {
    for (int i; i < col->TAILLE_LOGIQUE; i++) {
        printf("\n[%d] %d", i, col->DONNEES[i]);
    }

}



void delete_column(COLUMN **col) {
    free((*col)->DONNEES);
    free(col);
}