/*
 * Functions for setup and manipulation of the linked list
 */
#include <stdlib.h>

#include <list.h>

// Create a new list (on the stack)
list *newList(void) {
    list *new_list = (list *) malloc(sizeof(list));

    new_list->head = (list_cell *) malloc(sizeof(list_cell));
    new_list->head->index = -1;
    new_list->head->next = NULL;
    new_list->head->previous = NULL;
    new_list->head->value = NULL;

    new_list->tail = NULL;

    return new_list;
}

// Add data to a list
void appendList(list *_list, void *data) {
    list_cell *new_cell = (list_cell *) malloc(sizeof(list_cell));

    new_cell->value = data;
    if(_list->tail == NULL) {
        new_cell->index = 0;
        new_cell->previous = _list->head;
        _list->head->next = new_cell;
    } else {
        new_cell->index = _list->tail->index + 1;

        _list->tail->next = new_cell;
        new_cell->previous = _list->tail;
    }
    new_cell->next = NULL;

    _list->tail = new_cell;
}

// Delete all mallocs created
void deleteList(list *_list) {
    list_cell *current = _list->head;
    list_cell *cell_to_free;

    while(current != NULL) {
        cell_to_free = current;
        current = current->next;

        free(cell_to_free);
    }

    free(_list);
}
