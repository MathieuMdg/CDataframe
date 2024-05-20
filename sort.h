#ifndef CDATAFRAME_SORT_H
#define CDATAFRAME_SORT_H
#include "column.h"


void sort(COLUMN* col, int sort_dir);

int partition(COL_TYPE * arr[], unsigned long long int index[], int low, unsigned int high, COLUMN* col);

void insertion(COL_TYPE * arr[], unsigned long long int index[], unsigned int n);

#endif //CDATAFRAME_SORT_H
