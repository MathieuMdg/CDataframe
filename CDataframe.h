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

COLUMN* acces_column_by_name(CDATAFRAME* cdata, char* column_name);

int add_lines(CDATAFRAME* CData);

CDATAFRAME* fill_CDataframe(CDATAFRAME* Cdata);

int load_from_cqv_insert_value(COLUMN* col, char* str, ENUM_TYPE col_type);

LNODE* create_lnode();

int insert_lnode(CDATAFRAME* Cdata, LNODE* lnode, int position);

CDATAFRAME* fill_CDataframe_auto(CDATAFRAME* Cdata);

int delete_lnode(CDATAFRAME* Cdata, int position);



#endif //CDATAFRAME_CDATAFRAME_H
