# <h1 align="center">Laporan Praktikum Modul Array</h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori
Array merupakan kumpulan nilai-nilai data yang terstruktur dan merujuk kepada sebuah atau sekumpulan elemen yang mempunyai tipe data yang sama melalui indeks. array disebut juga sebagai tabel, vektor atau larik. elemen dari array dapat diakses langsung jika dan hanya jika indeks terdefinisi . struktur data array disimpan dengan urutan yang sesuai dengan definisi indeks secara kontinu dalam memori komputer. karena itu indeks haruslah merupakan suatu tipe data yang memiliki ketururutan , misal tipe integer dan karakter.[1]  

Dapat dilihat array dapat dibagi menjadi Array Satu Dimensi, Array Dua Dimensi dan Array Multi-Dimensi.[1]

1. Array Satu Dimensi 
array satu dimensi bertipe integer dengan 5 elemen yang diberi nomor indeks dari 0 sampai 4. array setiap elemen diberi sebutan nama yang berbeda dengan memberikan nomor indeks, sehingga masig-masing menjadi A[0], A[1], A[2], A[3], dan A[4]. [1]
bentuk umum penulisan array satu dimensi : 
Tipe_array nama_array[ukuran];

2. Array Dua Dimensi 
Array dua dimensi merupakan array yang terdiri dari m buah baris (row) dan n buah kolom (column). Bentuk array semacam ini menggunakan 2 buah kelompok indeks yang masing-masing dipresentasikan sebagai indeks baris dan kolom. jika ingin memasukkan atau membaca sebuah nilai pada matriks maka, harus diketahui terlebih dahulu indeks baris dan kolomnya.[1]
Bentuk umum: 
tipedata nama_array[baris][kolom];
mengakses nilai array dapat dilakukan dengan cara manual dimana kita langsung mengecetak sesui dengan indeks baris dan kolom pada array tersebut. [1]

3. Array Multi Dimensi
menggambarkan array multidimensi, hanya terbatas hingga dimensi ke-3, yakni dengan menggunakan bangun ruang, namun dalam kenyataannya tipe data array ini dapat dibentuk menjadi lebih dari tiga dimensi.[1]

## Guided 

### 1. [Input Data Array 3 Dimensi]
~~~
C++
#include <iostream>
using namespace std;
// PROGRAM INPUT ARRAY 3 DIMENSI
int main()
{
  // Deklarasi array
  int arr[2][3][3];
  // Input elemen
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << "Input Array[" << x << "][" << y << "][" << z << "] = ";
        cin >> arr[x][y][z];
      }
    }
    cout << endl;
  }
  // Output Array
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << "Data Array[" << x << "][" << y << "][" << z << "] = " << arr[x][y][z] << endl;
      }
    }
  }
  cout << endl;
  // Tampilan array
  for (int x = 0; x < 2; x++)
  {
    for (int y = 0; y < 3; y++)
    {
      for (int z = 0; z < 3; z++)
      {
        cout << arr[x][y][z] << ends;
      }
      cout << endl;
    }
    cout << endl;
  }
}
~~~
#### Output:
<img width="960" alt="Cuplikan layar 2024-03-21 203336" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/f9272c2a-53ff-4776-a32b-052cf40305c3">
<img width="960" alt="Cuplikan layar 2024-03-21 203354" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/4132dc2a-395a-44ca-83f0-20d8cffafbb6">

### Interprestasi:
Baris pertama menyertakan pustaka <iostream> yang menyediakan fungsi input/output standar seperti cout (untuk mencetak ke konsol) dan cin (untuk menerima input dari pengguna). Baris kedua menggunakan instruksi using namespace std; untuk menghindari penulisan std:: berulang-ulang di depan objek standar seperti cout dan cin. Array ini dapat menyimpan 2 "lapisan" (dimensi pertama), masing-masing berisi 3 baris (dimensi kedua), dan setiap baris memiliki 3 elemen integer (dimensi ketiga). Total ada 2 x 3 x 3 = 18 elemen integer yang dapat disimpan dalam array ini. input elemen for untuk memasukan nilai setiap elemen dan array. output for untuk  menampilkan nilai-nilai yang telah dimasukkan pengguna ke dalam array.

### 2. [Program Mencari Nilai Maksimal pada Array]
~~~C++
#include <iostream>
using namespace std;

int main()
{
    int maks, a, i = 1, lokasi;
    cout << "masukkan panjang array: ";
    cin >> a;
    int array[a];
    cout << "masukkan " << a << "angka\n";
    for (i = 0; i < a; i++)
    {
        cout << "array ke-" << (i) << ":";
        cin >> array [i];
    }
    maks = array[0];
    for (i =0; i <a; i++)
    {
        cout << "Array ke-" << (i) << ": ";
        cin >> array[i];
    }
    maks = array[0];
    for (i = 0; i < a; i++)
    {
        if (array[i] > maks)
        {
            maks = array[i];
            lokasi = i;
        }
    }
    cout << "nilai maksimum adalah " << maks << " berada di array ke" << lokasi << endl;
}
~~~
#### Output:
<img width="960" alt="Cuplikan layar 2024-03-21 204825" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/45e6b6c5-02b2-475f-a0ca-107e8cab4791">
### Interprestasi:
maks: integer untuk menyimpan nilai maksimum yang ditemukan dalam array.
(a) integer untuk menyimpan panjang array yang dimasukkan pengguna.
(i)counter loop yang diinisialisasi ke 1 (walaupun biasanya dimulai dari 0).Variabel maks diinisialisasi dengan nilai elemen pertama array (array[0]). Ini akan menjadi referensi awal untuk mencari nilai maksimum.
lokasi: integer untuk menyimpan indeks elemen dengan nilai maksimum.Loop for ketiga digunakan untuk iterasi melalui elemen array.Di dalam loop:Kondisi if memeriksa apakah elemen array saat ini (array[i]) lebih besar dari nilai maksimum yang disimpan di maks.Jika ya, maka: Nilai maksimum diperbarui dengan nilai elemen saat ini (maks = array[i]).
Indeks elemen maksimum disimpan di lokasi. memasukkan panjang array (jumlah elemen), memasukkan setiap elemen array, Menemukan nilai maksimum dalam array, Menampilkan indeks elemen dengan nilai maksimum.Baris kode yang diulang (meminta input array) dihapus. Inisialisasi maks diulang, di mana hanya satu inisialisasi yang diperlukan.Menghapus baris yang tidak perlu. Mengoptimalkan kode dengan mengurangi inisialisasi variabel.menampilkan nilai maksimum dan indeksnya dalam array yang dimasukkan.


## Unguided 

### 1. A [Soal]
Buatlah program untuk menampilkan Output seperti berikut dengan data yang
diinputkan oleh user!
~~~
C++
#include <iostream>

using namespace std;

int main() {
  int jumlahData;
  cout << "Masukkan jumlah data dalam array: ";
  cin >> jumlahData;

  int dataArray[jumlahData];
  cout << "Masukkan data untuk array (pisahkan dengan spasi): ";
  for (int i = 0; i < jumlahData; i++) {
    cin >> dataArray[i];
  }

  cout << "Data Array: ";
  for (int i = 0; i < jumlahData; i++) {
    cout << dataArray[i] << " ";
  }
  cout << endl;

  cout << "Bilangan Genap: ";
  for (int i = 0; i < jumlahData; i++) {
    if (dataArray[i] % 2 == 0) {
      cout << dataArray[i] << " ";
    }
  }
  cout << endl;

  cout << "Bilangan Ganjil: ";
  for (int i = 0; i < jumlahData; i++) {
    if (dataArray[i] % 2 == 1) {
      cout << dataArray[i] << " ";
    }
  }
  cout << endl;

  return 0;
} 
~~~
#### Output:
<img width="960" alt="Cuplikan layar 2024-03-22 185556" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/b9330fc4-92fc-4e39-bd5d-5a4277671474">

### interprestasi :
jumlahData: Variabel integer untuk menyimpan jumlah data yang akan dimasukkan pengguna.

dataArray: Array integer dengan ukuran jumlahData untuk menyimpan nilai-nilai data yang dimasukkan pengguna.
cout: Digunakan untuk menampilkan pesan "Data Array: ".

Loop for: Digunakan untuk iterasi melalui semua elemen array dataArray dan mencetak setiap elemennya.

Percabangan if: Digunakan untuk memeriksa apakah elemen array saat ini genap (dataArray[i] % 2 == 0) atau ganjil (dataArray[i] % 2 == 1).
Jika genap, elemen array dicetak setelah pesan "Bilangan Genap: ".

Jika ganjil, elemen array dicetak setelah pesan "Bilangan Ganjil:".

### Kesimpulan 
Membaca dan menyimpan data dari pengguna ke dalam array.
Menampilkan data array yang telah dimasukkan.
Menemukan dan menampilkan bilangan genap dan ganjil dalam array.

### 2. soal 
Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah
atau ukuran elemennya diinputkan oleh user!
~~~C++
#include <iostream>

using namespace std;

int main() {
  int panjang, lebar, tinggi;

  // Meminta input dimensi array
  cout << "Masukkan panjang array: ";
  cin >> panjang;
  cout << "Masukkan lebar array: ";
  cin >> lebar;
  cout << "Masukkan tinggi array: ";
  cin >> tinggi;

  // Deklarasi array 3 dimensi
  int array3D[panjang][lebar][tinggi];

  // Input nilai elemen array
  for (int i = 0; i < panjang; i++) {
    for (int j = 0; j < lebar; j++) {
      for (int k = 0; k < tinggi; k++) {
        cout << "Masukkan nilai array[" << i << "][" << j << "][" << k << "]: ";
        cin >> array3D[i][j][k];
      }
    }
  }

  // Menampilkan nilai elemen array
  cout << "Nilai elemen array:" << endl;
  for (int i = 0; i < panjang; i++) {
    for (int j = 0; j < lebar; j++) {
      for (int k = 0; k < tinggi; k++) {
        cout << array3D[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  return 0;
}
~~~
### output:
<img width="960" alt="Cuplikan layar 2024-03-22 200621" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/0e25b23d-838e-4274-bb1d-e35c8e267f6a">
<img width="960" alt="Cuplikan layar 2024-03-22 200558" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/ee4107ac-2efc-4de1-8938-6a5d55651852">

### interprestasi
panjang, lebar, dan tinggi: Variabel integer untuk menyimpan dimensi array 3 dimensi. array3D: Array 3 dimensi dengan tipe data integer dan dimensi panjang x lebar x tinggi untuk menyimpan nilai-nilai data yang dimasukkan pengguna. cout untuk menampilakan "Masukkan panjang array", "masukkan lebar array", dan "masukkan tinggi array". membaca input dari pengguna dan disimpan ke variabel panjang , lebar, dan tinggi. Membaca dimensi array 3 dimensi dari pengguna.
Membaca nilai-nilai data dari pengguna dan menyimpannya dalam array 3 dimensi.
Menampilkan semua nilai elemen array 3 dimensi.

### 3. soal
 Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai
rata – rata dari suatu array dengan input yang dimasukan oleh user!

~~~C++
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
  int panjang, lebar, tinggi;

  // Meminta input dimensi array
  cout << "Masukkan panjang array: ";
  cin >> panjang;
  cout << "Masukkan lebar array: ";
  cin >> lebar;
  cout << "Masukkan tinggi array: ";
  cin >> tinggi;

  // Deklarasi array 3 dimensi
  int array3D[panjang][lebar][tinggi];

  // Input nilai elemen array
  for (int i = 0; i < panjang; i++) {
    for (int j = 0; j < lebar; j++) {
      for (int k = 0; k < tinggi; k++) {
        cout << "Masukkan nilai array[" << i << "][" << j << "][" << k << "]: ";
        cin >> array3D[i][j][k];
      }
    }
  }

  // Menampilkan nilai elemen array
  cout << "Nilai elemen array:" << endl;
  for (int i = 0; i < panjang; i++) {
    for (int j = 0; j < lebar; j++) {
      for (int k = 0; k < tinggi; k++) {
        cout << setw(4) << array3D[i][j][k] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }

  // Deklarasi variabel untuk nilai maksimum, minimum, dan total
  int max = array3D[0][0][0], min = array3D[0][0][0], sum = 0;

  // Mencari nilai maksimum dan minimum
  for (int i = 0; i < panjang; i++) {
    for (int j = 0; j < lebar; j++) {
      for (int k = 0; k < tinggi; k++) {
        if (array3D[i][j][k] > max) {
          max = array3D[i][j][k];
        }
        if (array3D[i][j][k] < min) {
          min = array3D[i][j][k];
        }
        sum += array3D[i][j][k];
      }
    }
  }

  // Menghitung nilai rata-rata
  float avg = (float)sum / (panjang * lebar * tinggi);

  // Menampilkan menu
  int pilihan;
  do {
    cout << endl;
    cout << "Menu:" << endl;
    cout << "1. Tampilkan Nilai Maksimum" << endl;
    cout << "2. Tampilkan Nilai Minimum" << endl;
    cout << "3. Tampilkan Nilai Rata-rata" << endl;
    cout << "4. Keluar" << endl;
    cout << "Masukkan pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
      case 1:
        cout << "Nilai maksimum: " << max << endl;
        break;
      case 2:
        cout << "Nilai minimum: " << min << endl;
        break;
      case 3:
        cout << "Nilai rata-rata: " << fixed << setprecision(2) << avg << endl;
        break;
      case 4:
        cout << "Terima kasih saya cape!" << endl;
        break;
      default:
        cout << "Pilihan tidak valid!" << endl;
    }
  } while (pilihan != 4);

  return 0;
}
~~~
### ouput:
<img width="960" alt="Cuplikan layar 2024-03-22 192230" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/6842d737-08e4-4167-bffc-254ef0c0ae71">
<img width="960" alt="Cuplikan layar 2024-03-22 192257" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/b26dfef3-3b8a-4dba-a06e-017c26937411">

### Interprestasi 
cout digunakan untuk menampilkan "Nilai elemen array". loop for digunakan untuk iterasi melalui semua elemen. didalam loop nilai maksimum dan minimum diperbarui jika ada elemen yang lebih besar/kecil. total nilai semua elemen (sum) juga di hitung. switch digunakan untuk memproses pilihan :
1. menampilkan nialai maksimum.
2. menampilkan nilai minimum.
3. menampilkan nilai rata-rata dengan format 2 digit desimal. 
4. menampilkan pesan "Terima kasih saya cape!" dan keluar dari program. 

Mengoperasikan array 3 dimensi dalam C++.
Mencari nilai maksimum, minimum, dan rata-rata dari elemen array.
Membuat menu sederhana untuk menampilkan hasil.

## Kesimpulan
Array adalah struktur data yang serbaguna untuk menyimpan data yang terstruktur.
Dimensi array menentukan jumlah baris dan kolom data yang disimpan.
Array dapat digunakan untuk berbagai macam aplikasi, seperti menyimpan data siswa, tabel nilai, dan data penjualan.

## Referensi
[1] S. Esabella and M. Haq, Dasar-Dasar Pemrograman. Olat Maras Publishing, 2021:46-49.
