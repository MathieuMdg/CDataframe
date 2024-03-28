#include <stdio.h>
#include "fonction.h.c"



int main(){
    char title[20];
    char* ptr_title;
    printf("Choisir un nom de colonne : ");
    scanf(" %s", title);
    ptr_title = title;
    COLUMN* col = create_column(ptr_title);
    int val;
    printf("Choisir une valeur : ");
    scanf("%d", &val);
    if (insert_value(col, val)) {
        printf("Value added successfully to my column\n");
        printf("%d", *col->DONNEES);
    }
    else
        printf("Error adding value to my column\n");
    return 0;
}
