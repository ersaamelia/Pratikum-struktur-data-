#include <iostream>
using namespace std;

struct buku {
    string Judul;
    string Penulis[5]; // Array of strings untuk menyimpan nama penulis (hingga 5 penulis)
    string genre[5]; // Array of strings untuk menyimpan genre (hingga 5 genre)
    int tahunTerbit[5]; // Array of integers untuk menyimpan tahun terbit (hingga 5 tahun)
    int harga;
    int halaman;
};

int main() {
    buku myBooks[5]; // Deklarasi array berisi 5 struct buku

    // Mengisi data untuk 5 buku
    myBooks[0].Judul = "Godfall";
    myBooks[0].Penulis[0] = "Jeph Loeb";
    myBooks[0].genre[0] = "Superhero";
    myBooks[0].tahunTerbit[0] = 2004;
    myBooks[0].harga = 200000;
    myBooks[0].halaman = 112;


    myBooks[1].Judul = "Crush";
    myBooks[1].Penulis[0] = "Josephine Abigail";
    myBooks[1].genre[0] = "Romantis";
    myBooks[1].tahunTerbit[0] = 2020;
    myBooks[1].harga = 89100;
    myBooks[1].halaman = 360;


    myBooks[2].Judul = "Cuan Trading Pakai Fibonacci";
    myBooks[2].Penulis[0] = "Catherine Wiliam";
    myBooks[2].genre[0] = "Investasi";
    myBooks[2].tahunTerbit[0] = 2022;
    myBooks[2].harga = 70400;
    myBooks[2].halaman = 104;


    myBooks[3].Judul = "Matahari";
    myBooks[3].Penulis[0] = "Tere Liye";
    myBooks[3].genre[0] = "Fiksi";
    myBooks[3].tahunTerbit[0] = 2022;
    myBooks[3].harga = 85500;
    myBooks[3].halaman = 400;


    myBooks[4].Judul = "The Power of Sun Tzu";
    myBooks[4].Penulis[0] = "Kai Tan";
    myBooks[4].genre[0] = "Filsafat";
    myBooks[4].tahunTerbit[0] = 2024;
    myBooks[4].harga = 58500;
    myBooks[4].halaman = 200;

    cout << "\t\tDaftar Buku" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "\tBuku " << i + 1 << ":" << endl;
        cout << "\tJudul: " << myBooks[i].Judul << endl;
        cout << "\tPenulis: ";
        for (int j = 0; j < 1; j++) { // Hanya menampilkan penulis pertama
            cout << myBooks[i].Penulis[j] << " ";
        }
        cout << endl;
        cout << "\tGenre: " << myBooks[i].genre[0] << endl; // Hanya menampilkan genre pertama
        cout << "\tTahun Terbit: " << myBooks[i].tahunTerbit[0] << endl; // Hanya menampilkan tahun terbit pertama
        cout << "\tHarga: " << myBooks[i].harga << endl;
        cout << "\tHalaman: " << myBooks[i].halaman << endl;
    }

    return 0;
}
unguided 1