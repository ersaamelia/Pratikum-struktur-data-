# <h1 align="center">Laporan Praktikum Modul Searching </h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori
 Pemograman Searching merupakan metode pencarian data denganmembandingkan setiap elemen larik satu per satu secara urut (beruntun), mulai dari elemen pertama sampai dengan elemen yang terakhir. Ada  2 macam pencarian beruntun, yaitu pencarian array  yang sudah terurut, dan pecarian pada array yang belum terurut.[1].

 A. Sequential Search 
 sequential search merupakan metode pencarian metode dalam array dengan search array dengan cara membandingkan data yang dicari dengan data yang ada didalam array secara berurutan.[1]

 prosesnya sequential search seperti berikut:
 1. menentukan data yang dicari.
 2. membaca data array satu per satu secara sekuensial
 3. mulai dari data pertama sampai dengan data terakhir, kemudian data yang dicari tadi dibandingkan dengan masing-masing data yang ada di dalam array. [1]

Misal mencari nilai 63 dalam daftar ada dilokasi indeks 5 dan 8. operasi dihentikan diposisi 5 dan langsung diberikan statment bahwa data berhasil ditemukan.
 <img width="321" alt="Cuplikan layar 2024-04-02 121602" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/f7ed362f-7121-44bc-893b-13c38b97782e">

B.  Binary search 
Binary search merupakan metode pencarian yang mencari data dengan melakukan mengelompokkan array menjadi bagian-bagian.[1].

contoh :
<img width="375" alt="image" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/a91a1b4a-d61c-4c2e-8955-fd8115f9f6e5">

langkah pertama : 

a. menentukan posisi low kemudian posisi high dengan mencari mid = (high + low) /2.

b. lalu bandingkan data yang dicari dengan nilai posisi mid. 

c. jika data yang dicari sama dengan nilai yang ada posisi mid maka data ditemukan.

d. jika data yang dicari lebih kecil dari nilai maka akan dilakukan bagian kiri mid dengan melakukan perbandingan. kodisi high berubah (mid-1) dan posisi low tetap. 

e. jika data yang dicari lebih besar maka akan di seblah kanan dengan (mid + 1) dan posisi high tetap.
[1] 

<img width="303" alt="image" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/1d088fae-34a9-4965-bb76-e87660e3345a">

### Guided
### 1. [Input algoritma Bubble Sort]

~~~C++
#include <iostream>

using namespace std;

int main() {
    int n =10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    //algoritma sequential seacrh
    for (i = 0; i < n; i++) {
        if(data[i] == cari) {
            ketemu = true;
            break;
        }
    }
    cout << "\t program sequential search sederhana\n" << endl;
    cout << "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;

    if  (ketemu) {
        cout << "\n angka "<< cari << " ditemukan pada indeks ke-" << i << endl;
    } else {
        cout << cari << " tidak dapat ditemukan pada. " << endl;
    }
    return 0;
    
    }
~~~

#### Output:
<img width="960" alt="Cuplikan layar 2024-04-02 103707" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/c7c0072a-1016-463b-8688-57533c370786">


### interprestasi:
Kode ini menggunakan algoritma Sequential Search untuk mencari sebuah angka dalam array data. Array data telah diinisialisasi dengan 10 elemen, dan nilai yang ingin dicari adalah 10. Variabel ketemu digunakan untuk menandai apakah nilai yang dicari telah ditemukan atau tidak. Algoritma Sequential Search dilakukan dengan mengiterasi setiap elemen dalam array data dan memeriksa apakah nilai tersebut sama dengan nilai yang dicari (cari).Jika nilai yang dicari ditemukan, maka variabel ketemu diatur menjadi true, dan indeks di mana nilai ditemukan disimpan dalam variabel i.Setelah proses pencarian selesai, program mencetak hasil pencarian, yaitu apakah nilai yang dicari ditemukan atau tidak, beserta indeksnya jika ditemukan.

Algoritma Sequential Search memiliki kompleksitas waktu O(n), di mana n adalah jumlah elemen dalam array.
Hal ini disebabkan karena algoritma ini harus memeriksa setiap elemen dalam array satu per satu hingga menemukan nilai yang dicari atau mencapai akhir array. Oleh karena itu, semakin besar jumlah elemen dalam array, semakin banyak iterasi yang diperlukan untuk menyelesaikan pencarian, dan kompleksitas waktu algoritma ini tumbuh secara linear dengan jumlah elemen.

### 2. [Algoritma Insertion sort]

~~~C++
#include <iostream>
#include <iomanip>
#include <conio.h>

using namespace std;

int data[7] = {1, 8, 2, 5, 4, 9, 7};
int cari;

void selection_sort() {
    int temp, min, i, j;
    for(i = 0; i < 7; i++) {
        min = i;
        for(j = i + 1; j < 7; j++) {
            if(data[j] < data[min]) {
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binarysearch() {
    // searching
    int awal, akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = 6; // Mengubah akhir dari 7 menjadi 6 karena indeks dimulai dari 0 hingga 6
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir) / 2;
        if(data[tengah] == cari) {
            b_flag = 1;
            break;
        }
        else if(data[tengah] < cari)
            awal = tengah + 1;
        else
            akhir = tengah - 1;
    }
    if(b_flag == 1)
        cout << "\n Data ditemukan pada index ke-" << tengah << endl;
    else
        cout << "\n Data tidak ditemukan\n";
}

int main() {
    cout << "\t BINARY SEARCH " << endl;
    cout << "\n Data : ";
    // tampilkan data awal
    for(int x = 0; x < 7; x++)
        cout << setw(3) << data[x];
    cout << endl;
    cout << "\n Masukkan data yang ingin Anda cari : ";
    cin >> cari;
    cout << "\n Data diurutkan : ";
    // urutkan data dengan selection sort
    selection_sort();
    // tampilkan data setelah diurutkan
    for(int x = 0; x < 7; x++)
        cout << setw(3) << data[x];
    cout << endl;
    binarysearch();
    _getche();
    return 0; // Mengubah EXIT_SUCCESS menjadi 0 karena menggunakan C++
}
~~~

#### Output:
<img width="960" alt="image" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/b45ede74-a69b-4ae9-97b7-788c9139f913">

### interprestasi:
 Program memiliki sebuah array data yang telah diinisialisasi dengan nilai-nilai {1, 8, 2, 5, 4, 9, 7}. Sebelum melakukan pencarian, array data diurutkan menggunakan algoritma Selection Sort untuk menghasilkan array yang terurut secara ascending. Setelah diurutkan, array menjadi {1, 2, 4, 5, 7, 8, 9}. Input Pencarian Pengguna diminta untuk memasukkan angka yang ingin dicari. Program melakukan pencarian menggunakan algoritma Binary Search dalam array yang telah diurutkan. Algoritma ini mencari angka yang dicari dengan membagi-bagi rentang pencarian menjadi dua bagian secara berulang hingga angka yang dicari ditemukan atau rentang pencarian menjadi kosong. 
 
 Time complexity dari algoritma Binary Search adalah O(log n), di mana n adalah jumlah elemen dalam array yang diurutkan, Karena setiap iterasi membagi rentang pencarian menjadi dua bagian kompleksitas waktu dari algoritma Binary Search adalah O(log n), di mana log adalah logaritma basis 2.
## Unguided 

### 1.  [Soal]
Buatlah sebuah program untuk mencari sebuah huruf pada sebuah
kalimat yang sudah di input dengan menggunakan Binary Search!

~~~C++
#include <iostream>
#include <algorithm>

using namespace std;


bool binarySearch(string str, char target) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        
        if (str[mid] == target)
            return true;

        
        if (str[mid] < target)
            left = mid + 1;
        
        else
            right = mid - 1;
    }

    
    return false;
}

int main() {
    string sentence;
    char target;

    
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, sentence);
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

   
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

    
    bool found = binarySearch(sentence, tolower(target));

    
    if (found)
        cout << "Huruf '" << target << "' ditemukan dalam kalimat.\n";
    else
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat.\n";

    return 0;
}
~~~

#### Output:
<img width="960" alt="Cuplikan layar 2024-04-03 183038" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/dfb136be-120c-451b-aba2-28521af2eb73">

### interprestasi :
fungsi iostream untuk input standar dan  fungsi algoritma untuk tranform. looping akan berjalan selama left masih kurang dari , nilai mid dihitung dengan left + (right -left)/2  untuk mendaptkan indeks tengah string. jika indeks mid sama dengan target maka fungsi mengembalikan true. jika target tidak ditemukkan dalam string aka fungsi mengembalikan false. 
kodingan memasukkan kalimat " Saya suka renang" 
memasukkan huruf yang ingin dicari dengan huruf kecil  "r" maka akan di temukan dalam kalimat, sedangkan memasukkan huruf besar maka tidak dapat ditemukkan. 

### Kesimpulan 
Time complexity Binary Search adalah O(log n), dimana panjang dari string. setiap iterasi nilai mid  dihitung dengan membagi ruang pencarian menjadi dua (o(1)). operasi pencarian didominasi oleh iterasi loop while O(log n). 
jadi program kodingan tersebut untuk memasukkan sebuah kalimat dan huruf yang ingin dicari menggunakan semua huruf kecil untuk mempermudah pencarian. 

### 2. soal 
Buatlah sebuah program yang dapat menghitung banyaknya huruf
vocal dalam sebuah kalimat!

~~~C++
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  string kalimat;
  int jumlah_vokal = 0;

  
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  
  transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);

  
  for (int i = 0; i < kalimat.length(); i++) {
    if (kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' || kalimat[i] == 'e' || kalimat[i] == 'o') {
      jumlah_vokal++;
    }
  }

  
  cout << "Jumlah huruf vokal dalam kalimat: " << jumlah_vokal << endl;

  return 0;
}
~~~

### output:
<img width="960" alt="Cuplikan layar 2024-04-03 195348" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/f90fc57f-3d85-4aff-8401-0bda13db4644">

### interprestasi
<algorithm> Pustaka ini menyediakan berbagai fungsi algoritma standar, termasuk fungsi transform. kalimat String yang menyimpan kalimat yang akan dianalisis. (jumlah_vokal) Integer yang menyimpan jumlah huruf vokal yang ditemukan. cout << ("Masukkan kalimat: ";) Menampilkan pesan "Masukkan kalimat: " ke layar. (getline(cin, kalimat);) Membaca kalimat yang dimasukkan pengguna dan menyimpannya dalam variabel kalimat. (transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);) Mengubah semua huruf dalam string kalimat menjadi huruf kecil.  for (int i = 0; i < kalimat.length(); i++) Perulangan untuk setiap karakter dalam string kalimat. if (kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' || kalimat[i] == 'e' || kalimat[i] == 'o') Memeriksa apakah karakter saat ini adalah huruf vokal (a, i, u, e, atau o). jumlah_vokal++; Jika karakter saat ini adalah huruf vokal, maka nilai jumlah_vokal ditambah 1. Memasukkan kalimat getline(cin,kalimat). kalimat dapat diubah menjadi huruf kecil dengan menggunakan transform(kalimat.begin(), kalimat.end(), kalimat.begin(), tolower). perulangan for digunakan setiap karakter dengan memperiksa (a, i, u, e, o). hasil akan memunjulkan jumlah vokal.

Time complexity adalah O(n), dimana panjang kalimat untuk mencari huruf vokal. <iostream> Pustaka ini digunakan untuk operasi input dan output data. operasi dominan dalam kodingan ini adalah perulangan yang iterasi sebanyak n. 

### Kesimpulan :  
kodingan ini untuk menghitung banyaknya huruf vokal dalam sebuah kalimat. seperti : saya suka kpop maka jumlah vokalnya ada 5. 

### 3. soal
 Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak
angka 4 dengan menggunakan algoritma Sequential Search!
~~~C++
#include <iostream>

using namespace std;

int hitungAngkaEmpat(int data[], int panjang) {
    int jumlahEmpat = 0;
    for (int i = 0; i < panjang; ++i) {
        if (data[i] == 4) {
            jumlahEmpat++;
        }
    }
    return jumlahEmpat;
}  

int main() {
  int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int n = sizeof(data) / sizeof(data[0]);
  int jumlah_angka_4 = 0;

  // Algoritma Sequential Search
  for (int i = 0; i < n; i++) {
    if (data[i] == 4) {
      jumlah_angka_4++;
    }
  }

  // Tampilkan hasil
  cout << "Jumlah angka 4 dalam data: " << jumlah_angka_4 << endl;

  return 0;
}
~~~
### ouput:
<img width="960" alt="Cuplikan layar 2024-04-03 201630" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/e346b562-ddd3-472b-8487-dbacb4789a8c">

### Interprestasi :
(int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};) Deklarasi dan inisialisasi array data yang berisi 10 elemen integer.
(int n = sizeof(data) / sizeof(data[0]);) Menghitung dan menyimpan panjang array data dalam variabel n.
(int jumlah_angka_4 = 0;) Inisialisasi variabel jumlah_angka_4 untuk menyimpan jumlah angka 4.
for (int i = 0; i < n; i++) Perulangan untuk setiap elemen dalam array data. if (data[i] == 4) Memeriksa apakah elemen saat ini sama dengan 4.
(jumlah_angka_4++;) Jika elemen saat ini sama dengan 4, maka nilai jumlah_angka_4 ditambah 1. (cout << "Jumlah angka 4 dalam data: " << jumlah_angka_4 << endl;) Menampilkan jumlah angka 4 ke layar. (return 0;)Mengembalikan nilai 0 untuk menunjukkan bahwa program selesai dengan sukses.
fungsi hitungAngkaEmpat menerima dua parameter ada data dan panjang. variabel jumlahEmpat diinisialisasi dengan nilai 0. perulangan for digunakan iterasi elemen dalam array. setiap elemen diperiksa apakah sama dengan 4, jika sama maka diincrement. seperti kodingan itu menghitung berapa kali angka 4 muncul dalam array maka halinya ada 4. 

time complexity  adalah O(n), di mana n adalah jumlah elemen dalam array data. Karena program harus melakukan pemeriksaan setiap elemen dalam array secara berurutan untuk menentukan apakah itu angka 4 atau bukan. Oleh karena itu, kompleksitasnya tumbuh secara linear dengan ukuran input (jumlah elemen dalam array).

### kodingan berbeda 
~~~C++
#include <iostream>

using namespace std;

// Fungsi untuk menghitung berapa kali angka selain 4 muncul dalam data menggunakan Sequential Search
int hitungAngkaSelainEmpat(int data[], int panjang, int angka) {
    int jumlahAngka = 0;
    for (int i = 0; i < panjang; ++i) {
        if (data[i] != angka) {
            jumlahAngka++;
        }
    }
    return jumlahAngka;
}

int main() {
    int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
    int panjang = sizeof(data) / sizeof(data[0]);
    int angkaPencarian = 4; // Angka yang ingin dihitung selain 4

    int jumlahSelainEmpat = hitungAngkaSelainEmpat(data, panjang, angkaPencarian);

    cout << "Banyaknya angka selain " << angkaPencarian << " dalam data adalah: " << jumlahSelainEmpat << endl;

    return 0;
}
~~~

### output:
<img width="960" alt="image" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/6754a394-1356-411d-ad3b-38fe814d3133">

<img width="960" alt="image" src="https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/761c3f33-d19e-4540-9018-074b3e138531">

### Interprestasikan:
Fungsi hitungAngkaSelainEmpat() menerima array data, panjang array panjang, dan angka yang ingin dicari selain 4 angka. Program utama memanggil fungsi tersebut dengan menyediakan array data, panjang array, dan angka pencarian 4.
Pada setiap iterasi, program memeriksa apakah elemen pada indeks tertentu dalam array data tidak sama dengan angka 4. Jika tidak sama, maka jumlah angka tersebut ditambahkan. Setelah selesai memeriksa semua elemen dalam array, program mencetak jumlah angka selain 4 yang ditemukan.menghasilan angka 6. 
### Kesimpulan
program tersebut memberikan informasi tentang berapa kali angka 4 muncul dalam array data yang diberikan. Program ini menunjukkan penggunaan algoritma Sequential Search untuk mencari elemen tertentu dalam sebuah array.

## Kesimpulan
Sequential Search adalah metode yang sederhana dan mudah diimplementasikan, tetapi lambat pada array yang besar. Binary Search jauh lebih cepat pada array yang besar, tetapi hanya bekerja pada array yang terurut.
Sequential Search Metode: Membandingkan data yang dicari dengan data di array secara berurutan.
Keuntungan itu Sederhana dan mudah diimplementasikan. Bekerja dengan baik pada array yang kecil.
Kekurangan itu Lambat pada array yang besar.
Tidak efisien jika data tidak terurut.

Binary Search Metode: Membagi array menjadi dua bagian dan mencari data di bagian yang sesuai.
Keuntungan itu Jauh lebih cepat daripada Sequential Search pada array yang besar.
Bekerja dengan baik pada array yang terurut.
Kekurangan itu Lebih kompleks untuk diimplementasikan. Hanya bekerja pada array yang terurut.


## Referensi

[1] S. Esabella and M. Haq, Dasar-Dasar Pemrograman. Olat Maras Publishing, 2021:100-105.

