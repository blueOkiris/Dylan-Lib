#include <stdio.h>
#include <stdlib.h>

#include <dyllib.h>

void testLinkedList(void);

int main(int argc, char** args) {
    //printf("Hello, world!");
    testLinkedList();

    return 0;
}

void testLinkedList(void) {
    list *test = dlib.newList();
    printf("%d\n", test->head->index);

    for(int i = 0; i < 10; i++)
        dlib.appendList(test, dlib.heapInt(i));
    
    for(int i = 0; i < test->length; i++) {
        printf("List[%d] = %d\n", i, *(int*) dlib.accessList(test, i));
    }

    dlib.deleteList(test);
}
