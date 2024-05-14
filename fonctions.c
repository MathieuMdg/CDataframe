#include "column.h"
#include "fonctions.h"
#define REALOC_SIZE 256
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define ASC 0
#define DESC 1



// Affiche le menu du programme
void menu() {
    for(int i = 0; i<6; i++)
        printf("\n");
    printf("1. Alimentation\n\n- Creation du CDataframe vide\n- Remplissage du CDataframe a partir de saisies utilisateurs\n- Remplissage en dur du CDataframe\n\n2. Affichage\n\n- Afficher tout le CDataframe\n- Afficher une partie des lignes du CDataframe selon une limite fournie par l utilisateur\n- Afficher une partie des colonnes du CDataframe selon une limite fournie par l utilisateur\n\n3. Operations usuelles\n\n- Ajouter une ligne de valeurs au CDataframe\n- Supprimer une ligne de valeurs du CDataframe\n- Ajouter une colonne au CDataframe\n- Supprimer une colonne du CDataframe\n- Renommer le titre d une colonne du CDataframe\n- Verifier l existence d une valeur (recherche) dans le CDataframe\n- Acceder/remplacer la valeur se trouvant dans une cellule du CDataframe en utilisant son\nnumero de ligne et de colonne\n- Afficher les noms des colonnes\n\n4. Analyse et statistiques\n\n- Afficher le nombre de lignes\n- Afficher le nombre de colonnes\n- Nombre de cellules contenant une valeur egale a x (x donne en parametre)\n- Nombre de cellules contenant une valeur superieure a x (x donne en parametre)\n- Nombre de cellules contenant une valeur inferieure a x(x donne en parametre)\n");
    for(int i = 0; i<3; i++)
        printf("\n");
}


void print_answer(char* string) {
    printf("\n\n\n");
    for(int i = 0; i < strlen(string) + 6; i++) {
        printf("=");
    }
    printf("\n|| %s ||\n", string);
    for(int i = 0; i < strlen(string) + 6; i++) {
        printf("=");
    }
    printf("\n\n\n");
}



// Fonction qui prend un titre de colonne et renvoie un pointer sur la colonne.
COLUMN* create_column(ENUM_TYPE type, char* title) {
    COLUMN* ptr_colonne = (COLUMN*)malloc(sizeof(COLUMN));
    ptr_colonne->CHAINE = title;
    ptr_colonne->TAILLE_LOGIQUE = 0;
    ptr_colonne->COLUMN_TYPE = type;
    ptr_colonne->TAILLE_PHYSIQUE = REALOC_SIZE;
    ptr_colonne->DONNEES= NULL;
    ptr_colonne->VALID_INDEX = 0;
    ptr_colonne->INDEX = NULL;
    return ptr_colonne;
}


// Permet d'ajouter une valeur à la fin d'une colonne et de l'agrandir si besoin
int insert_value(COLUMN* col, void* value) {

    // Si la colonne est vide
    if (col == NULL) {
        printf("COLONNE NON INITIALISEE\n");
        return 0;
    }

    // Allouer de la mémoire pour le tableau de pointeurs si ce n'est pas déjà fait
    if (col->DONNEES == NULL) {
        col->DONNEES = (COL_TYPE**) malloc(sizeof(COL_TYPE*));
        if (col->DONNEES == NULL) {
            printf( "ERREUR ALLOCATION\n");
            return 0;
        }
    }

    // Allocation de l'espace pour la valeur
    col->DONNEES[col->TAILLE_LOGIQUE] = (COL_TYPE*) malloc(sizeof(COL_TYPE*));
    if (col->DONNEES[col->TAILLE_LOGIQUE] == NULL) {
        printf( "ERREUR ALLOCATION\n");
        return 0;
    }
    if (value == NULL){
        col->DONNEES[col->TAILLE_LOGIQUE] = NULL;
    }
    else {
        // Affecter la valeur en fonction du type de colonne
        switch (col->COLUMN_TYPE) {
            case CHAR:
                col->DONNEES[col->TAILLE_LOGIQUE] = (char *) malloc(sizeof(char));
                *((char *) col->DONNEES[col->TAILLE_LOGIQUE]) = *((char *) value);
                break;
            case INT:
                col->DONNEES[col->TAILLE_LOGIQUE] = (int *) malloc(sizeof(int));
                *((int *) col->DONNEES[col->TAILLE_LOGIQUE]) = *((int *) value);
                break;
            case UINT:
                col->DONNEES[col->TAILLE_LOGIQUE] = (unsigned int *) malloc(sizeof(unsigned int));
                *((unsigned int *) col->DONNEES[col->TAILLE_LOGIQUE]) = *((unsigned int *) value);
                break;
            case FLOAT:
                col->DONNEES[col->TAILLE_LOGIQUE] = (float *) malloc(sizeof(float));
                *((float *) col->DONNEES[col->TAILLE_LOGIQUE]) = *((float *) value);
                break;
            case DOUBLE:
                col->DONNEES[col->TAILLE_LOGIQUE] = (double *) malloc(sizeof(double));
                *((double *) col->DONNEES[col->TAILLE_LOGIQUE]) = *((double *) value);
                break;
            case STRING:
                col->DONNEES[col->TAILLE_LOGIQUE] = (char **) malloc(sizeof(char*));
                *((char **) col->DONNEES[col->TAILLE_LOGIQUE]) = *((char **) value);
                break;
            case NULLVAL:
                col->DONNEES[col->TAILLE_LOGIQUE] = NULL;
                break;
            case STRUCTURE:
                //col->DONNEES[col->TAILLE_LOGIQUE] = (double *) malloc(sizeof(double ));
                //*((double *) col->DONNEES[col->TAILLE_LOGIQUE]) = *((double *) value);
                break;

                // Ajoutez d'autres cas pour les autres types ici
            default:
                printf("TYPE DE COLONNE ERRONE\n");
                break;
        }
    }

    col->TAILLE_LOGIQUE++;
    return 1;
}

// Fonction d'échange pour échanger deux éléments dans un tableau
void echanger(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Fonction de partitionnement pour l'algorithme Quicksort
int partition(COL_TYPE * tab[], int gauche, unsigned int droite) {
    int pivot = *((int*) tab[droite]); // Choix du pivot comme dernier élément
    int i = gauche - 1;

    for (int j = gauche; j < droite; j++) {
        if (*((int*) tab[j]) <= pivot) {
            i++;
            echanger((int*) tab[i], (int*) tab[j]);
        }
    }

    echanger((int*) tab[i + 1], (int*) tab[droite]);
    return i + 1;
}


// Fonction Quicksort pour trier un tableau
void quicksort(COL_TYPE * tab[], int gauche, unsigned int droite) {
    if (gauche < droite) {
        int pi = partition(tab, gauche, droite);
        quicksort(tab, gauche, pi - 1);
        quicksort(tab, pi + 1, droite);
    }
}

// Fonction tri_insertion
void tri_insertion(COL_TYPE * tab[], unsigned int N) {
    for (int i = 1; i < N; i++) {
        int k = *((int*) tab[i]); // Élément à insérer dans la partie triée
        int j = i - 1;

        // Déplacer les éléments plus grands que k vers la droite
        while (j >= 0 && *((int*) tab[j]) > k) {
            *((int*) tab[j + 1]) = *((int*) tab[j]);
            j--;
        }

        // Insérer k à la bonne position dans la partie triée
        *((int*) tab[j + 1]) = k;
    }
}

// Fonction de tri générale en fonction du type de tri pour un tableau d'index
void sort(COLUMN* col, int sort_dir) {
    if (col->VALID_INDEX == 0) {

        // Tri non trié : Utiliser Quicksort pour le tableau d'index
        quicksort( col->DONNEES, 0, col->TAILLE_LOGIQUE - 1);
    } else if (col->VALID_INDEX == -1) {
        // Tri partiellement trié : Utiliser Insertion Sort pour le tableau d'index
        tri_insertion( col->DONNEES, col->TAILLE_LOGIQUE);
    }

    // Si le tri est DESC, inverser le tableau d'index trié
    if (sort_dir == 1) {
        int i = 0;
        unsigned int j = col->TAILLE_LOGIQUE - 1;
        while (i < j) {
            unsigned int temp = col->INDEX[i];
            col->INDEX[i] = col->INDEX[j];
            col->INDEX[j] = temp;
            i++;
            j--;
        }
    }
}


void print_col_by_index(COLUMN *col) {
    for (int i = 0; i < col->TAILLE_LOGIQUE; i++) {
        if (col->DONNEES[col->INDEX[i]] == NULL) {
            printf("[%d] NULL\n", i);
        }
        else {
            char str[100];
            convert_value(col, col->INDEX[i], str, 100);
            printf("[%d] %s\n", i, str);
        }
    }
}

// Affiche une colonne en entier
void print_col(COLUMN* col) {
    for (int i = 0; i < col->TAILLE_LOGIQUE; i++) {
        if (col->DONNEES[i] == NULL) {
            printf("[%d] NULL\n", i);
        }
        else {
            char str[100];
            convert_value(col, i, str, 100);
            printf("[%d] %s\n", i, str);
        }
    }
}


// Supprime l'espace mémoire occupé par une colonne
void delete_column(COLUMN* col) {
    for (int i = 0; i<col->TAILLE_LOGIQUE; i++) {
        free(col->DONNEES[i]);
    }
    free(col->DONNEES);
    free(col);
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size) {

    switch (col->COLUMN_TYPE){

        case INT:
            snprintf(str, size, "%d", *((int *) col->DONNEES[i]));
            break;

        case UINT:
            snprintf(str, size, "%u", *((unsigned int *) col->DONNEES[i]));
            break;

        case FLOAT:
            snprintf(str, size, "%f", *((float *) col->DONNEES[i]));
            break;

        case DOUBLE:
            snprintf(str, size, "%f", *((double *) col->DONNEES[i]));
            break;

        case STRING:
            strcpy(str, *((char **) col->DONNEES[col->TAILLE_LOGIQUE]));
            break;

        case CHAR:
            snprintf(str, size, "%c", *((char *) col->DONNEES[i]));
            break;

        case NULLVAL:
            snprintf(str, size, "%d", col->DONNEES[i]);
            break;

    }

}




// Supprimer une ligne dans une colonne et décale les valeurs
void delete_line(COLUMN* col) {
    int number_line;
    printf("\n\n\n");
    printf("LIGNE A SUPPRIME : ");
    scanf(" %d", &number_line);
    printf("\n");
    for(int i = number_line; i < col->TAILLE_LOGIQUE - 1; i++) {
        col->DONNEES[i] = col->DONNEES[i+1];
    }
    col->TAILLE_LOGIQUE--;
}



// Détermine le nombre d'occurence d'une valeur dans une colonne
int occurence(COLUMN* colonne, int val) {
    int occurence = 0;
    for (int i = 0; i < colonne->TAILLE_LOGIQUE; i++) {
        if (colonne->DONNEES[i] == val) {
            occurence++;
        }
    }
    return occurence;
}


// Retourne la valeur stockée dans une colonne avec sa position
int positionx(COLUMN* colonne, int position) {
    if (position < colonne->TAILLE_LOGIQUE) {
        return colonne->DONNEES[position];
    }
    else {
        return -1;
    }
}



// Calcul le nombre de valeur supérieure à x dans une colonne
int sup_x(COLUMN* colonne, int x) {
    int sup_x = 0;
    for (int i = 0; i < colonne->TAILLE_LOGIQUE; i++) {
        if (colonne->DONNEES[i] > x) {
            sup_x++;
        }
    }
    return sup_x;
}



// Calcul le nombre de valeur inférieure à x dans une colonne
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



// Change le nom d'une colonne par un nom donné par l'utilisateur
void rename_columns_name(COLUMN* col) {
    char title[100] = "";
    printf("Nouveau nom : ");
    scanf(" %s", title);
    strcpy(col->CHAINE, title);
}



// Cherche si une valeur est présente dans une colonne
int value_research(COLUMN* col, int value) {
    int presence = 0;
    for (int i = 0; i < col->TAILLE_LOGIQUE; i++) {
            if (col->DONNEES[i] == value) {
                printf("La valeur %d est presente a la colonne %s.\n", value, col->CHAINE);
                presence = 1;
            }
    }
    if (presence == 0) {
        printf("La valeur n'est pas presente dans la colonne %s.\n", col->CHAINE);
    }
    return presence;
}


void init_CData() {
    for(int i = 0; i < 3; i++) {
        printf("\n");
    }
    printf("========================================================================\n");
    printf("|| Il faut initialiser le Cdataframe avant de pouvoir le manipuler... ||\n");
    printf("========================================================================\n");
}

// Analyse et statistiques


//
int equal_x(COLUMN** CData, int nbre_colonne) {
    int nbre = 0, val;
    printf("valeur de x : ");
    scanf(" %d", &val);
    printf("\n");
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

void print_CData_selected_column(maillon* CData) {
    maillon* tmp ;
    int value1, value2;
    printf("\n\n");
    printf("COLONNE MINIMUM :");
    scanf(" %d", &value1);
    printf("\n");
    printf("COLONNE MAXIMUM :");
    scanf(" %d", &value2);
    printf("\n");
    if (CData != NULL)
    {
        tmp = CData;
        while(tmp->INDEX != value2)
        {
            if(tmp->INDEX > value1 - 1) {
                printf("%s\n", tmp->COLUMN->CHAINE);
                print_col(tmp->COLUMN);
                printf("\n");
            }
            tmp = (maillon *) tmp->SUCC;
        }
        printf("%s\n", tmp->COLUMN->CHAINE);
        print_col(tmp->COLUMN);
    }
}

int print_Col_lines(COLUMN* col, int value1, int value2) {
    if(value2 < col->TAILLE_LOGIQUE) {
        print_answer("Affichage");
        if (value2 < value1) {
            for (int i = 0; i<value2; i++) {
                printf("[%d] %d\n", i, col->DONNEES[i]);
            }
            printf("\n\n--------------------------------------------\n\n");
            for (int i = value1; i<col->TAILLE_LOGIQUE; i++) {
                printf("[%d] %d\n", i, col->DONNEES[i]);
            }
        }
        else {
            for (int i = value1; i < value2 + 1; i++) {
                printf("[%d] %d\n", i, col->DONNEES[i]);
            }
        }
        return 1;
    }
    else {
        return 0;
    }
}

void print_CData_selected_lines(maillon* CData) {
    maillon* tmp ;
    int value1, value2;
    printf("LIGNE MINIMUM :");
    scanf(" %d", &value1);
    printf("\n");
    printf("LIGNE MAXIMUM :");
    scanf(" %d", &value2);
    printf("\n");
    if (CData != NULL)
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

void print_CData_number_lines(maillon* CData) {
    int number_lines = 0;
    maillon* tmp ;
    if (CData != NULL)
    {
        tmp = CData;
        while(tmp != NULL)
        {
            printf("Le nombre de ligne de la colonne %s est de %d\n", tmp->COLUMN->CHAINE, tmp->COLUMN->TAILLE_LOGIQUE);
            number_lines += tmp->COLUMN->TAILLE_LOGIQUE;
            tmp = (maillon *) tmp->SUCC;
        }
    }
    printf("\nLe nombre total de ligne du CDataframe est de %d\n", number_lines);

}

void print_CData_number_column(maillon* CData) {
    int number_column = 0;
    maillon* tmp ;
    if (CData != NULL)
    {
        tmp = CData;
        while(tmp != NULL)
        {
            number_column++;
            tmp = (maillon *) tmp->SUCC;
        }
    }
    printf("Le nombre de colonne du CDataframe est de %d\n", number_column);
}