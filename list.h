#ifndef CDATAFRAME_LIST_H
#define CDATAFRAME_LIST_H
#include "column.h"
#include "cdataframe.h"


LNODE* create_lnode();

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);

int insert_lnode(CDATAFRAME* Cdata, LNODE* lnode, int position);

int delete_lnode(CDATAFRAME* Cdata, int position);

void delete_cdataframe(CDATAFRAME **cdf);

#endif //CDATAFRAME_LIST_H
