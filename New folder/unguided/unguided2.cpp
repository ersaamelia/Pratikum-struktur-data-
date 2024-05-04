#include <iostream>
using namespace std;

// Mendefinisikan struktur buku
struct buku {
    string judulBuku;
    string pengarang;
    string penerbit;
    int tebalHalaman;
    int hargaBuku;
};

int main() {
    // Mendeklarasikan array favoritBuku dengan tipe buku
    buku favoritBuku[3];

    // Mengisi data ke dalam array favoritBuku
    favoritBuku[0].judulBuku = "The Alpha Girl's Guide";
    favoritBuku[0].pengarang = "Henry Manampiring";
    favoritBuku[0].penerbit = "Gagas Media";
    favoritBuku[0].tebalHalaman = 253;
    favoritBuku[0].hargaBuku = 79000;

    favoritBuku[1].judulBuku = "The Hobbit";
    favoritBuku[1].pengarang = "J.R.R. Tolkien";
    favoritBuku[1].penerbit = "HarperCollins";
    favoritBuku[1].tebalHalaman = 304;
    favoritBuku[1].hargaBuku = 125000;

    favoritBuku[2].judulBuku = "The Great Gatsby";
    favoritBuku[2].pengarang = "F. Scott Fitzgerald";
    favoritBuku[2].penerbit = "Scribner";
    favoritBuku[2].tebalHalaman = 180;
    favoritBuku[2].hargaBuku = 95000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "\tBuku " << i+1 << endl;
        cout << "\tJudul Buku : " << favoritBuku[i].judulBuku << endl;
        cout << "\tPengarang : " << favoritBuku[i].pengarang << endl;
        cout << "\tPenerbit : " << favoritBuku[i].penerbit << endl;
        cout << "\tTebal Halaman: " << favoritBuku[i].tebalHalaman << " halaman" << endl;
        cout << "\tHarga Buku : Rp " << favoritBuku[i].hargaBuku << endl << endl;
    }

    return 0;
}
unguided 2