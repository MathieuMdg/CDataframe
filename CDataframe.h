#ifndef CDATAFRAME_CDATAFRAME_H
#define CDATAFRAME_CDATAFRAME_H
#include "column.h"


typedef struct LNODE {;
    int NUMBER_COLONNE;
    struct LNODE *SUCC;
    struct LNODE * PREC;
    COLUMN* COLUMN;
} LNODE;


typedef struct list_ {
    LNODE *head;
    LNODE *tail;
} LIST;
typedef LIST CDATAFRAME;


CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);

void delete_cdataframe(CDATAFRAME **cdf);

int get_cdataframe_cols_size(CDATAFRAME *cdf);

CDATAFRAME* load_from_csv(char *file_name, ENUM_TYPE *dftype, int size);



#endif //CDATAFRAME_CDATAFRAME_H
