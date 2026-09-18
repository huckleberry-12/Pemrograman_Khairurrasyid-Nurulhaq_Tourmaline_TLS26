#include <iostream>
using namespace std;

// Fungsi untuk menghapus elemen array
void hapusAstronaut(int astronaut[], int &jumlah, int posisi)
{
    for (int i = posisi; i < jumlah - 1; i++)
    {
        astronaut[i] = astronaut[i + 1];
    }

    jumlah--;
}

// Fungsi untuk menentukan posisi eliminasi
int cariPosisiEliminasi(int posisi, int K, int jumlah)
{
    return (posisi + K - 1) % jumlah;
}

// Fungsi utama proses eliminasi
void prosesEliminasi(int astronaut[], int jumlah)
{
    int K = 2;
    int posisi = 0;

    cout << "Urutan eliminasi: ";

    while (jumlah > 1)
    {
        // Cari posisi astronaut yang dieliminasi
        int posisiEliminasi =
            cariPosisiEliminasi(posisi, K, jumlah);

        // Simpan nomor astronaut
        int nomor = astronaut[posisiEliminasi];

        // Tampilkan astronaut yang dieliminasi
        cout << nomor;

        if (jumlah > 2)
        {
            cout << " ";
        }

        // Perubahan nilai K
        if (nomor % 2 == 0)
        {
            K = K + 2;
        }
        else
        {
            K = K - 1;
        }

        // K minimal adalah 2
        if (K < 2)
        {
            K = 2;
        }

        // Hapus astronaut
        hapusAstronaut(astronaut, jumlah, posisiEliminasi);

        // Perhitungan selanjutnya dimulai dari
        // astronaut setelah yang dieliminasi
        if (jumlah > 0)
        {
            posisi = posisiEliminasi % jumlah;
        }
    }

    cout << endl;
    cout << "Astronaut terakhir: " << astronaut[0] << endl;
}

int main()
{
    int N;

    cout << "Masukkan N: ";
    cin >> N;

    if (N < 1)
    {
        cout << "N harus lebih besar atau sama dengan 1." << endl;
        return 0;
    }

    // Array dengan ukuran maksimum N.
    // Menggunakan dynamic array agar sesuai dengan input N.
    int *astronaut = new int[N];

    // Mengisi nomor astronaut 1 sampai N
    for (int i = 0; i < N; i++)
    {
        astronaut[i] = i + 1;
    }

    prosesEliminasi(astronaut, N);

    delete[] astronaut;

    return 0;
}