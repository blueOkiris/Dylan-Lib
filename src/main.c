#include <stdio.h>
#include <stdlib.h>

#include <dyllib.h>

void testLinkedList(void);
void testString(void);

int main(int argc, char** args) {
    //printf("Hello, world!");
    testLinkedList();
    testString();

    return 0;
}

void testString(void) {
    string *str = dlib.newString();

    printf("Testing append string:\n");
    dlib.appendString(str, "Hello, world!");
    printf("%s\n", str->val);
    dlib.appendString(str, str->val);
    printf("%s\n", str->val);
    dlib.appendString(str, "DEATH");
    printf("%s\n", str->val);
    dlib.deleteString(str);

    printf("Testing insertion:\n");
    str = dlib.newString();
    dlib.appendString(str, "NEWSTRING");
    printf("%s\n", str->val);
    dlib.insertString(str, 0, "BLAH");
    printf("%s\n", str->val);
    dlib.insertString(str, 5, "BLAH");
    printf("%s\n", str->val);
    dlib.insertString(str, str->len - 1, "BLAH");
    printf("%s\n", str->val);

    printf("Freeing string\n");
    dlib.deleteString(str);
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
