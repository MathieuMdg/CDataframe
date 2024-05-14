#include <stdio.h>
#include "column.h"
#include "fonctions.h"
#include <stdlib.h>
#include <string.h>
#define ASC 0
#define DESC 1

int main() {

    COLUMN *mycol = create_column(STRING, "sorted column");
    char a[] = "abracadabra";
    char b[] = "boboub";
    char c[] = "c";
    char d[] = "duouloul";
    char e[] = "escalib";
    insert_value(mycol, &a);
    insert_value(mycol, &b);
    insert_value(mycol, &e);
    insert_value(mycol, &e);
    insert_value(mycol, &c);
    insert_value(mycol, &e);
    insert_value(mycol, &d);
    printf("Column content before sorting : \n");
    print_col(mycol);
    sort(mycol,DESC);
    printf("Column content after sorting : \n");
    print_col_by_index(mycol);
    printf("\n%d", search_value_in_column(mycol, (void *) "c"));



    return 0;
    }