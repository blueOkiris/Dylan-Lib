/*
 * The main hub where all the libraries meet
 * In here there is a global instance that gets created whenever the library is used.
 * It contains function references to all the other libraries
 */
#ifndef _DYLLIB_H_
#define _DYLLIB_H_

#include <stdint.h>

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

typedef struct STRING {
    int len;
    char *val;
} string;

typedef struct DYLAN_LIB {
    // Linked list functions
    list *(*newList) (void);
    void (*appendList) (list *lst, void *data);
    void (*deleteList) (list *lst);
    void *(*accessList) (list *lst, int index);
    void (*insertInList) (list *lst, int index, void *data);
    void (*removeFromList) (list *lst, int index);
    void *(*heapInt) (uint64_t data);
    void (*debugPrintList) (list *lst);

    // String functions
    string *(*newString) (void);
    void (*deleteString) (string *str);
    void (*appendString) (string *str, char *value);
    void (*insertString) (string *str, int, char *value);
    void (*removeString) (string *str, int start, int len);
    string *(*substring) (string *str, int start, int len);
} dylanlib;

extern dylanlib dlib; 

#endif