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

    printf("Testing Basic Append:\n");

    for(int i = 0; i < 10; i++)
        dlib.appendList(test, dlib.heapInt(i));
    
    dlib.debugPrintList(test);

    printf("Testing Insertion:\n");
    for(int i = 5; i < 10; i++)
        dlib.insertInList(test, 5, dlib.heapInt(i));

    dlib.debugPrintList(test);

    printf("Testing Removal:\n");
    for(int i = 0; i < 3; i++)
        dlib.removeFromList(test, 2);

    dlib.debugPrintList(test);

    printf("Freeing list\n");
    dlib.deleteList(test);
}
