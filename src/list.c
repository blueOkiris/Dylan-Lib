/*
 * Functions for setup and manipulation of the linked list
 */
#include <stdlib.h>
#include <stdio.h>

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
    new_list->length = 0;

    return new_list;
}

// Add data to a list
list *appendList(list *_list, void *data) {
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

    _list->length++;

    return _list;
}

// Delete all mallocs created
void deleteList(list *_list) {
    list_cell *current = _list->head;
    list_cell *cell_to_free;

    while(current != NULL) {
        cell_to_free = current;
        current = current->next;

        free(cell_to_free->value);
        free(cell_to_free);
    }

    free(_list);
}

// Get an element at a specific location in list
void *accessList(list *_list, int index) {
    list_cell *current = _list->head;

    while(current != NULL) {
        if(current->index == index)
            return current->value;

        current = current->next;
    }

    return NULL;
}

// Insert an element into a list at a specified index
list *insertInList(list *_list, int index, void *data) {
    list_cell *current = _list->head;

    // Special case where there's no items
    if(index >= _list->length)      // Add to end if expecting past tail
        appendList(_list, data);
    else {
        while(current != NULL) {
            if(current->index == index) {
                // Swap a new cell in for the old cell
                list_cell *new_cell = (list_cell *) malloc(sizeof(list_cell));
                new_cell->value = data;
                new_cell->previous = current->previous;
                new_cell->next = current;
                new_cell->index = index;
                current->previous->next = new_cell;
                current->previous = new_cell;

                current = new_cell;
                _list->length++;

                list_cell *index_cell = current->next;
                while(index_cell != NULL) {
                    index_cell->index++;
                    index_cell = index_cell->next;
                }

                break;
            }

            current = current->next;
        }
    }

    return _list;
}

// Remove an element at given index and return its data
list *removeFromList(list *_list, int index) {
    if(index < _list->length) {
        list_cell *current = _list->head;

        while(current != NULL) {
            if(current->index == index) {
                current->previous->next = current->next;
                current->next->previous = current->previous;

                list_cell *index_cell = current->next;
                while(index_cell != NULL) {
                    index_cell->index--;
                    index_cell = index_cell->next;
                }

                free(current->value);
                free(current);

                break;
            }

            current = current->next;
        }
    }

    return _list;
}

// Print the list to stdout
void debugPrintList(list *_list) {
    list_cell *current = _list->head->next;

    while(current != NULL) {
        int value = *((int*) current->value);
        printf("list[%d] = %d\n", current->index, value);
        current = current->next;
    }
}

list *changeList(list *_list, int index, void *new_data) {
    list_cell *current = _list->head->next;

    while(current != NULL) {
        if(current->index == index) {
            free(current->value);
            current->value = new_data;

            return _list;
        }

        current = current->next;
    }

    return _list;
}
