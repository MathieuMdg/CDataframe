#ifndef CDATAFRAME_CDATAFRAME_H
#define CDATAFRAME_CDATAFRAME_H

typedef struct lnode_ {
    void *data; // Pointer to a column
    struct lnode_ *prev;
    struct lnode_ *next;
} LNODE;


typedef struct list_ {
    lnode *head;
    lnode *tail;
} LIST;
typedef LIST CDATAFRAME;


#endif //CDATAFRAME_CDATAFRAME_H
