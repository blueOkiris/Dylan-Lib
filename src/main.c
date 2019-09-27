#include <stdio.h>
#include <stdlib.h>

#include <dyllib.h>

int main(int argc, char** args) {
    //printf("Hello, world!");
    list *test = dlib.newList();
    printf("%d\n", test->head->index);

    for(int i = 0; i < 10; i++)
        dlib.appendList(test, (void *) i);
    
    list_cell *cell = test->head->next;
    while(cell != NULL) {
        printf("List[%d] = %d\n", cell->index, (int) cell->value);
        cell = cell->next;
    }
    dlib.deleteList(test);

    return 0;
}
