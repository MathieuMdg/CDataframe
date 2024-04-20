#include <stdio.h>
#include "column.h"



int main(){
    char title[20];
    char* ptr_title;
    printf("Choisir un nom de colonne : ");
    scanf(" %s", title);
    ptr_title = title;
    COLUMN* ptr_colonne = create_column(ptr_title);
    int val;
    printf("Choisir une valeur : ");
    scanf("%d", &val);
    if (insert_value(ptr_colonne, val)) {
        printf("Value added successfully to my column\n");
    }
    else
        printf("Error adding value to my column\n");

    insert_value(ptr_colonne, 7);
    insert_value(ptr_colonne, 5);
    insert_value(ptr_colonne, 9);
    insert_value(ptr_colonne, 7);
    insert_value(ptr_colonne, 9);
    insert_value(ptr_colonne, 187);
    insert_value(ptr_colonne, 7);
    print_col(ptr_colonne);
    printf("\n%d", occurence(ptr_colonne, 9));
    delete_column(&ptr_colonne);
    return 0;
}
