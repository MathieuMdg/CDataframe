#include <stdio.h>
#include "column.h"
#include <stdlib.h>
#include <string.h>


int main(){
///    char title[20];
///    char* ptr_title;
///    printf("Choisir un nom de colonne : ");
///    scanf(" %s", title);
///    ptr_title = title;
///    COLUMN* ptr_colonne = create_column(ptr_title);
///    int val;
///    printf("Choisir une valeur : ");
///    scanf("%d", &val);
///    if (insert_value(ptr_colonne, val)) {
///        printf("Value added successfully to my column\n");
///    }
///    else
///        printf("Error adding value to my column\n");

///    insert_value(ptr_colonne, 7);
///    insert_value(ptr_colonne, 5);
///    insert_value(ptr_colonne, 9);
///    insert_value(ptr_colonne, 7);
///    insert_value(ptr_colonne, 9);
///    insert_value(ptr_colonne, 187);
///    insert_value(ptr_colonne, 7);
///    print_col(ptr_colonne);
///    printf("\n%d", occurence(ptr_colonne, 9));
///    printf("\n%d",positionx(ptr_colonne, 2));
///    printf("\n%d", sup_x(ptr_colonne, 8));
///    printf("\n%d", inf_x(ptr_colonne, 8));
///    delete_column(&ptr_colonne);



    // Création du CDataframe
    COLUMN** CDataframe = NULL;
    int nbre_col;
    printf("Nombre de colonne du CDataframe? :");
    scanf(" %d", &nbre_col);

    CDataframe = (COLUMN**)malloc(sizeof(COLUMN*));


    for (int CData_column = 0; CData_column < nbre_col; CData_column++) {
        char title[100] = "";
        char* ptr_title = malloc(strlen(title) + 1);
        printf("\nNom de la colonne numero %d :", CData_column);
        scanf(" %s", title);
        strcpy(ptr_title, title);
        CDataframe[CData_column] = create_column(ptr_title);
    }



    for (int CData_column = 0; CData_column < nbre_col; CData_column++) {
        int nbre_valeur;
        printf("Combien de valeurs dans la colonne %d nommee %s: ", CData_column, CDataframe[CData_column]->CHAINE);
        scanf(" %d", &nbre_valeur);
        for (int column_line = 0; column_line<nbre_valeur; column_line++) {
            int val;
            printf("La valeur %d de la colonne %s : ", column_line, CDataframe[CData_column]->CHAINE);
            scanf(" %d", &val),
            insert_value(CDataframe[CData_column], val);
        }
        print_col(CDataframe[CData_column]);
    }
    for (int CData_column; CData_column < nbre_col; CData_column++) {
        delete_column(&CDataframe[CData_column]);
    }
    return 0;
}
