#ifndef STACK_H
#define STACK_H

struct Node {
    int info;
    Node *next;
};
typedef Node *Address;

struct Stack {
    Address Top;          // kosong jika Top == nullptr
};

void createStack(Stack &S);
bool isEmpty(Stack S);
Address alokasi(int x);
void dealokasi(Address &P);
void push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(Stack S);
void pushAscending(Stack &S, int x);
void clearStack(Stack &S);

#endif
