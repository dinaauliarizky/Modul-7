#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);
    int pilih, x;

    do {
        cout << "\n=== MENU STACK (POINTER, TERURUT) ===" << endl;
        cout << "1. Tambah Terurut" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilih)) break;

        switch (pilih) {
        case 1:
            cout << "Masukkan bilangan: ";
            cin >> x;
            pushAscending(S, x);
            cout << x << " berhasil ditambahkan secara terurut." << endl;
            break;
        case 2:
            if (pop(S, x))
                cout << "Nilai yang di-Pop: " << x << endl;
            else
                cout << "Pop ditolak: stack kosong." << endl;
            break;
        case 3:
            printInfo(S);
            break;
        case 0:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilih != 0);

    clearStack(S);   // lepas semua node sebelum program berakhir
    return 0;
}
