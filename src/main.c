#include <stdio.h>
#include <stdlib.h>

#include <dyllib.h>

int main(int argc, char** args) {
    //printf("Hello, world!");
    list *test = dlib.newList();
    printf("%d\n", test->head->index);

    for(int i = 0; i < 10; i++)
        dlib.appendList(test, (void *) i);
    
    for(int i = 0; i < test->length; i++) {
        printf("List[%d] = %d\n", i, (int) dlib.accessList(test, i));
    }

    dlib.deleteList(test);

    return 0;
}
