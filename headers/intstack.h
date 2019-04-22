#ifndef _INTSTACK_H_
#define _INTSTACK_H_

typedef struct intstack {
    int *data;
    int length;
} intstack;

intstack* intstackCreate();
void intstackPush(intstack*, int);
int intstackPeek(intstack*);
int intstackPop(intstack*);
void intstackDelete(intstack*);

#endif

