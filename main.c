#include <stdio.h>
#include "column.h"
#include "fonctions.h"
#include <stdlib.h>
#include <string.h>


int main() {

    int running;
    running = 0;

    maillon *CDataframe = NULL;

    int init_CDataframe = 0;

    int full = 0;

    COLUMN *mycol = create_column(INT, "My column");

    for(int i = 0 ; i < 100 ; i++){
        insert_value(mycol, &i);
    }
    for(int i = 0 ; i < 100 ; i++){
        printf(" %", mycol->DONNEES[i]);
    }

    return 0;
    }