#include <stdio.h>
#include <stdlib.h>

#include <dyllib.h>

void testLinkedList(void);
void testString(void);
void testDictionary(void);
void testMiscellaneous(void);

int main(int argc, char** args) {
    //printf("Hello, world!\n");
    //testLinkedList();
    //testString();
    //testDictionary();
    testMiscellaneous();

    return 0;
}

void testMiscellaneous(void) {
    string *main_c_src = dlib.fscantext("src/main.c");
    //printf("\n%s\n", main_c_src->val);
    dlib.deleteString(main_c_src);

    list *main_c_src_lines = dlib.fscanlines("src/main.c");
    for(int i = 0; i < main_c_src_lines->length; i++)
        printf("%s\n", (char *) dlib.accessList(main_c_src_lines, i));
    dlib.deleteList(main_c_src_lines);
}

void testDictionary(void) {
    dict *test = dlib.newDict();

    printf("Testing basic add/get:\n");
    dlib.addToDict(test, "taco", dlib.heapInt(1));
    dlib.addToDict(test, "burrito", dlib.heapInt(2));
    dlib.addToDict(test, "pasta", dlib.heapInt(3));

    printf("dict[\"taco\"] = %d\n", *(int *)dlib.getFromDict(test, "taco"));
    printf("dict[\"burrito\"] = %d\n", *(int *)dlib.getFromDict(test, "burrito"));
    printf("dict[\"pasta\"] = %d\n", *(int *)dlib.getFromDict(test, "pasta"));

    dlib.removeFromDict(test, "taco");
    printf("dict[\"burrito\"] = %d\n", *(int *)dlib.getFromDict(test, "burrito"));
    printf("dict[\"pasta\"] = %d\n", *(int *)dlib.getFromDict(test, "pasta"));
    if(dlib.getFromDict(test, "taco") == NULL)
        printf("Success!\n");
    else
        printf("Failure!\n");
    printf("%d\n", test->length);
    dlib.setDict(test, "burrito", dlib.heapInt(127));
    printf("dict[\"burrito\"] = %d\n", *(int *)dlib.getFromDict(test, "burrito"));

    printf("Freeing dict\n");
    dlib.deleteDict(test);
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
    printf("Freeing string\n");
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

    printf("Testing substring:\n");
    str = dlib.newString();
    dlib.appendString(str, "Hello, world!");
    printf("%s\n", str->val);
    string *str2 = dlib.substring(str, 1, 4);
    printf("%s\n", str2->val);
    printf("%d\n", str2->len);
    printf("Freeing strings\n");
    dlib.deleteString(str);
    dlib.deleteString(str2);

    printf("Testing removal:\n");
    str = dlib.newString();
    dlib.appendString(str, "HELLO WORLD!");
    printf("%s\n", str->val);
    dlib.removeString(str, 0, 5);
    printf("%s\n", str->val);
    dlib.insertString(str, 0, "THE");
    printf("%s\n", str->val);
    printf("%d\n", str->len);
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
