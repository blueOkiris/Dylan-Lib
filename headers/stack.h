#ifndef _STACK_H_
#define _STACK_H_

#include <stdlib.h>

#define DEFINE_STACK(type, type_name)\
\
    typedef struct type_name##stack {\
        type * data;\
        int length;\
    } type_name##stack;\
    \
    type_name##stack * type_name##stack_new(void);\
    void type_name##stack_push( type_name##stack * stack, type data);\
    type type_name##stack_peek( type_name##stack * stack );\
    type type_name##stack_pop( type_name##stack * stack );
    
#define IMPLEMENT_STACK(type, type_name)\
    type_name##stack * type_name##stack_new(void) {\
        type_name##stack * new_stack = ( type_name##stack * ) malloc(sizeof( type_name##stack ));\
        new_stack->data = NULL;\
        new_stack->length = 0;\
        return new_stack;\
    }\
    \
    void type_name##stack_push( type_name##stack * stack, type data) {\
        stack->length++;\
        stack->data = ( type *) realloc(stack->data, sizeof( type ) * stack->length);\
        stack->data[stack->length - 1] = data;\
    }\
    \
    type type_name##stack_peek( type_name##stack * stack ) {\
        return stack->data[stack->length - 1];\
    }\
    \
    type type_name##stack_pop( type_name##stack * stack ) {\
        type old_top = stack->data[stack->length - 1];\
        stack->length--;\
        stack->data = ( type *) realloc(stack->data, sizeof( type ) * stack->length);\
        return old_top;\
    }

#endif