# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori
Tipe Data menentukan apakah sebuah nilai dapat memiliki data atau tidak,serta operasi apa saja yang dapat dilakukan pada data tersebut. dalam pengubah (variabel) yang akan digunakan dalam program harus ditentukan tipe datanya.[1].
bahasa-bahasa pemograman membedakan tujuannya agar operasi-operasi data menjadi lebih efesien dan efektif. didalamnya  menyediakan empat macam tipe data dasar yaitu tipe data integer, floanting-point, doubel-precision, dan karakter. char dapat di kombinasikan dengan signed, unsigned, long dan short.[2].

pada umumnya dalam setiap bahsa pemograman obyek terdapat tiga level tipe data, yaitu:
1. Tipe data Primitf
2. Tipe data abstrak (obyek)
3. Tipe data collection.


#Tipe Data Primitf 
tipe data dasar bahasa pemograman dijadikan standar bahasa pemograman tertentu.memiliki tipe data  dasar pada bahasa pemograman C.

a. Integer:bilangan bulat yang ditulis dalam bentuk desimal, hexadesimal maupun oktal. (-2,147,483,648 + 2,147,483.647).[2].

b. Floating point: tipe bilangan desimal, tipe data bilangan yang mengandung angka dibelakang koma, misalnya 3.16, 21.5, dll. [2].

c. Booleans: tipe logika data -data hanya mengandung dua buah nilai, yaitu boleaan yang terdiri dari nilai benar ( dipresentasikan dengan nilai 1) dan nilai salah (dipresentasikan dengan nilai 0)..[1].

d. tipe karakter /string 
tipe data yang berupa karakter, string dinatakan dengan pointer dari tipe char. char: singkatan dari character dan digunakan untuk menyimpan satu karakter Unicode seperti 'A', '%', '@' dan 'p' ..

#Tipe Data Abstrak
Tipe data obyek mulai digunakan pada pemograman prosedural pasal ataupun C dengan penggunaan tipe data abstrack dan pointer, yaitu record, struct untuk tipe data kelompok serta pointer untuk penciptaan tipe data dinamis. pada perkembanganya untuk tipe data obyek dimulai pada bahsa pemograman LISP dan kemudian disusul Java.  sedangkan pada java menggunakan Class dimana obyek tidak hanya atribut variabel.

#Tipe Data Koleksi
Tipe data koleksi adalah struktur data yang digunakan untuk menyimpan sekumpulan data yang memiliki tipe data sama atau berbeda. tipe data ini memungkinkan progammer mengakses dengan mudah.

a. Array : kumpulan nilai data yang tersuktur dan merujuk kepada sebuah elemen yang mempunyai tipe data yang sama melalui indeks.[2]
b. Vector : nilai dari array. jumlah semua elemen (count) bukan sum nilai yang ada didalam vektor.
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

program kodingan tipe data primitif menggunakan tipe float dan tipe double untuk menyimpan harga buah. menampilakn dua varibel hargaapel dan hargamangga. menghitung harga 5kg apel dan 2kg mangga, menampilan haslnya menggunakan cout. Program ini menunjukkan perbedaan penggunaan tipe data float dan double. Tipe data double memiliki presisi yang lebih tinggi dibandingkan dengan float untuk menyimpan nilai desimal.

### B. 
```C++
#include <iostream>

using namespace std;

// Deklarasi fungsi untuk menghitung total harga buah
float hitungTotalHargaBuah(float hargaBuah, int jumlahBuah) {
  return hargaBuah * jumlahBuah;
}

int main() {
  // Deklarasi variabel
  float hargaApel = 7000.0f; // Harga apel per kg
  int jumlahApel = 5; // Jumlah apel yang dibeli

  // Menghitung total harga apel
  float totalHargaApel = hitungTotalHargaBuah(hargaApel, jumlahApel);

  // Menampilkan total harga
  cout << "Total harga " << jumlahApel << " kg apel: Rp" << totalHargaApel << endl;

  return 0;
}
```
### Output :
![kodingan1](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/86db6700-5aae-4fdd-b0e3-41854206f78d)

secara pisah 
### B.
```C++
#include <iostream>

using namespace std;

// Deklarasi fungsi untuk menghitung total harga buah
double hitungTotalHargaBuah(double hargaBuah, int jumlahBuah) {
  return hargaBuah * jumlahBuah;
}

int main() {
  // Deklarasi variabel
  double hargaMangga = 14000.0; // Harga mangga per kg
  int jumlahMangga = 2; // Jumlah mangga yang dibeli

  // Menghitung total harga mangga
  double totalHargaMangga = hitungTotalHargaBuah(hargaMangga, jumlahMangga);

  // Menampilkan total harga
  cout << "Total harga " << jumlahMangga << " kg mangga: Rp" << totalHargaMangga << endl;

  return 0;
}
```
### output :
![kodingan2](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/8cbc13ed-538d-4184-9ed6-1f8e0c83a881)
berdasarkan kodingan pertama meggunakan float untuk harga dan total harga apel. sedangkan kodingan kedua menggunakan doubel untuk harga dan total harga mangga. float memiliki presesi 7 digit dan doubel memiliki presesi 15 digit. float nilai tidak terlalu besar, sedangkan doubel nilai lebih besar. untuk menghitung fungsi hitungtotalhargabuah.

### 2. soal 
Jelaskan fungsi dari class dan struct secara detail dan berikan contoh programnya
class :Class kita membutuhkan keyword class yang dilanjutkan dengan pemberian nama dari deklarasi class tersebut. lalu dilanjutkan dengan meletakan tanda { dan } untuk mengapit definisi dari class. Class termasuk sebuah pernyataan maka dari itu akhir dari deklarasi class diwajibkan untuk mengakhiri class menggunakan tanda titik-koma.Terdapat banyak fasilitas yang disediakan oleh class, yaitu dapat menampung member variabel, function, constructor, desctructor, overloading dan lain-lain. Diluar definisi class kita juga dimungkinkan untuk membuat relalasi seperti inheritance dan overriding.

struct: Struct adalah singkatan dari "structure". Dalam bahasa C, struct adalah sebuah tipe data terstruktur yang memungkinkan Anda untuk mengelompokkan data terkait bersama-sama.Menyimpan data kompleks seperti data mahasiswa, data buku, dll. Membangun struktur data yang lebih kompleks seperti linked list, tree, dll. Mempermudah pertukaran data antar modul program.
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
Kodingan tersebut mendefinisikan kelas Segitiga dengan dua atribut private (alas dan tinggi) dan dua metode publik (hitungLuas dan hitungKeliling).Fungsi main membuat objek Segitiga baru dengan alas 5.0 dan tinggi 6.0. Luas segitiga dihitung dengan memanggil metode hitungLuas.
Keliling segitiga dihitung dengan memanggil metode hitungKeliling.
Luas dan keliling segitiga dicetak ke konsol. Kodingan ini menunjukkan cara mendefinisikan kelas dengan atribut, metode, dan konstruktor.

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
map<string, string> mendeklarasikan map dengan key (nama) bertipe string dan value (alamat) bertipe string.Data mahasiswa ditambahkan ke map dengan map["key"] = value. Loop for digunakan untuk iterasi map dan menampilkan key dan value.find("key") digunakan untuk mencari data mahasiswa berdasarkan key (nama). Jika data ditemukan, value (alamat) ditampilkan. Jika data tidak ditemukan, pesan "Data mahasiswa dengan nama [nama] tidak ditemukan." ditampilkan. program dijalankan menggunakan map untuk menyimpan dan menampilan data mahasiswa. perbedaan dengan array , array menyimpan data dengan urutan tertentu dan ukuran array harus ditentukan. sedangakn map data tanpa urutan tertentu dan ukuran map dapat berubah.

## Kesimpulan
ipe data dalam bahasa c++ itu beragam dan sangat penting untuk menulis program yang efektif dan efesien. Memilih tipe data yang tepat dapat meningkatkan performa, skalabilitas, dan kemudahan penggunaan algoritma. Pemahaman yang baik tentang tipe data algoritma sangat penting untuk programmer dan ilmuwan komputer. 

## Referensi
[1] S. Esabella and M. Haq, Dasar-Dasar Pemrograman. Olat Maras Publishing, 2021.
[2] Buana, I. K. S., Setiawan, H., & Putro, P. a. W. (2021). Pemrograman terstruktur. Syiah Kuala University Press.
