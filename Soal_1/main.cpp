#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack S;
    createStack(S);
    int pilih, x;

    do {
        cout << "\n=== MENU STACK (ARRAY) ===" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Balik Stack" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";
        if (!(cin >> pilih)) break;

        switch (pilih) {
        case 1:
            cout << "Masukkan bilangan: ";
            cin >> x;
            if (push(S, x))
                cout << x << " berhasil di-Push." << endl;
            else
                cout << "Push ditolak: stack penuh (maks. 20 elemen)." << endl;
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
        case 4:
            balikStack(S);
            cout << "Stack berhasil dibalik." << endl;
            printInfo(S);
            break;
        case 0:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilih != 0);

    return 0;
}
