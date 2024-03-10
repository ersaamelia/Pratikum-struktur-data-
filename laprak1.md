# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori

pada umumnya dalam setiap bahsa pemograman obyek terdapat tiga level tipe data, yaitu:
1. Tipe data Primitf
2. Tipe data abstrak (obyek)
3. Tipe data collection.

Tipe data Primitf 
tipe data primitif dikenal pada bahasa pemograman prosedural seperti: pasal, C, atau basic. dimana tipe data ini memiliki ukuran memori yang tetap dan pasti,diantarnya:

a. Integer: memegang angka dari -2.147.483.648 hingga 2.147.483.647. Contohnya termasuk 15, 407, -908, 6150.

b. Floating point: Float mengacu pada angka floating point, yang merupakan angka dengan tempat desimal seperti 12,43, 5,2 dan -9,12. float dapat menyimpan angka dari -3,4 x 1038 hingga +3,4 x 1038. Menggunakan penyimpanan 8 byte dan memiliki presisi sekitar 7 digit.

c. Booleans:  boolean dan hanya dapat menampung dua nilai: true dan false. Ini biasanya digunakan dalam pernyataan aliran kontrol.
d. char: singkatan dari character dan digunakan untuk menyimpan satu karakter Unicode seperti 'A', '%', '@' dan 'p' .

f. Doubel:angka floating point, tetapi dapat menyimpan rentang angka
yang jauh lebih luas. Ini dapat menyimpan angka dari (+/-)5,0 x 10-324 hingga (+/-)1,7 x 10308 dan memiliki presisi sekitar 15 hingga 16 digit. double adalah tipe data floating point default di C. 

Tipe Data Abstrak
Tipe data obyek mulai digunakan pada pemograman prosedural pasal ataupun C dengan penggunaan tipe data abstrack dan pointer, yaitu record, struct untuk tipe data kelompok serta pointer untuk penciptaan tipe data dinamis. pada perkembanganya untuk tipe data obyek dimulai pada bahsa pemograman LISP dan kemudian disusul Java.  sedangkan pada java menggunakan Class dimana obyek tidak hanya atribut variabel.

Tipe Data Koleksi
Tipe data koleksi adalah struktur data yang digunakan untuk menyimpan sekumpulan data yang memiliki tipe data sama atau berbeda. tipe data ini memungkinkan progammer mengakses dengan mudah.

a. Array : Array hanyalah kumpulan data yang biasanya terkait satu sama lain. Misalkan kita ingin
menyimpan usia 5 pengguna. Alih-alih menyimpannya sebagai user1Age, user2Age, user3Age,
user4Age dan user5Age, kita dapat menyimpannya sebagai array.
Sebuah array dapat dideklarasikan dan diinisialisasi sebagai berikut:
int[] userAge = {21, 22, 23, 24, 25

b. Vector : nilai dari array. jumlah semua elemn   (count) bukan sum nilai yang ada didalam vektor.

c. String :String adalah sepotong teks. Contoh string
adalah teks "Hello World". Untuk mendeklarasikan dan menginisialisasi variabel string, Anda menulis: string pesan = “Halo Dunia”;

d. Map: Menyimpan data dengan pasangan key-value.
Akses data menggunakan key. Contoh: map<string, int> m; m["key"] = 1; cout << m["key"];.

## Guided 

### 1. [Tipe Data Primitif]

```C++
#include <iostream>
using namespace std ;
// main program
main()
{
    char op;
    float num1, num2;
    //it allows user to enter operator i.e. +,-,*,/
    cout << "masukkan operator:";
    cin >> op;
    // It allow user to enter the operands
    cout << "masukkan angka 1 & 2";
    cin >> num1 >> num2;
    //switch statment begins 
    switch(op)
    {
    //if user enter +
    case '+':
            cout << num1 + num2;
            break;
    //if user enter -
    case '-':
            cout << num1 - num2;
            break;
    //if user enter *
    case '*':
        cout << num1 * num2;
        break;
    //if user enter /
    case '/':
        cout << num1 / num2;
        break;
    // if the operator is other than +, -, * or/,
    // eror massage will display
    defalut:
        cout << "eror! opearot is not correct";
    }// swicth statement ends
    return 0;
}
```
#### Output:
!<img width="960" alt="Cuplikan layar 2024-03-08 212859" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/9356597c-3d5e-4a09-961c-49c48d17a1aa">


bahwa fungsi iostream untuk input dan output data. fungsi main adalah tempat program di mulai. op bertipe char untuk menyimpan operator yang akan dimasukkan. num1 dan num2 untuk menyimpan dua angka yang akan dihitung. fungsi cout untuk menampilkan masukkan operator. switch digunakan untuk blok kode berdasarkan nilai dari varibel op. fungsi case untuk menangani operasi yang berbeda berdasarkan operator. fungsi defalut dieksekusi jika operator yang dimasukkan tidak sesuai.

### 2. [Tipe Data abstrak]
```C++
#include <stdio.h>

// struct
struct Mahasiswa
{
  const char *name;
  const char *addres;
  int age;
};

int main()
{
  // menggunakan struct
  struct Mahasiswa mhs1, mhs2;
  // mengisi nilai ke struct
  mhs1.name = "Dian";
  mhs1.addres = "Mataram";
  mhs1.age = 22;
  mhs2.name = "Bambang";
  mhs2.addres = "Surabaya";
  mhs2.age = 23;

  // mencetak list struct
  printf("## Mahasiswa 1 ##\n");
  printf("Name: %s\n", mhs1.name);
  printf("Alamat: %s\n", mhs1.addres);
  printf("Umur: %d\n",mhs1.age);
  printf("## Mahasiswa 2 ##\n");
  printf("Name: %s\n", mhs2.name);
  printf("Alamat: %s\n", mhs2.addres);
  printf("Umur: %d\n",mhs2.age);
  return 0;
}
```
#### Output:
!<img width="960" alt="Cuplikan layar 2024-03-08 231531" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/96db9f69-f94e-463e-807f-727f93fb3556">

fungsi stdio.h untuk input dan output data. struct mahasiswa untuk struktur dengan tiga anggota yang berisi nama, addres, age. struct mahasiswa mhs1, mhs2 untuk dua variabel bertipe. fungsi printf untuk mencetak tentang mhs1 dan mhs2 ke konsol.

### 3. [Tipe Data koleksi]
```C++
#include <iostream>
using namespace std;

int main()
{
    //deklarasi dan inisialisasi array
    int nilai[5];
    nilai[0] = 23;
    nilai[1] = 50;
    nilai[2] = 34;
    nilai[3] = 78;
    nilai[4] = 90;

    //mencetak array
    cout << "Isi array pertama :" << nilai[0] << endl;
    cout << "Isi array kedua :" << nilai[1] << endl;
    cout << "Isi array ketiga :" << nilai[2] << endl;
    cout << "Isi array keempat :" << nilai[3] << endl;
    cout << "Isi array kelima :" << nilai[4] << endl;
    return 0;
}
```
### Output:
!<img width="960" alt="Cuplikan layar 2024-03-08 231955" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/e537f552-d632-4d7b-a128-2330e3e80910">

kode ini menunjukkan cara menggunakan array untuk menyimpan sekumpulan data dengan tipe yang sama dengan menggunakan indeks.

## Unguided 

### 1. [Soal]
Buatlah program menggunakan tipe data primitif minimal dua fungsi dan bebas.
Menampilkan program, jelaskan program tersebut dan ambil kesimpulan dari
materi tipe data primitif!

```C++
#include <iostream>
using namespace std;

int main() {
  // Deklarasi variabel harga buah dengan tipe data float dan double
  float hargaApel = 7000;
  double hargaMangga = 14000;

  // Menampilkan nilai variabel harga buah
  cout << "Harga apel: Rp" << hargaApel << endl;
  cout << "Harga mangga: Rp" << hargaMangga << endl;

  // Menghitung total harga untuk 2 kg apel dan 3 kg mangga
  float totalApel = 5 * hargaApel;
  double totalMangga = 2 * hargaMangga;

  // Menampilkan total harga
  cout << "Total harga 5 kg apel: Rp" << totalApel << endl;
  cout << "Total harga 2 kg mangga: Rp" << totalMangga << endl;

  return 0;
}
   
```

#### Output:
<img width="960" alt="Cuplikan layar 2024-03-09 065605" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/fa1be6bc-d1ad-4c3a-b264-5799cb0930a4">

program kodingan tipe data primitif menggunakan tipe float dan tipe double untuk menyimpan harga buah. menampilakn dua varibel hargaapel dan hargamangga. menghitung harga 5kg apel dan 2kg mangga, menampilan haslnya menggunakan cout.
### kesimpulan 
Program ini menunjukkan perbedaan penggunaan tipe data float dan double. Tipe data double memiliki presisi yang lebih tinggi dibandingkan dengan float untuk menyimpan nilai desimal.


### 2. soal 
Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya

fungsi class sendiri untuk membuat objek yang lebih kompleks dengan banyak data dan fungsionalitas. class bersifat privat.
fungsi struct sendiri itu kumpulan variabel menjadi satu , anggotanya dapat diakses langsung dari luar struct. struct itu publik.
```C++
#include <stdio.h>

class Segitiga{
  private:
    float alas;
    float tinggi;

  public:
    Segitiga(float a, float t) {
      alas = a;
      tinggi = t;
    }

    float hitungLuas() {
      return (alas * tinggi)/2;
    }

    float hitungKeliling() {
      return 0.0;
    }
};

int main() {
  Segitiga s1(5.0, 6.0);

  printf("Luas: %.2f\n", s1.hitungLuas());
  printf("Keliling: %.2f\n", s1.hitungKeliling());

  return 0;
}
```

### output:
!<img width="960" alt="Cuplikan layar 2024-03-08 233638" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/abbc56e1-5dd1-445b-bfc7-3c2a18648215">
program menunjukkan cara membuat dan menggunakan objek dengan data dan metode terkait. fungsi class itu privat sedangkan struct itu publik.

### 3. soal
 Buat dan jelaskan program menggunakan fungsi map dan jelaskan perbedaan dari
array dengan map.
```C++
#include <iostream>
#include <map>

using namespace std;

int main() {
  // Deklarasi map untuk menyimpan data mahasiswa
  map<string, string> daftarMahasiswa;

  // Menambahkan data mahasiswa ke map
  daftarMahasiswa["Boboiboy"] = "Brebes";
  daftarMahasiswa["Gopal"] = "Purwokerto";
  daftarMahasiswa["Alysa"] = "Jakarta";
  daftarMahasiswa["Dohyun"] = "Korea";

  // Menampilkan data mahasiswa dari map
  for (auto it = daftarMahasiswa.begin(); it != daftarMahasiswa.end(); ++it) {
    cout << "Nama: " << it->first << endl;
    cout << "Alamat: " << it->second << endl;
  }

  // Mencari data mahasiswa berdasarkan nama
  auto it = daftarMahasiswa.find("Gopal");
  if (it != daftarMahasiswa.end()) {
    cout << "Gopal:" << it ->second << endl;
  } else {
    cout << "Data mahasiswa dengan nama Gopal tidak ditemukan." << endl;
  }

  return 0;
}
```
### ouput:
<img width="960" alt="Cuplikan layar 2024-03-09 071558" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/0f0acf9e-82af-42d3-891f-1b4357ea3476">
program dijalankan menggunakan map untuk menyimpan dan menampilan data mahasiswa. perbedaan dengan array , array menyimpan data dengan urutan tertentu dan ukuran array harus ditentukan. sedangakn map data tanpa urutan tertentu dan ukuran map dapat berubah.

## Kesimpulan
tipe data dalam bahasa c++ itu beragam dan sangat penting untuk menulis program yang efektif dan efesien.

## Referensi

[1] Putri, M. P., Barovih, G., Azdy, R. A., Yuniansyah, Y., Saputra, A., Sriyeni, Y., Rini, A., & Admojo, F. T. (2022, September 28). ALGORITMA DAN STRUKTUR DATA. 

[2] Buana, I. K. S., Setiawan, H., & Putro, P. a. W. (2021). Pemrograman terstruktur. Syiah Kuala University Press.

[3] Dachi, A. (n.d.). Struktur data dan algoritma. Scribd. https://id.scribd.com/presentation/434267206/Struktur-data-dan-algoritma.

[4] Tutorial Java OOP: Mengenal Class Abstrak dan Cara Pakainya. (2020, January 4). Petani Kode.

[5]Pemrograman C++ Untuk SMA/SMK dan Mahasiswa. (n.d.). Google Books. https://books.google.co.id/books?hl=id&lr=&id=LYdeDwAAQBAJ&oi=fnd&pg=PP2&dq=jurnal+tipe+data+map+pemrograman+algoritma+C%2B%2B+terbaru&ots=1Qmyvl8gHw&sig=RPQwMyVGS09ooVJucw_i-VPpLzw&redir_esc=y#v=onepage&q&f=false. 