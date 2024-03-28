#include "fonction.h.c"
#define REALOC_SIZE 256
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



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

int insert_value(COLUMN* colonne, int value) {
    if (colonne->DONNEES == NULL) {
        colonne->DONNEES = (int *) malloc(REALOC_SIZE * sizeof(int));
        printf("\nCreation\n");
        colonne->TAILLE_LOGIQUE = 1;
        printf("new_t_log : %d\n", colonne->TAILLE_LOGIQUE);
        colonne->TAILLE_PHYSIQUE = REALOC_SIZE;
        printf("new t physique : %d\n", colonne->TAILLE_PHYSIQUE);
        colonne->DONNEES[0] = value;

        return 0;
    }
    if ((colonne->DONNEES != NULL) && (colonne->TAILLE_LOGIQUE == colonne->TAILLE_PHYSIQUE)) {
        colonne->TAILLE_PHYSIQUE += REALOC_SIZE;
        colonne->DONNEES = realloc(colonne->DONNEES, colonne->TAILLE_PHYSIQUE + REALOC_SIZE);
    }
}