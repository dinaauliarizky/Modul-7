#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(Stack S) {
    return S.Top == 0;
}

bool isFull(Stack S) {
    return S.Top == MAKS;
}

bool push(Stack &S, int x) {
    if (isFull(S)) return false;   // tidak mengubah isi maupun Top
    S.Top++;
    S.info[S.Top] = x;
    return true;
}

bool pop(Stack &S, int &x) {
    if (isEmpty(S)) return false;  // tidak mengubah isi maupun Top
    x = S.info[S.Top];
    S.Top--;
    return true;
}

void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP: ";
    for (int i = S.Top; i >= 1; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

// Membalik isi stack memakai SATU stack bantu, hanya lewat push dan pop.
// Tahap 1: pindahkan seluruh isi S ke bantu (urutan di bantu sudah = urutan hasil).
// Tahap 2: kembalikan ke S TANPA membalik urutan. Karena hanya ada satu stack
//          bantu, S sendiri dipakai sebagai tempat parkir sementara:
//          elemen dasar bantu diambil satu per satu (variabel x).
void balikStack(Stack &S) {
    Stack bantu;
    createStack(bantu);
    int x, y, n = 0;

    while (pop(S, x)) {
        push(bantu, x);
        n++;
    }

    for (int sisa = n; sisa >= 1; sisa--) {
        for (int i = 0; i < sisa - 1; i++) {   // parkir elemen di atas dasar ke S
            pop(bantu, y);
            push(S, y);
        }
        pop(bantu, x);                          // x = elemen dasar bantu
        for (int i = 0; i < sisa - 1; i++) {   // kembalikan parkiran ke bantu
            pop(S, y);
            push(bantu, y);
        }
        push(S, x);                             // x menempati posisi berikutnya di S
    }
}
