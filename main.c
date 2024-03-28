#include <stdio.h>
#include "fonction.h.c"



int main(){
    char title[20];
    char* ptr_title;
    printf("Choisir un nom de colonne : ");
    scanf(" %s", title);
    ptr_title = title;
    COLUMN* col = create_column(ptr_title);
    printf("%d %d %s", col->TAILLE_PHYSIQUE, col->TAILLE_LOGIQUE, col->CHAINE);
    return 0;
}
