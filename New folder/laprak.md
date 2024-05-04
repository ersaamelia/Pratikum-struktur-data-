# <h1 align="center">Laporan Praktikum Modul Struct dan Implementasi</h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori
Variabel 

suatu lokasi dimemori yang diberi nama khas untuk menampung suatu data atau mengambil kembali nilai tersebut. dalam deklarasinya dibuat bersamaan dengan tipe data. tipe variabel ditentukan oleh jenis data yang akan disimpan. [1].

tipe data variabel artinya harus menentukan batasan nilai variabel tersebut dan jenis operasi yang bisa dikenakan padanya. karena masing-masing tipe data memiliki batasan nili dan jenis operasi yang berbeda -beda.[1].

Tipe dasar ini digolongkan ke dalam tipe bilangan bulat (integer), bilangan
riil (floating-point), tipe logika (boolean), tipe karakter/teks (character/string).[2].

Struct

Tipe data bentukan yaitu tipe data yang dibuat sendiri sesuai kebutuhan
dalam program yang akan kita buat. Dalam bahasa latin sering disebut user defined
types. Adapun yang termasuk dalam kategori tipe bentukan ini adalah array
(larik), struktur dan enumerasi.
Struktur Yaitu tipe data bentukan yang menyimpan lebih dari satu variabel
bertipe sama maupun berbeda. Berikut bentuk umum pendeklerasian tipe
data struktur dalam bahasa C++.[2].
~~~C++
Struct nama_struktur {
tipe_data variabel1;
tipr_data variabel2;
........
}
~~~ 
contoh program
~~~C++
#include <iostream>
using namespace std;
int main() {
struct MAHASISWA {
char NIM[11];
char Nama[25];
char Alamat[20];
char Kota[15];
};
MAHASISWA A; // Mendeklarasikan variabel A yang
// bertipe MAHASISWA
A.NIM = "07501241026";
A.Nama = "Hasbu";
A.Alamat = "Demangan";
A.Kota = "Yogyakarta";
// Menampilkan nilai yang diisikan ke layar
cout<<A.NIM<<endl;
cout<<A.Nama<<endl;
cout<<A.Alamat<<endl;
cout<<A.Kota<<endl;
return 0;
}
~~~

### Guided
### 1. 

~~~C++
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
    // Mendeklarasikan variabel favorit dengan tipe buku
    buku favorit;

    // Mengisi data ke dalam variabel favorit
    favorit.judulBuku = "The Alpha Girl's Guide";
    favorit.pengarang = "Henry Manampiring";
    favorit.penerbit = "Gagas Media";
    favorit.tebalHalaman = 253;
    favorit.hargaBuku = 79000;

    // Menampilkan informasi buku favorit
    cout << "\tBuku Favorit Saya" << endl;
    cout << "\tJudul Buku : " << favorit.judulBuku << endl;
    cout << "\tPengarang : " << favorit.pengarang << endl;
    cout << "\tPenerbit : " << favorit.penerbit << endl;
    cout << "\tTebal Halaman: " << favorit.tebalHalaman << " halaman" << endl;
    cout << "\tHarga Buku : Rp " << favorit.hargaBuku << endl;
 
    return 0;
}

~~~
### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/c6c9834f-ebd5-4087-b1fb-e149d3e7f8fc)

### interprestasi:
kodingan ini menyertakan header iostream untuk menginput dan output. mendefinisikan struktur buku dengan lima anggota mencakup judulbuku, pengarang, penerbit, tebalhalaman, dan harga. variabel favorit dnegan tipe buku untuk menyimpan data yang sama seperti struktur buku. cout digunakan untuk mencetak hasil dan variabel favorit yang dapat diakses. return 0 untuk mengembalikan nilai 0 ke sistem operasi dengan menandakan program telah selesai dnegan sukses.
### 2. 

~~~C++
#include <iostream>
using namespace std;

struct hewan {
    string namaHewan;
    string jenisKelamin;
    string caraBerkembangbiak;
    string alatPernafasan;
    string tempatHidup;
    bool Karnivora;
};

struct hewanDarat {
    int jumlahKaki;
    bool menyusui;
    string suara;
};

struct hewanLaut {
    string bentukSirip;
    string bentukPertahananDiri;
};

int main() {
    hewanDarat kelinci; // Menggunakan tipe data hewanDarat untuk kelinci
    kelinci.jumlahKaki = 4;
    kelinci.menyusui = true;
    kelinci.suara = "Citcit";

    hewanLaut ikan; // Menggunakan tipe data hewanLaut untuk ikan
    ikan.bentukSirip = "Sirip ekor";
    ikan.bentukPertahananDiri = "Sisik";

    hewan serigala; // Tetap menggunakan tipe data hewan untuk serigala
    serigala.namaHewan = "Serigala";
    serigala.jenisKelamin = "Jantan";
    serigala.caraBerkembangbiak = "Melahirkan";
    serigala.alatPernafasan = "Paru-paru";
    serigala.tempatHidup = "Hutan terbuka";
    serigala.Karnivora = true;

    cout << "\t\tHewan" << endl;
    cout << "\t" << serigala.namaHewan << endl;
    cout << "\tJenis kelamin : " << serigala.jenisKelamin << endl;
    cout << "\tCara berkembangbiak : " << serigala.caraBerkembangbiak << endl;
    cout << "\tAlat pernafasan : " << serigala.alatPernafasan << endl;
    cout << "\tTempat hidup : " << serigala.tempatHidup << endl;
    cout << "\tKarnivora : " << (serigala.Karnivora ? "Yes" : "No") << endl << endl;

    cout << "\t\tHewan Darat" << endl;
    cout << "\tKelinci" << endl;
    cout << "\tJumlah kaki : " << kelinci.jumlahKaki << endl;
    cout << "\tMenyusui : " << (kelinci.menyusui ? "Yes" : "No") << endl;
    cout << "\tSuara : " << kelinci.suara << endl << endl;

    cout << "\t\tHewan Laut" << endl;
    cout << "\tIkan" << endl;
    cout << "\tBentuk sirip : " << ikan.bentukSirip << endl;
    cout << "\tBentuk pertahanan diri: " << ikan.bentukPertahananDiri << endl;

    return 0;
}
~~~
#### Output:
![Cuplikan layar 2024-04-26 184043](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/fefe3afe-d1f9-4d58-ac71-b19dc28c46f9)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/6df11417-5b14-4d69-8384-43e55917ab45)

#### Interprestasi:
kode ini menggunakan tiga struktur data untuk mewakili informasi hewan. pertama hewan dengan mendiskripsikan struktur data untuk hewan dengan mencakup nama, jenis kelamin , cara berkembang biak, alat pernafasan, tempat hidup dan status karnivora atau bukan. kedua hewan darat mendiskripsikan struktur data khusus untuk hewan darat, mencakup jumlah kaki, kemampuan menyusui dan suara yang dihasilkan. ketiga hewanlaut mendiskripsikan struktur data khusus untuk hewan laut mencakup bentuk sirip dan bentuk pertahanan diri. kelinci (kelinci) dibuat sebagai struct hewanDarat. Field spesifiknya seperti jumlahKaki (diisi 4), menyusui (diisi True), dan suara (diisi "Citcit") diberi nilai.
ikan (ikan) dibuat sebagai struct hewanLaut. Field spesifiknya seperti bentukSirip (diisi "Sirip ekor") dan bentukPertahananDiri (diisi "Sisik") diberi nilai.
serigala (serigala) dibuat sebagai struct hewan (bukan hewanDarat atau hewanLaut ). Field-nya diisi dengan informasi yang sesuai mengenai serigala.
 

## Unguided 

### 1.  [Modifikasi tugas guided pertama, sehingga setiap item yang terdapat pada struct buku berupa array yang berukuran 5, isi dengan data kemudian tampilkan]

~~~C++
#include <iostream>
using namespace std;

struct buku {
    string Judul;
    string Penulis[5]; 
    string genre[5]; 
    int tahunTerbit[5]; 
    int harga;
    int halaman;
};

int main() {
    buku myBooks[5]; 

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
        for (int j = 0; j < 1; j++) { 
            cout << myBooks[i].Penulis[j] << " ";
        }
        cout << endl;
        cout << "\tGenre: " << myBooks[i].genre[0] << endl; 
        cout << "\tTahun Terbit: " << myBooks[i].tahunTerbit[0] << endl; 
        cout << "\tHarga: " << myBooks[i].harga << endl;
        cout << "\tHalaman: " << myBooks[i].halaman << endl;
    }

    return 0;
}

~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/be9ba73f-8df6-483d-bfdb-8056340c4144)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/de9feca1-e9c6-448f-94f9-43901383f80b)

#### Interprestasikan:
struct buku untuk menyimpan informasi buku, termasuk judul, penulis, genre, tahun terbit, dan jumlah halaman. array mybooks menjadi bertipe buku yang dapat menyimpan informasi untuk 5 buku berbeda. Looping bagian dalam (for (int j = 0; j < 1; j++)) saat ini hanya menampilkan penulis pertama. Anda dapat memodifikasi loop ini menjadi for (int j = 0; j < 5; j++) untuk menampilkan semua penulis yang tersimpan di array Penulis.  informasi genre, tahunTerbit, harga, dan halaman menggunakan indeks i untuk mengakses elemen array yang sesuai. return 0  ke sistem operasi, menandakan bahwa program telah selesai dengan sukses.
### 2.  [Apa yang terjadi jika deklarasi variabel struct yang dibuat pada tugas guided I,berjenis Array. Bagaimana cara mengisi data dan menampilkannya ?]

~~~C++
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

~~~

#### Output:
![Cuplikan layar 2024-04-26 213557](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/2138a4a1-0b42-4c09-af7c-494a10863f44)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/2cc7f601-4a25-4ee8-b4e4-81cf09d284f1)

#### Interprestasikan: 
 Bagian ini mengisi data untuk 3 buku ke dalam array favoritBuku. Setiap elemen array (buku) diakses menggunakan indeks array (misalnya favoritBuku[0] untuk buku pertama). Anda mengakses anggota struct menggunakan titik (.).Bagian ini menampilkan informasi buku dari array favoritBuku menggunakan loop for. Loop ini diulang 3 kali, sesuai dengan jumlah elemen dalam array. Di dalam loop, informasi setiap buku (judul, pengarang, penerbit, tebal halaman, dan harga) dicetak ke layar. Kodingan fungsi loop for memungkinkan program untuk mengulang operasi pengisian dan menampilkan data untuk setiap buku dalam array.kodingan  menggunakan spasi dan tabulasi untuk menyusun output agar lebih mudah dibaca dan terstruktur.
 
#### Kesimpulan:
Variabel dan tipe data penting untuk mengatur dan mengolah data dalam program.
Tipe data menentukan jenis data yang dapat disimpan dan operasi yang dapat dilakukan.
Struktur memungkinkan pengelompokan data terkait dengan lebih rapi dan terorganisir.

### Referensi :
[1].S. Esabella and M. Haq, Dasar-Dasar Pemrograman. Olat Maras Publishing, 2021: 15-16.

[2]. Robbi Rohim. 2005. Perkembangan C++. Modul Pemrograman C++. STMIK
Amikom ,hal : 11-15.