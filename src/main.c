#include <stdio.h>

#include <dyllib.h>

int main(int argc, char** args) {
    //printf("Hello, world!");
    list test = dlib.newList();
    printf("%d\n", test.head.index);

    return 0;
}
