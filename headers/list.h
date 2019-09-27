/*
 * Structure and function definitions for a linked list
 * Uses "void *" for data to be generic.
 * This means the data placed in must ALWAYS be a reference
 */
#ifndef _LIST_H_
#define _LIST_H_

// The individual nodes of our linked list.
struct LINKED_LIST_CELL {
    void *value;

    int index;

    struct LINKED_LIST_CELL *previous;
    struct LINKED_LIST_CELL *next;
};

typedef struct LINKED_LIST {
    struct LINKED_LIST_CELL head;
} list;

list newList(void);

#endif