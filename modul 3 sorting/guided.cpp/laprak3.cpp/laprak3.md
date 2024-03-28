# <h1 align="center">Laporan Praktikum Modul Sorting</h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori
pemograman sorting adalah proses mengantur sekumpulan objek menurut aturan atau susunan tertentu. urutan objek tersebut dapat menaik atau disebut juga ascending ( dari data kecil ke data lebih besar) ataupun menurun atau disebut dengan descending (dari data besar ke data kecil).[1]

Metode sorting ada 3, yaitu:
 1. Bubble sort/ pengurutan gelembung 
 2. Selection sort/ pengurutan maksimum-minimum 
 3. Insertion sort/ pengurutan sisipan. [1]

A.  Bubble Sort
Algoritma Bubble Sort adalah algoritma yang terinspirasi dari gelembung sabun yang berada pada permukaan air. Karena berat jenis gelembung sabun lebih ringan daripada berat jenis air, maka gelembung sabun akan terapung ke atas permukaan. Apabila kita menginginkan larik terurut naik, maka elemen larik yang paling kecil diapungkan ke atas melalui proses pertukaran atau bisa disebutkan bahwa arah perbandingan dilakukan dari belakang. 
59 20 56 90 3 40 14 78 3 -1
Jika data tersebut akan diurutkan dengan urutan menaik (ascending) menggunakan metode
Bubble Sort maka proses dan langkah penyelesaiannya pada tabel 1. [2]

B.  Selection Sort
merupakan metode pengurutan yang didasarkan pada pemilihan elemen maksimum - minimum tersebut dengan elemen terujung larik (elemen ujung kiri atau elemen ujung kanan). selanjutnya elemen terujung itu kita "isolasi" dan tidak diikuti sertakan pada proses selanjutnya. [1]

C. Insertion Sort 
merupakan metode pengurutan sisip  adalah metode pengurutan dengan cara menyisipkan elemen pada posisi yang tepat. pencarian posisi yang tepat dilakukan dengan pencarian beruntun. selama pencarian posisi yang tepat dilakukan pergeseran elemn larik. 

misal ada 6 kartu tersusun memiliki urutan 2, 8, 5, 3, 9, 4. 
dimulai dari index array ke 1 yang berati dimulai dari angka 8 setiap perulangan kita bandingkan angka disebelah kirinya hingga angka tersebut lebih besar daripada angka disebelah kirinya. disini angka 8 lebih besar daripada angka 2 jadi tidak ada perubahan. selanjutnya angka 3 lebih kecil dibandingkan 8 dan 5 tapi lebih besar dibandingkan 2, maka angka 3 akan bergeser 2 langkah ke kiri, sedangkan angka 5 dan 8 akan bergeser 1 langkah ke kanan dan seterusnya. [1] 
## Guided 

### 1. [Input algoritma Bubble Sort]

~~~C++
#include <iostream>
using namespace std;

void bubble_sort(double arr[], int length){
    bool not_sorted = true;
	int j=0;
    double tmp;

    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i = 0; i < length - j; i++){
            if (arr[i] > arr[i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }// end of if
        }//end of for loop
    }//end of while loop
}//end of buuble_sort

void print_array(double a [], int length) {

    for(int i=0; i<length; i++) {
        cout << a[i] << "\t";
    }
    cout << endl;
}
int main() {

    int length = 5;
    double a[] = {22.1, 15.3, 8.2, 33.21, 99.99};

    cout << "Urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);

    bubble_sort(a, length);

    cout << "\nUrutan bilangan setelah sorting: " << endl;
    print_array(a, length);
}
~~~

#### Output:
<img width="960" alt="Cuplikan layar 2024-03-26 204046" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/a72c0d5e-4b81-4a6a-9cab-bdb049cbe679">
<img width="960" alt="Cuplikan layar 2024-03-26 204151" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/a4cce921-eaf0-4cc8-bc14-eb9874293f9f">

### interprestasi
Fungsi insertion_sort melakukan perbandingan dan pergeseran elemen untuk menempatkan setiap elemen pada posisi yang benar. Fungsi print_array kemudian mencetak elemen array yang telah diurutkan ke konsol. pertama arr[] itu karakter yang ingin diurutkan, length itu Panjang array arr[], (i) itu Indeks loop luar untuk iterasi elemen array, (j) itu Indeks loop dalam untuk perbandingan dan pergeseran elemen dan tmp itu Variabel temporary untuk menyimpan nilai selama pertukaran. pengrurutan Loop for luar  iterasi dari elemen kedua (i = 1) hingga elemen terakhir (i < length). didalam loop for luar j diinisialisasi dengan nilai i .Loop while  melakukan pergeseran elemen ke kiri. j belum mencapai elemen pertama (j > 0) dan elemen sebelumnya lebih kecil (arr[j - 1] < arr[j]). 

### Kesimpulan:
bubble sort salah satu algortma sederhana efektif untuk jumlah yang kecil. komplexity waktu O(n^2) dimana n adalah jumlah elemen dalam array. untuk jumlah data yang besar, bubble sort mungkin tidak menjadi pilihan yang efesien. 

### 2. [Algoritma Insertion sort]

~~~C++
#include <iostream>
using namespace std;

void insertion_sort(char arr[], int length){
    int i, j;
    char tmp;

    for (i = 1; i < length; i++) {
        j = i;

        while (j > 0 && arr[j - 1] < arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j -1] = tmp;
            j--;
        }//end of while loop
    }// end of for loop
}

void print_array(char a[], int length) {

    for(int i=0; i<length; i++){
        cout << a[i] << "\t";
    }
    cout << endl;
}

int main (){

    int length = 6;
    char a[length] = {'c', 'f', 'a', 'z', 'd', 'p'};

    cout << "Urutan karakter sebelum sorting: " << endl;
    print_array(a, length);

    insertion_sort(a, length);

    cout << "\nUrutan karakter setelah sorting: " << endl;
    print_array(a, length);

}
~~~

#### Output:
<img width="960" alt="Cuplikan layar 2024-03-26 201407" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/9ee7e0d5-4245-4fed-82ce-7ec742343503">
<img width="960" alt="Cuplikan layar 2024-03-26 202055" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/39f6bd71-9805-4f01-9f2a-422b15b57b97">

### interprestasi:
dalam kodingan ini karakter - krakter dalam array diurutkan secara descending yakni dari nilai yang terbesar ke nilai yang terkecil. while(j > 0 && arr[j - 1] < arr[j]) dimana elemen sebelumnya lebih kecil maka pertukaran dilakukan. Penggunaan fungsi terpisah seperti insertion_sort() dan print_array() meningkatkan keterbacaan dan modularitas kodingan.
Kompleksitas Waktu Algoritma insertion sort memiliki kompleksitas waktu O(n^2), di mana n adalah jumlah elemen dalam array. Ini karena dalam setiap iterasi, algoritma harus membandingkan elemen-elemen dan memindahkannya ke posisi yang sesuai.
## Unguided 

### 1.  [Soal]
Kelas S1 IF 2016 G memiliki 5 mahasiswa. Pada akhir semester mereka menerima
lembar Indeks Prestasi Semester (IPS), masing-masing mahasiswa tersebut memiliki IPS
sebagai berikut: {3.8, 2.9, 3.3, 4.0, 2.4}. Buatlah program untuk mengurutkan IPS
mahasiswa tersebut dari yang terbesar hingga terkecil dengan menggunakan algoritma
Selection Sort! 

~~~C++
#include <iostream>
using namespace std;

void selectSort(float arr[], int n) {
    int pos_min;
    float temp;
    for (int i = 0; i < n - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[pos_min])
                pos_min = j;
        }
        if (pos_min != i) {
            temp = arr[i];
            arr[i] = arr[pos_min];
            arr[pos_min] = temp;
        }
    }
}

int main() {
    int Mahasiswa= 5;
    float IPS[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    

    cout << "IPS sebelum diurutkan: ";
    for (int i = 0; i < Mahasiswa; i++) {
        cout << IPS[i] << " ";
    }

    selectSort(IPS, Mahasiswa);

    cout << "\nIPS setelah diurutkan dari terbesar ke terkecil: ";
    for (int i = 0; i < Mahasiswa; i++) {
        cout << IPS[i] << " ";
    }
}
~~~

#### Output:
<img width="960" alt="Cuplikan layar 2024-03-27 223511" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/f936e0d4-3807-4a01-bae7-4e60f081c616">

### interprestasi :
 fungsi include <iostream> untuk menyediakan input/output data dan using namespace std tidak perlu std::. fungsi selectsort menerima arr dan n untuk ukuran array. variabel pos_min sebagai integr untuk menyimpan indeks elemen dengan nilai minimum sementara dan temp untuk menyimpan nilai. looping for menjalankan sebanyak n-1. i sebagai elemen minimum sementara. arr[pos_min] untuk mengecek elemen indeks j. selectsort(Ips, Mahasiwa) untuk mengurutkan array ips . looping for digunakan untuk menampilkan setiap elemen yang terurut dari terbesar ke terkecil. 

### Kesimpulan 
kode ini untuk mengururtkan array ips mahasiswa dari terbesar ke terkecil. 
selection sort O(n^2) menyatakan bahwa waktu yang dibutuhkan untuk menjalankan selection sort berbanding lurus dengan pangkat dua dari jumlah elemen (n). semakin besar jumlah elemen maka waktu yang dibutuhkan untuk mengurutkan data akan semakin lama.

### 2. soal 
Pak RT memiliki 10 warga dengan nama: siti, situ, sana, ana, ani, caca, cici, dida, dodo,
dan dadi. Supaya mudah dalam melakukan pencarian, Pak RT akan mengurutkan namanama tersebut sesuai dengan alfabet. Buatlah program untuk membantu Pak RT dengan
menggunakan algoritma Bubble Sort!
~~~C++
#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string nama[], int n) {
  bool swapped;
  int i, j;

  for (i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = 0; j < n - i - 1; j++) {
      if (nama[j] > nama[j + 1]) {
        swap(nama[j], nama[j + 1]);
        swapped = true;
      }
    }

    // Jika tidak ada pertukaran pada iterasi ini, maka array sudah terurut
    if (!swapped) {
      break;
    }
  }
}

int main() {
  // Array untuk menyimpan nama-nama warga
  string nama[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

  // Jumlah warga
  int Warga = 10;

  // Mengurutkan nama-nama warga
  bubbleSort(nama, Warga);

  // Menampilkan nama-nama warga yang telah diurutkan
  for (int i = 0; i < Warga; i++) {
    cout << nama[i] << " ";
  }
}
~~~

### output:
<img width="960" alt="Cuplikan layar 2024-03-27 234545" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/92dd2780-d89a-46e0-b535-17305b9e302e">

### interprestasi
fungsi bubbleSort berfungsi ini mengurutkan array nama dengan panjangan warga untuk menggunakan algoritma bubble sort. Swapped untuk menandai apakah ada pertukaran elemen. if (nama[j] > nama[j + 1]) membandingkan dua elemen array yang berdekatan. if (!swapped) jika tidak ada pertukaran maka dapat dihentikan.
### Kesimpulan : 
program bubble sort untuk menguruttkan nama- nama warga pak RT agar mudah di pahami dan diimplementasikan. time complexity adalah O(n^2) dimana sort perlu membandingkan n-1 elemen. program dapat dimodifikasi dalam urutan descending. bubble sort dapat diubah untuk mengurutkan data dengan tipe data yang berbeda seperti integer atau float. 

### 3. soal
 Buatlah program yang meminta user menginputkan suatu bilangan n dan meminta user
untuk menginputkan sejumlah n karakter. Kemudian program akan melakukan sorting
secara menaik (ascending) dan menurun (descending)!
~~~C++
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int n;

  // Meminta user untuk memasukkan jumlah karakter
  cout << "Masukkan jumlah karakter: ";
  cin >> n;

  // Deklarasi array untuk menyimpan karakter
  char karakter[n];

  // Meminta user untuk memasukkan karakter
  cout << "Masukkan " << n << " karakter: ";
  for (int i = 0; i < n; i++) {
    cin >> karakter[i];
  }

  // Menampilkan karakter sebelum sorting
  cout << "\nKarakter sebelum sorting: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }

  // Sorting karakter secara ascending
  sort(karakter, karakter + n);

  // Menampilkan karakter setelah sorting ascending
  cout << "\n\nKarakter setelah sorting ascending: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }

  // Sorting karakter secara descending
  reverse(karakter, karakter + n);

  // Menampilkan karakter setelah sorting descending
  cout << "\n\nKarakter setelah sorting descending: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }

  cout << endl;

  return 0;
}
~~~


### ouput:
<img width="960" alt="Cuplikan layar 2024-03-28 211225" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/2da26927-cd03-454b-9628-4b9bcf8724d2">

### Interprestasi : 
program ini meminta pengguna memasukkan sejumlah karakter, kemudian menyimpannya dalam sebuah array. setelah itu, program mengurutkan array tersebut secara ascending dan descending menggunakan fungsi sort dan reverse. loop untuk menampilkan karakter yang diurutkan secara descending. menampilkan karakter sebelum pengurutan , setelah pengurutan ascending dan setelah pengurutan secara descending. 

## Kesimpulan
memiliki time complexity waktu rata-rat o(n log n), dimana n adalah jumlh karakter yang dimasukkan. array juga memiliki kompleksitas waktu o(n) untuk meminta input karakter dan mencetak hasil. program kodingan ini untuk memasukkan sejumlah karakter, menyimpanya dalam sebuah array, mengurutkan array scara ascending dan descending dan menampilkn hasilnya.

## Referensi

[1] S. Esabella and M. Haq, Dasar-Dasar Pemrograman. Olat Maras Publishing, 2021:108-114.

[2]  Arifin RW, Setiyadi D. 2020. Algoritma Metode Pengurutan Bubble Sort dan Quick Sort Dalam Bahasa Pemrograman C++. Information System for Educators and Professionals. 4
(2): 178 – 187.