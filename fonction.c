#include "fonction.h.c"
#define REALOC_SIZE 256
#include <string.h>
#include <stdio.h>



// Fonction qui prend un titre de colonne et renvoie un pointer sur la colonne.
COLUMN* create_column(char* title) {
    COLUMN colonne;
    COLUMN* ptr_colonne;
    colonne.CHAINE = title;
    colonne.TAILLE_PHYSIQUE = REALOC_SIZE;
    colonne.TAILLE_LOGIQUE = 0;
    colonne.DONNEES = NULL;
    ptr_colonne = &colonne;
    return ptr_colonne;
}

int insert_value(COLUMN* col, int value) {
    if (col->TAILLE_LOGIQUE == col->TAILLE_PHYSIQUE) {
        printf("Impossible");
        return 0;
    }
}