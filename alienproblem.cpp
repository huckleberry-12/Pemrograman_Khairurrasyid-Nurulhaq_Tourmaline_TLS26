#include <iostream>
using namespace std;

const int MAX_LEN = 1000;

char keAtas(char c) {
    // ubah huruf kecil jadi besar tanpa cctype
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

int posisi(char c) {
    c = keAtas(c);
    return c - 'A' + 1;   // A=1, B=2, ..., Z=26
}

char huruf(int nilai) {
    int n = (nilai - 1) % 26;
    if (n < 0) n += 26;   // jaga tetap positif
    return 'A' + n;
}

void encode(char pesan[], char hasil[], int panjang) {
    hasil[0] = keAtas(pesan[0]);   // huruf pertama tidak berubah
    for (int i = 1; i < panjang; i++) {
        int nilaiAsli = posisi(pesan[i]);
        int nilaiPrev = posisi(pesan[i - 1]);
        int nilaiBaru = ((nilaiAsli + nilaiPrev - 1) % 26) + 1;
        hasil[i] = huruf(nilaiBaru);
    }
    hasil[panjang] = '\0';   // akhiri string
}

int main() {
    char pesan[MAX_LEN];
    char hasil[MAX_LEN];

    cout << "Masukkan pesan: ";
    cin.getline(pesan, MAX_LEN);

    // hitung panjang string secara manual
    int panjang = 0;
    while (pesan[panjang] != '\0') {
        panjang++;
    }

    encode(pesan, hasil, panjang);

    cout << "Pesan ter-sandi: " << hasil << endl;

    return 0;
}
