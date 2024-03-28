#include <stdio.h>
#include "fonction.h.c"



int main(){
    COLUMN* col = create_column("miam");
    printf("%d\t%d\t%s", col->TAILLE_LOGIQUE, col->TAILLE_PHYSIQUE, col->CHAINE);
    return 0;
}
