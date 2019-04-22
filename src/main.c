#include <stdio.h>
#include <string.h>
#include <stack.h>
#include <intstack.h>
#include <map.h>
#include <math.h>

void test_intstack(void);
void test_numstack(void);
int str_hashcode(char *);
void test_str2strmap(void);

int main(int argc, char** args) {
    //printf("Hello, world!");
    //test_intstack();
    //test_numstack();
    //test_str2strmap();

    return 0;
}

DEFINE_MAP_TYPE(char *, str, char *, str);
IMPLEMENT_MAP_TYPE(char *, str, char *, str, str_hashcode, strcmp);

int str_hashcode(char *key) {
    int len = strlen(key);
    int code = 0;

    for(int i = 0; i < len; i++) {
        code += key[0] * (int) pow(31, len - i - 1);
    }

    return code;
}

void test_str2strmap(void) {
    str2strmap *test = str2strmap_new();
    str2strmap_put(test, "Hello", "world");
    str2strmap_put(test, "123", "456");
    str2strmap_put(test, "ABC", "DEF");
    str2strmap_put(test, "I wanna ", "rule the world");
    str2strmap_put(test, "5-", "guys");

    printf("Hello, %s!\n", str2strmap_get(test, "Hello"));
    printf("123%s\n", str2strmap_get(test, "123"));
    printf("ABC%s\n", str2strmap_get(test, "ABC"));
    printf("I wanna %s\n", str2strmap_get(test, "I wanna "));
    printf("5-%s\n", str2strmap_get(test, "5-"));
}

DEFINE_STACK(int, num)
IMPLEMENT_STACK(int, num);

void test_numstack(void) {
    printf("Testing numstack!\n");
    
    numstack* test_stack = numstack_new();
    for(int i = 0; i < 6; i++)
        numstack_push(test_stack, i);

    printf("Data: ");
    for(int i = 0; i < test_stack->length; i++)
        printf("%d ", test_stack->data[i]);
    printf("\nPeek: %d\nPop: ", numstack_peek(test_stack));
    while(test_stack->length > 0)
        printf("%d ", numstack_pop(test_stack));

    free(test_stack->data);
    free(test_stack);

    printf("\nDone.\n");
}

void test_intstack(void) {
    printf("Testing intstack!\n");
    
    intstack* test_stack = intstackCreate();
    for(int i = 0; i < 6; i++)
        intstackPush(test_stack, i);

    printf("Data: ");
    for(int i = 0; i < test_stack->length; i++)
        printf("%d ", test_stack->data[i]);
    printf("\nPeek: %d\nPop: ", intstackPeek(test_stack));
    while(test_stack->length > 0)
        printf("%d ", intstackPop(test_stack));

    intstackDelete(test_stack);

    printf("\nDone.\n");
}
