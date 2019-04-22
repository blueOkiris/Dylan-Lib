#include <stdlib.h>
#include <intstack.h>

intstack* intstackCreate() {
    intstack* new_stack = (intstack*) malloc(sizeof(intstack));
    
    new_stack->data = NULL;
    new_stack->length = 0;
    
    return new_stack;
}

void intstackPush(intstack* stack, int data) {
    stack->length++;
    stack->data = (int*) realloc(stack->data, sizeof(int) * stack->length);
    stack->data[stack->length - 1] = data;
}

int intstackPeek(intstack* stack) {
    return stack->data[stack->length - 1];
}

int intstackPop(intstack* stack) {
    int old_top = stack->data[stack->length - 1];
    stack->length--;
    stack->data = (int*) realloc(stack->data, sizeof(int) * stack->length);
    return old_top;
}

void intstackDelete(intstack* stack) {
    free(stack->data);
    free(stack);
}
