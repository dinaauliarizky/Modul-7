#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(Stack S) {
    return S.Top == nullptr;
}

Address alokasi(int x) {
    Address P = new Node;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(Address &P) {
    delete P;
    P = nullptr;
}

// Menambah elemen pada TOP
void push(Stack &S, int x) {
    Address P = alokasi(x);
    P->next = S.Top;
    S.Top = P;
}

// Mengambil nilai TOP dan melepas node tersebut
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) return false;   // keadaan stack tidak berubah
    Address P = S.Top;
    x = P->info;
    S.Top = P->next;
    dealokasi(P);
    return true;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP: ";
    for (Address P = S.Top; P != nullptr; P = P->next) {
        cout << P->info << " ";
    }
    cout << endl;
}

// Urutan menaik dari bawah ke TOP (nilai terbesar di TOP).
// 1. Pindahkan elemen yang lebih besar dari x ke stack bantu (pop -> push).
// 2. Push x ke stack utama.
// 3. Kembalikan seluruh elemen dari stack bantu ke stack utama.
// Duplikat disimpan sebagai elemen terpisah (pemindahan hanya jika info > x).
void pushAscending(Stack &S, int x) {
    Stack bantu;
    createStack(bantu);
    int y;

    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, y);
        push(bantu, y);
    }
    push(S, x);
    while (pop(bantu, y)) {
        push(S, y);
    }
    // stack bantu kosong kembali (Top = nullptr)
}

// Melepas seluruh node dan mengembalikan Top menjadi nullptr
void clearStack(Stack &S) {
    int x;
    while (pop(S, x)) {
    }
    S.Top = nullptr;
}
