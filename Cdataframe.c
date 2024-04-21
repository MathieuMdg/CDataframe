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
    for (int i = 0; i < col->TAILLE_LOGIQUE; i++) {
        printf("[%d] %d\n", i, col->DONNEES[i]);
    }
}


void delete_column(COLUMN **col) {
    free((*col)->DONNEES);
    free(col);
}

int occurence(COLUMN* colonne, int val) {
    int occurence = 0;
    for (int i = 0; i < colonne->TAILLE_LOGIQUE; i++) {
        if (colonne->DONNEES[i] == val) {
            occurence++;
        }
    }
    return occurence;
}

int positionx(COLUMN* colonne, int position) {
    if (position < colonne->TAILLE_LOGIQUE) {
        return colonne->DONNEES[position];
    }
    else {
        return -1;
    }
}

int sup_x(COLUMN* colonne, int x) {
    int sup_x = 0;
    for (int i = 0; i < colonne->TAILLE_LOGIQUE; i++) {
        if (colonne->DONNEES[i] > x) {
            sup_x++;
        }
    }
    return sup_x;
}

int inf_x(COLUMN* colonne, int x) {
    int inf_x = 0;
    for (int i = 0; i < colonne->TAILLE_LOGIQUE; i++) {
        if (colonne->DONNEES[i] < x) {
            inf_x++;
        }
    }
    return inf_x;
}


// Affichage


void print_CData(COLUMN** CData,int nbre_colonne) {
    for(int i=0; i<nbre_colonne; i++) {
        printf("%s\n", CData[i]->CHAINE);
        print_col(CData[i]);
        printf("\n");
    }
}


// Opérations usuelles

void add_line(COLUMN** CData, int nbre_colonne) {
    int val, colonne;
    do {
        printf("Dans quelle colonne ajouter la valeur (indiqué le numéro) : ");
        scanf(" %d", &colonne);
        if (colonne > nbre_colonne - 1) {
            printf("Colonne inexistante.");
        }
    }
    while (colonne > nbre_colonne - 1);
    printf("valuer à ajouter : ");
    scanf(" %d", &val);
    if (insert_value(CData[colonne], val)) {
    }
    else {
        printf("Error adding value to my column\n");
    }
}

void rename_columns_name(COLUMN** CData, int nbre_colonne) {
    int colonne;
    do {
        printf("Choisir la colonne à renommer (numéro de colonne) : ");
        scanf(" %d", &colonne);
        if (colonne > nbre_colonne - 1) {
            printf("Colonne inexistante.");
        }
    }
    while (colonne > nbre_colonne - 1);
    char title[100] = "";
    char* ptr_title = malloc(strlen(title) + 1);
    printf("Nouveau nom de la colonne : ");
    scanf(" %s", title);
    strcpy(CData[colonne]->CHAINE, title);
}

void value_research(COLUMN** CData, int nbre_colonne, int value) {
    int presence = 0;
    for (int i = 0; i < nbre_colonne; i++) {
        for (int j = 0; j < CData[i]->TAILLE_LOGIQUE; j++) {
            if (CData[i]->DONNEES[j] == value) {
                printf("La valeur %d est presente a la colonne %d, ligne %d\n", value, i, j);
                presence = 1;
            }
        }
    }
    if (presence == 0) {
        printf("La valeur n'est pas presente dans le CDataframe.\n");
    }
}


// Analyse et statistiques

void print_lines(COLUMN** CData, int nbre_colonne) {
    for (int i = 0; i < nbre_colonne; i++) {
            printf("Le nombre de ligne de la colonne %d est %d\n", i, CData[i]->TAILLE_LOGIQUE);
        }
}

void print_colonne(int nbre_colonne) {
    printf("Le nombre de colonne est %d.\n", nbre_colonne);
}

int equal_x(COLUMN** CData, int nbre_colonne) {
    int nbre = 0, val;
    printf("valeur de x : ");
    scanf(" %d", &val);
    for (int i = 0; i < nbre_colonne; i++) {
        if (occurence(CData[i], val)) {
            nbre++;
        }
    }
    return nbre;
}

int CData_sup_x(COLUMN** CData, int nbre_colonne) {
    int nbre = 0, val;
    printf("valeur de x : ");
    scanf(" %d", &val);
    for (int i = 0; i < nbre_colonne; i++) {
        if (sup_x(CData[i], val)) {
            nbre++;
        }
    }
    return nbre;
}

int CData_inf_x(COLUMN** CData, int nbre_colonne) {
    int nbre = 0, val;
    printf("valeur de x : ");
    scanf(" %d", &val);
    for (int i = 0; i < nbre_colonne; i++) {
        if (inf_x(CData[i], val)) {
            nbre++;
        }
    }
    return nbre;
}



// Affichage (CDataframe chainé)


void print_CData_chaine(maillon * CData) {
    maillon* tmp ;
    if ( CData != NULL)
    {
        tmp = CData;
        while(tmp != NULL)
        {
            printf("%s\n", tmp->COLUMN->CHAINE);
            print_col(tmp->COLUMN);
            printf("\n");
            tmp = (maillon *) tmp->SUCC;
        }
    }
}

void print_CData_selected_column(maillon* CData,int value1,int value2) {
    maillon* tmp ;
    if (CData != NULL)
    {
        tmp = CData;
        while(tmp->INDEX != value2 + 1)
        {
            if(tmp->INDEX > value1 - 1) {
                printf("%s\n", tmp->COLUMN->CHAINE);
                print_col(tmp->COLUMN);
                printf("\n");
            }
            tmp = (maillon *) tmp->SUCC;
        }
    }
}

int print_Col_lines(COLUMN* col, int value1, int value2) {
    if(value2 < col->TAILLE_LOGIQUE) {
        for (int i = value1; i < value2; i++) {
            printf("[%d] %d\n", i, col->DONNEES[i]);
        }
        return 1;
    }
    else {
        return 0;
    }
}

void print_CData_selected_lines(maillon* CData,int value1,int value2) {
    maillon* tmp ;
    if ( CData != NULL)
    {
        tmp = CData;
        while(tmp != NULL)
        {
            printf("%s\n", tmp->COLUMN->CHAINE);
            print_Col_lines(tmp->COLUMN, value1, value2);
            printf("\n");
            tmp = (maillon *) tmp->SUCC;
        }
    }
}