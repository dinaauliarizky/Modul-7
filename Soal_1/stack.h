#ifndef STACK_H
#define STACK_H

const int MAKS = 20;

struct Stack {
    int info[MAKS + 1];   // indeks data 1..20
    int Top;              // 0 = kosong, 20 = penuh
};

void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif
