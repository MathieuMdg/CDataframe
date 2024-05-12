#include <stdio.h>
#include "column.h"
#include "fonctions.h"
#include <stdlib.h>
#include <string.h>


int main() {

    COLUMN *mycol = create_column(CHAR, "Column 1");
    char a = 'A', c = 'C', b = 'Z';
    insert_value(mycol, &a);
    insert_value(mycol, &c);
    insert_value(mycol, NULL);
    insert_value(mycol, &b);
    print_col(mycol);



    return 0;
    }