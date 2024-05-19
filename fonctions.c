#include "column.h"
#include "CDataframe.h"
#include "fonctions.h"
#define REALOC_SIZE 256
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define ASC 0
#define DESC 1

LNODE * CData_create_column() {
    LNODE *nouveau = (LNODE *) malloc(sizeof(LNODE));
    char title[100];
    printf("\n\n\n");
    printf("TITRE COLONNE : ");
    scanf(" %s", title);
    char *ptr_title = malloc(strlen(title) + 1);
    strcpy(ptr_title, title);
    enum enum_type type;
    printf("\n\n\nTYPE DE LA COLONNE %s (NULLVAL[1] , UINT[2], INT[3], CHAR[4], FLOAT[5], DOUBLE[6], STRING[7], STRUCTURE[8]) : ",
           ptr_title);
    scanf(" %u", &type);
    printf("\n\n\n");
    nouveau->COLUMN = create_column(type, ptr_title);
    int number_lines;
    printf("CHOISIR NOMBRE DE LIGNE POUR LA COLONNE [%d] %s : ",
           nouveau->NUMBER_COLONNE, nouveau->COLUMN->CHAINE);
    scanf(" %d", &number_lines);
    for (int i = 0; i < 3; i++)
        printf("\n");
    for (int j = 0; j < number_lines; j++) {
        void *value = type_choice(nouveau->COLUMN);
        if (nouveau->COLUMN->COLUMN_TYPE == STRING) {
            insert_value(nouveau->COLUMN, value, nouveau->COLUMN->COLUMN_TYPE);
        } else {
            insert_value(nouveau->COLUMN, &value, nouveau->COLUMN->COLUMN_TYPE);
        }
    }
    return nouveau;
}


// Affiche le menu du programme
void menu() {
    for(int i = 0; i<6; i++)
        printf("\n");
    printf("1. Alimentation\n\n- Creation du CDataframe vide\n- Remplissage du CDataframe a partir de saisies utilisateurs\n- Remplissage en dur du CDataframe\n\n2. Affichage\n\n- Afficher tout le CDataframe\n- Afficher une partie des lignes du CDataframe selon une limite fournie par l utilisateur\n- Afficher une partie des colonnes du CDataframe selon une limite fournie par l utilisateur\n\n3. Operations usuelles\n\n- Ajouter une ligne de valeurs au CDataframe\n- Supprimer une ligne de valeurs du CDataframe\n- Ajouter une colonne au CDataframe\n- Supprimer une colonne du CDataframe\n- Renommer le titre d une colonne du CDataframe\n- Verifier l existence d une valeur (recherche) dans le CDataframe\n- Acceder/remplacer la valeur se trouvant dans une cellule du CDataframe en utilisant son\nnumero de ligne et de colonne\n- Afficher les noms des colonnes\n\n4. Analyse et statistiques\n\n- Afficher le nombre de lignes\n- Afficher le nombre de colonnes\n- Nombre de cellules contenant une valeur egale a x (x donne en parametre)\n- Nombre de cellules contenant une valeur superieure a x (x donne en parametre)\n- Nombre de cellules contenant une valeur inferieure a x(x donne en parametre)\n\n5.Manupulation de CDataframe\n\n- Trier une colonne\n- Regarder le statut d'index d'une colonne\n- Effacer l'index d'une colonne\n- Importer un CDataframe d'un fichier .csv\n- Sauvegarder un CDataframe dans un fichier .csv");
    for(int i = 0; i<3; i++)
        printf("\n");
}


// Fonction d'affichage des réponseds
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


// Fonction qui permet à l'utilisateur de saisir la donnée dans le type de la colonne
void* type_choice(COLUMN* col) {
    switch (col->COLUMN_TYPE) {

        case CHAR:
            printf("CHOISIR VALEUR TYPE [CHAR] : ");
            char* value_char = (char*) malloc(sizeof (char));
            scanf(" %c", value_char);
            printf("\n\n\n");
            col->DONNEES[col->TAILLE_LOGIQUE] = (COL_TYPE *) value_char;
            return value_char;

        case INT:
            printf("CHOISIR VALEUR TYPE [INT] : ");
            int* value_int = (int*) malloc(sizeof (int));
            scanf(" %d", value_int);
            printf("\n\n\n");
            return value_int;

        case UINT:
            printf("CHOISIR VALEUR TYPE [UINT] : ");
            unsigned int* value_uint = (unsigned int*) malloc(sizeof (unsigned int));
            scanf(" %u", (unsigned int*) &value_uint);
            printf("\n\n\n");
            return value_uint;

        case FLOAT:
            printf("CHOISIR VALEUR TYPE [FLOAT] : ");
            float* value_float = (float*) malloc(sizeof (float));
            scanf(" %f", (float*) &value_float);
            printf("\n\n\n");
            return value_float;

        case DOUBLE:
            printf("CHOISIR VALEUR TYPE [DOUBLE] : ");
            double* value_double = (double *) malloc(sizeof (double ));
            scanf(" %lf", (double*) &value_double);
            printf("\n\n\n");
            return value_double;

        case NULLVAL:
            printf("CHOISIR VALEUR TYPE [NULLVAL] : ");
            void* value_null = NULL;
            printf("\n\n\n");
            return value_null;

        case STRING:
            printf("CHOISIR VALEUR TYPE [STRING] : ");
            char* value_string = (char*) malloc(sizeof (char));
            scanf(" %s", value_string);
            printf("\n\n\n");
            return value_string;

        case STRUCTURE:
            printf("CHOISIR VALEUR TYPE [STRUCTURE] : ");
            //double* value_double = (double *) malloc(sizeof (double ));
            //scanf(" %lf", (double*) &value_double);
            //printf("\n\n\n");
           // return value_double;

        default:
            printf("TYPE DE COLONNE ERRONE\n");
            break;
    }
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
    ptr_colonne->INDEX = (unsigned long long int*) malloc(sizeof(unsigned long long int) * REALOC_SIZE);
    return ptr_colonne;
}


// Permet d'ajouter une valeur à la fin d'une colonne et de l'agrandir si besoin
int insert_value(COLUMN* col, void* value, ENUM_TYPE col_type) {

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

    if (col->TAILLE_LOGIQUE == col->TAILLE_PHYSIQUE) {
        col->TAILLE_PHYSIQUE += REALOC_SIZE;
        col->DONNEES = realloc(col->DONNEES, col->TAILLE_PHYSIQUE);
        col->INDEX = realloc(col->INDEX, col->TAILLE_PHYSIQUE);
        printf("REALLOCATION...");
    }


    col->INDEX[col->TAILLE_LOGIQUE] = col->TAILLE_LOGIQUE;

    if (value == NULL){
        col->DONNEES[col->TAILLE_LOGIQUE] = NULL;
    }

    else {

        // Affecter la valeur en fonction du type de colonne
        switch (col->COLUMN_TYPE) {

            case CHAR:
                col->DONNEES[col->TAILLE_LOGIQUE] = (COL_TYPE *) (char *) malloc(sizeof(char));
                *((char *) col->DONNEES[col->TAILLE_LOGIQUE]) = *((char *) value);
                break;

            case INT:

                col->DONNEES[col->TAILLE_LOGIQUE] = (COL_TYPE *) (int *) malloc(sizeof(int));
                if (col->DONNEES[col->TAILLE_LOGIQUE] == NULL) {
                    printf("ERREUR ALLOCATION");
                    printf("%d", *((int*) value));
                }

                *((int *) col->DONNEES[col->TAILLE_LOGIQUE]) = *((int *) value);
                if (col->DONNEES[col->TAILLE_LOGIQUE] == NULL) {
                    printf("ERREUR D ASSIGNATION DE LA VALEUR");
                }
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
                col->DONNEES[col->TAILLE_LOGIQUE] = (char *) malloc(sizeof(char));
                col->DONNEES[col->TAILLE_LOGIQUE] = value;
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


// Fonction de tri par insertion pour un tableau d'index
void insertion(COL_TYPE * arr[], unsigned long long int index[], unsigned int n) {
    int i, j;
    unsigned long long int key_index;
    for (i = 1; i < n; i++) {
        key_index = index[i];
        int key_data = *((int*) arr[key_index]);
        j = i - 1;

        while (j >= 0 && *((int*) arr[index[j]]) > key_data) {
            index[j + 1] = index[j];
            j = j - 1;
        }
        index[j + 1] = key_index;
    }
}


// Fonction Partition utilisée dans Quicksort pour un tableau d'index
int partition(COL_TYPE * arr[], unsigned long long int index[], int low, unsigned int high, COLUMN* col) {
    if (col->COLUMN_TYPE == STRING) {
        char* pivot = (char*) arr[index[high]];
        int i = (low - 1); // Index du plus petit élément


        for (int j = low; j <= high - 1; j++) {
            if (strcmp((char *) arr[index[j]], pivot) <= 0) {
                i++;
                // Échanger index[i] et index[j]
                unsigned long long int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
        // Échanger index[i + 1] et index[high] (pivot)
        unsigned long long int temp = index[i + 1];
        index[i + 1] = index[high];
        index[high] = temp;
        return (i + 1);
    }
    else {
        int pivot = *((int *) arr[index[high]]);
        int i = (low - 1); // Index du plus petit élément

        for (int j = low; j <= high - 1; j++) {
            if (*((int *) arr[index[j]]) <= pivot) {
                i++;
                // Échanger index[i] et index[j]
                unsigned long long int temp = index[i];
                index[i] = index[j];
                index[j] = temp;
            }
        }
        // Échanger index[i + 1] et index[high] (pivot)
        unsigned long long int temp = index[i + 1];
        index[i + 1] = index[high];
        index[high] = temp;
        return (i + 1);
    }
}


// Fonction Quicksort pour un tableau d'index
void quicksort(COL_TYPE * arr[], unsigned long long int index[], int low, unsigned int high, COLUMN* col) {
    if (low < high) {
        // pi est l'index de partition, index[pi] est à la bonne position
        int pi = partition(arr, index, low, high, col);

        // Tri des éléments séparément avant et après la partition
        quicksort(arr, index, low, pi - 1, col);
        quicksort(arr, index, pi + 1, high, col);
    }
}


// Fonction de tri générale en fonction du type de tri pour un tableau d'index
void sort(COLUMN* col, int sort_dir) {
    if (col->VALID_INDEX == 0) {
        // Tri non trié : Utiliser Quicksort pour le tableau d'index
        quicksort(col->DONNEES, col->INDEX, 0, col->TAILLE_LOGIQUE - 1, col);
    } else if (col->VALID_INDEX == -1) {
        // Tri partiellement trié : Utiliser Insertion Sort pour le tableau d'index
        insertion(col->DONNEES, col->INDEX, col->TAILLE_LOGIQUE);
    }

    // Si le tri est DESC, inverser le tableau d'index trié
    if (sort_dir == DESC) {
        int i = 0;
        unsigned int j = col->TAILLE_LOGIQUE - 1;
        while (i < j) {
            unsigned long long int temp = col->INDEX[i];
            col->INDEX[i] = col->INDEX[j];
            col->INDEX[j] = temp;
            i++;
            j--;
        }
    }
    col->VALID_INDEX = 1;
    col->SORT_DIR = sort_dir;
}


// Fonction de recherche dichotomique dans un tableau d'index trié
int binarySearch(COLUMN * col, int left, int right, void* value) {
    if (col->COLUMN_TYPE == STRING) {
        while (left <= right) {

            int middle = left + (right - left) / 2;

            // Accéder à l'élément cible dans le tableau principal de données via l'index
            char* current = (char *) col->DONNEES[col->INDEX[middle]];
            printf(" %s", current);


            // Comparaison de l'élément actuel avec la cible
            // Ici, nous supposons que nous comparons des entiers (à adapter en fonction de COLUMN_TYPE)
            if (strcmp(current, (char *) value) == 0) {

                return middle; // Retourne l'indice dans le tableau d'index
            }

            // Mise à jour des limites de recherche en fonction de la comparaison
            if (col->SORT_DIR == ASC) {
                if (strcmp(current, (char *) value) < 0 ) {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                }
            }
            else {
                if (strcmp(current, (char *) value) < 0) {
                    right = middle - 1;
                }
                else {
                    left = middle + 1;
                }
            }
        }
    }
    else {
        while (left <= right) {

            int middle = left + (right - left) / 2;

            // Accéder à l'élément cible dans le tableau principal de données via l'index
            int current = *((int *) col->DONNEES[col->INDEX[middle]]);


            // Comparaison de l'élément actuel avec la cible
            // Ici, nous supposons que nous comparons des entiers (à adapter en fonction de COLUMN_TYPE)
            if (current == (int *) value) {

                return middle; // Retourne l'indice dans le tableau d'index
            }

            // Mise à jour des limites de recherche en fonction de la comparaison
            if (col->SORT_DIR == ASC) {
                if (current < (int *) value) {
                    left = middle + 1;
                }
                else {
                    right = middle - 1;
                }
            }
            else {
                if (current < (int *) value) {
                    right = middle + 1;
                }
                else {
                    left = middle - 1;
                }
            }

        }
    }

    // Si la cible n'est pas trouvée dans le tableau d'index
    return 0;
}


// Fonction de recherche de valeur dans la colonne avec tableau d'index et recherche dichotomique
int search_value_in_column(COLUMN* col, void* value) {
    if (col == NULL || col->INDEX == NULL || col->TAILLE_LOGIQUE == 0 || col->VALID_INDEX != 1)
        return -1; // Cas de tableau vide ou index non valide

    // Utilisation de la recherche dichotomique sur le tableau d'index trié
    int result = binarySearch(col, 0, col->TAILLE_LOGIQUE - 1, value);

    return result;
}


void erase_index(COLUMN *col) {
    free(col->INDEX);
    col->INDEX = NULL;
    col->VALID_INDEX = 0;
}


void print_col_by_index(COLUMN *col) {
    for (int i = 0; i < col->TAILLE_LOGIQUE; i++) {
        if (col->DONNEES[col->INDEX[i]] == NULL) {
            printf("[%d] NULL\n", i);
        }
        else {
            if (col->COLUMN_TYPE != STRING) {
                char str[100];
                convert_value(col, col->INDEX[i], str, 100);
                printf("[%d] %s\n", i, str);
            }
            else {
                printf("[%d] %s\n", i, (char*) col->DONNEES[col->INDEX[i]]);
            }

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
            if (col->COLUMN_TYPE != STRING) {
                char str[50];
                convert_value(col, i, str, 50);
                printf("[%d] %s\n", i, str);
            }
            else {
                printf("[%d] %s\n", i, (char*) col->DONNEES[i]);
            }

        }
    }
}


int check_index(COLUMN *col) {
    if (col->VALID_INDEX == 0) {
        return 0;
    }
    if (col->VALID_INDEX == -1) {
        return -1;
    }
    else {
        return 1;
    }
}


void update_index(COLUMN *col) {
    sort(col, col->SORT_DIR);
}


// Supprime l'espace mémoire occupé par une colonne
void delete_column(COLUMN* col) {
    for (int i = 0; i<col->TAILLE_LOGIQUE; i++) {
        free(col->DONNEES[i]);
    }
    free(col->DONNEES);
    free(col);
}


// Converti les valeurs d'une colonne en chaine de caractère
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
            strcpy(str, (char*) col->DONNEES[i]);
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
    if (insert_value(CData[colonne], val, INT)) {
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


void print_CData_chaine(CDATAFRAME* CData) {

    LNODE* tmp ;
    if (CData->head != NULL)
    {
        tmp = CData->head;
        while(tmp != NULL)
        {
            printf("%s\n", tmp->COLUMN->CHAINE);
            print_col(tmp->COLUMN);
            printf("\n");
            tmp = (LNODE *) tmp->SUCC;
        }
    }
}

void print_CData_selected_column(CDATAFRAME* CData) {

    LNODE* tmp ;
    int value1, value2;
    printf("\n\n");
    printf("COLONNE MINIMUM :");
    scanf(" %d", &value1);
    printf("\n");
    printf("COLONNE MAXIMUM :");
    scanf(" %d", &value2);
    printf("\n");

    print_answer("Affichage...");

    if (CData != NULL && CData->head != NULL)
    {
        tmp = CData->head;
        int i = 0;

        while(tmp != NULL && i < value2)
        {
            if(i > value1 - 1) {
                printf("%s\n", tmp->COLUMN->CHAINE);
                print_col(tmp->COLUMN);
                printf("\n");

            }
            i++;
            tmp = (LNODE *) tmp->SUCC;
        }
        printf("%s\n", tmp->COLUMN->CHAINE);
        print_col(tmp->COLUMN);
    }
}

int print_Col_lines(COLUMN* col, int value1, int value2) {
    if(value2 < col->TAILLE_LOGIQUE) {

        if (value2 < value1) {
            for (int i = 0; i<value2; i++) {
                if (col->DONNEES[i] == NULL) {
                    printf("[%d] NULL\n", i);
                }
                else {
                    if (col->COLUMN_TYPE != STRING) {
                        char str[50];
                        convert_value(col, i, str, 50);
                        printf("[%d] %s\n", i, str);
                    }
                    else {
                        printf("[%d] %s\n", i, (char*) col->DONNEES[i]);
                    }

                }
            }
            printf("\n\n--------------------------------------------\n\n");
            for (int i = value1; i<col->TAILLE_LOGIQUE; i++) {
                if (col->DONNEES[i] == NULL) {
                    printf("[%d] NULL\n", i);
                }
                else {
                    if (col->COLUMN_TYPE != STRING) {
                        char str[50];
                        convert_value(col, i, str, 50);
                        printf("[%d] %s\n", i, str);
                    }
                    else {
                        printf("[%d] %s\n", i, (char*) col->DONNEES[i]);
                    }

                }
            }
        }
        else {
            for (int i = value1; i < value2 + 1; i++) {
                if (col->DONNEES[i] == NULL) {
                    printf("[%d] NULL\n", i);
                }
                else {
                    if (col->COLUMN_TYPE != STRING) {
                        char str[50];
                        convert_value(col, i, str, 50);
                        printf("[%d] %s\n", i, str);
                    }
                    else {
                        printf("[%d] %s\n", i, (char*) col->DONNEES[i]);
                    }

                }
            }
        }
        return 1;
    }
    else {
        print_answer("Les valeurs sont superieurs a la taille de la colonne...");
        return 0;
    }
}

void print_CData_selected_lines(CDATAFRAME* CData) {
    LNODE* tmp ;
    int value1, value2;
    printf("LIGNE MINIMUM :");
    scanf(" %d", &value1);
    printf("\n");
    printf("LIGNE MAXIMUM :");
    scanf(" %d", &value2);
    printf("\n");

    print_answer("Affichage");

    if (CData != NULL)
    {
        tmp = CData->head;
        while(tmp != NULL)
        {
            printf("%s\n", tmp->COLUMN->CHAINE);
            print_Col_lines(tmp->COLUMN, value1, value2);
            printf("\n");
            tmp = (LNODE *) tmp->SUCC;
        }
    }
}

void print_CData_number_lines(LNODE* CData) {
    int number_lines = 0;
    LNODE* tmp ;
    if (CData != NULL)
    {
        tmp = CData;
        while(tmp != NULL)
        {
            printf("Le nombre de ligne de la colonne %s est de %d\n", tmp->COLUMN->CHAINE, tmp->COLUMN->TAILLE_LOGIQUE);
            number_lines += tmp->COLUMN->TAILLE_LOGIQUE;
            tmp = (LNODE *) tmp->SUCC;
        }
    }
    printf("\nLe nombre total de ligne du CDataframe est de %d\n", number_lines);

}

void print_CData_number_column(LNODE* CData) {
    int number_column = 0;
    LNODE* tmp ;
    if (CData != NULL)
    {
        tmp = CData;
        while(tmp != NULL)
        {
            number_column++;
            tmp = (LNODE *) tmp->SUCC;
        }
    }
    printf("Le nombre de colonne du CDataframe est de %d\n", number_column);
}

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdata_type, int number_column) {
    CDATAFRAME* CData = (LIST*) malloc(sizeof (LIST));
    CData->head = NULL;
    CData->tail = NULL;

    if(number_column == 0) {
        return CData;
    }

    if (number_column > 0) {
        for (int i = 0; i<number_column; i++) {

            LNODE* lnode = (LNODE *) malloc(sizeof (LNODE));
            lnode->NUMBER_COLONNE = i;
            lnode->PREC = NULL;
            lnode->SUCC = NULL;

            lnode->COLUMN = create_column(cdata_type[i], "colonne");

            if(CData->head == NULL) {
                CData->head = lnode;
            }
            else {
                LNODE* tmp = CData->head;
                while (tmp->SUCC != NULL) {
                    tmp = tmp->SUCC;
                }
                tmp->SUCC = lnode;
                lnode->PREC = tmp;
                CData->tail = lnode;
            }
        }
    }
    return CData;
}

void delete_cdataframe(CDATAFRAME **cdf) {
    LNODE* tmp = (*cdf)->head;
    while (tmp != NULL) {
        delete_column(tmp->COLUMN);
        LNODE* tmp_succ = tmp->SUCC;
        free(tmp);
        tmp = tmp_succ;
    }

    free(*cdf);
}

int get_cdataframe_cols_size(CDATAFRAME *cdf) {
    int number_column = 0;
    LNODE* tmp = cdf->head;
    while (tmp != 0) {
        number_column++;
        tmp = tmp->SUCC;
    }
    return number_column;
}

CDATAFRAME* load_from_csv(char *file_name, ENUM_TYPE *dftype, int size) {

    CDATAFRAME* Cdata = create_cdataframe(dftype, size);

    FILE *file;
    char ligne[256];  // Buffer pour stocker les lignes lues
    char file_path[] = "C:\\Users\\abuhl\\Documents\\GitHub\\CDataframe\\";
    strcat(file_path, file_name);

    file = fopen(file_path, "rt");

    if (file == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return NULL;
    }

    LNODE* tmp = Cdata->head;

    while (tmp != NULL) {
        tmp->COLUMN = create_column(dftype[tmp->NUMBER_COLONNE],"");
        tmp = tmp->SUCC;
    }

    char* chaine;
    while (fgets(ligne, sizeof(ligne), file) != NULL) {
        tmp = Cdata->head;
        const char * separators = ",;\n";
        chaine = strtok (ligne, separators);
        while (tmp != NULL) {
            char *ptr_chaine = (char*) malloc(sizeof (char));
            strcpy(ptr_chaine, chaine);
            printf("%s\n", ptr_chaine);
            insert_value(tmp->COLUMN, ptr_chaine, STRING);
            tmp = tmp->SUCC;
            chaine = strtok (NULL, separators);
        }

    }
    return Cdata;

}


void save_into_csv(CDATAFRAME *cdf, char *file_name) {
    FILE *fpt;

    char file_path[] = "C:\\Users\\abuhl\\Documents\\GitHub\\CDataframe\\";
    strcat(file_path, file_name);

    fpt = fopen(file_path, "w+");


    LNODE* tmp = cdf->head;
    printf("%d", tmp->COLUMN->TAILLE_LOGIQUE);

        for(int i = 0; i<tmp->COLUMN->TAILLE_LOGIQUE; i++) {
            tmp = cdf->head;
            while (tmp->SUCC != NULL) {
                char* str = (char*) malloc(sizeof (char) * 50);
                convert_value(tmp->COLUMN, i, str, 50);
                fprintf(fpt, "%s,", str);
                tmp = tmp->SUCC;
            }
            char* str = (char*) malloc(sizeof (char) * 50);
            convert_value(tmp->COLUMN, i, str, 50);
            fprintf(fpt, "%s", str);
            fprintf(fpt, "\n");
        }

    fclose(fpt);
}

COLUMN* acces_column_by_name(CDATAFRAME* cdata, char* column_name) {
    LNODE* tmp = cdata->head;
    while (tmp != NULL && strcmp((tmp->COLUMN->CHAINE), column_name) != 0) {
        tmp = tmp->SUCC;
    }
    if (tmp != NULL){
        return tmp->COLUMN;
    }
    else{
        print_answer("Colonne introuvable");
        return NULL;
    }
}


// Rempli un CDataframe vide avec des saisies utilisateurs
CDATAFRAME* fill_CDataframe(CDATAFRAME* Cdata) {

    int number_column;
    printf("\n\n\n");

    printf("CHOISIR NOMBRE DE COLONNE DU CDATAFRAME :");
    scanf(" %d", &number_column);
    printf("\n\n\n");

    for (int i = 0; i < number_column; i++) {

        LNODE* lnode = create_lnode();


        insert_lnode(Cdata, lnode, 1);
        printf("ZJFQOF");

        printf("NOM DE LA COLONNE %d : ", i);
        char title[100] = "";
        char *ptr_title = malloc(strlen(title) + 1);
        enum enum_type type;


        scanf(" %s", title);
        strcpy(ptr_title, title);
        printf("\n\n\nTYPE DE LA COLONNE %s (NULLVAL[1] , UINT[2], INT[3], CHAR[4], FLOAT[5], DOUBLE[6], STRING[7], STRUCTURE[8]) : ", ptr_title);
        scanf(" %u", &type);
        printf("\n\n\n");


        lnode->COLUMN = create_column(type, ptr_title);

        int number_lines;
        printf("CHOISIR NOMBRE DE LIGNE POUR LA COLONNE %s[%d] : ", lnode->COLUMN->CHAINE, lnode->NUMBER_COLONNE);
        scanf(" %d", &number_lines);
        printf("\n");
        printf("\n\n\n");

        for (int j = 0; j < number_lines; j++) {



            if (insert_value(lnode->COLUMN, type_choice(lnode->COLUMN), lnode->COLUMN->COLUMN_TYPE)) {
                printf("\nINSERTION GOOD");
            }
            else {
                printf("\nNICHT GUT");
            }

        }
    }
    printf("mim");
    return Cdata;
}


// Créer un nouveau maillon
LNODE* create_lnode() {

    LNODE* new_lnode = (LNODE *)malloc(sizeof(LNODE));
    new_lnode->SUCC = NULL;
    new_lnode->PREC = NULL;
    new_lnode->NUMBER_COLONNE = 0;
    new_lnode->COLUMN = NULL;
    return new_lnode;

}

int insert_lnode(CDATAFRAME* Cdata, LNODE* lnode, int position) {
    if (Cdata == NULL) {
        CDATAFRAME new_Cdata;
        Cdata = &new_Cdata;
        Cdata->head = lnode;
        Cdata->tail = lnode;
        return 1;
    } else {
        if (Cdata->head == NULL) {
            Cdata->head = lnode;
            Cdata->tail = lnode;
        } else {
            if (position == 0) {
                LNODE *tmp = Cdata->head;
                tmp->PREC = lnode;
                lnode->SUCC = tmp;
                Cdata->head = lnode;
                return 1;
            } else {
                LNODE *tmp = Cdata->tail;
                tmp->SUCC = lnode;
                lnode->PREC = tmp;
                Cdata->tail = lnode;
                return 1;
            }
        }
    }
    return 0;

}


CDATAFRAME* fill_CDataframe_auto(CDATAFRAME* Cdata) {

    int number_column = 3;


    for (int i = 0; i < number_column; i++) {

        LNODE* lnode = create_lnode();


        insert_lnode(Cdata, lnode, 1);


        lnode->COLUMN = create_column(INT, "colonne");

        int number_lines = 3;


        for (int j = 0; j < number_lines; j++) {

            int number = j + i;

            if (insert_value(lnode->COLUMN, &number, lnode->COLUMN->COLUMN_TYPE)) {
                printf("\nINSERTION GOOD");
            }
            else {
                printf("\nNICHT GUT");
            }


        }
    }

    return Cdata;
}


