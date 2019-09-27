/*
 * The main hub where all the libraries meet
 * In here there is a global instance that gets created whenever the library is used.
 * It contains function references to all the other libraries
 */
#ifndef _DYLLIB_H_
#define _DYLLIB_H_

// The individual nodes of our linked list.
typedef struct LINKED_LIST_CELL {
    void *value;

    int index;

    struct LINKED_LIST_CELL *previous;
    struct LINKED_LIST_CELL *next;
} list_cell;

typedef struct LINKED_LIST {
    list_cell *head;
    list_cell *tail;

    int length;
} list;

typedef struct DYLAN_LIB {
    list *(*newList) (void);
    void (*appendList) (list *, void *);
    void (*deleteList) (list *);
    void *(*accessList) (list *, int);
} dylanlib;

extern dylanlib dlib; 

#endif