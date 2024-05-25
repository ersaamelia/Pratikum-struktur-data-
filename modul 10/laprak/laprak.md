# <h1 align="center">Laporan Praktikum Modul REKURSIF</h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori
pemograman rekursif merupakan proses memanggil dirinya sendiri yang biasa dilakukan oleh fungsi atau prosedur pada pemograman modular. Rekursif akan terus berjalan sampai kondisi berhenti terpenuhi, mirip dengan perulangan/looping.[1].

pemograman rekursif faktorial dari bilangan asli n adalah hasil peralian bilangan bulat positif yang kurang dari atau sama dengann. faktorial yang di tulis sebagai n! dan dis ebut n faktorial , tanda ! disebut dengan notasi faktorial.[1].

Rekursi adalah suatu proses dari fungsi yang memanggil dirinya sendiri. Fungsi yang seperti ini disebut 
fungsi rekursif (recursive function). Dalam sebuah fungsi rekursif pemanggilan dapat terjadi berulang kali. Karena 
ada proses yang berulang-ulang maka harus ada suatu kondisi yang mengakhiri prosesnya. Jika tidak, maka 
proses tidak akan pernah berhenti sampai memori yang digunakan tidak dapat menampung lagi. 
Pemecahan masalah dengan pendekatan rekursif dapat dilakukan jika masalah tersebut dapat 
didefinisikan secara rekursif, yaitu masalah dapat diuraikan menjadi masalah sejenis yang lebih sederhana. Dalam membuat fungsi rekursi harus ditentukan kondisi perhentian. Kondisi perhentiannya adalah jika nilai n sudah lebih kecil atau sama dengan 0. Setiap kali fungsi memanggil 
dirinya sendiri, nilai dari n dikurangi dengan nilai 1, sehingga nilai n akhirnya akan menjadi nol dan proses rekursi 
akan diakhiri, sehingga fungsi ini akan memanggil dirinya sendiri sebanyak n kali. 
Contoh untuk menggambarkan fungsi rekursif yang sering digunakan adalah fungsi untuk mendapatkan 
nilai faktorial dari suatu bilangan bulat.[2].

Proses ini akan memanggil kembali fungsi dirinya sendiri dengan mengirimkan nilai 4 sebagai nilai a yang 
baru. Karena nilai a masih lebih besar dari 1 maka proses rekursi kedua akan dilakukan dengan hasilnya 
adalah 4 * factorial(3). Untuk a adalah 3, hasil yang diperoleh oleh rekursi adalah 3 * factorial(2) dan 
seterusnya sampai nilai a adalah 1. Untuk nilai a sama dengan 1 ini, perintah return(1) akan mengembalikan 
proses ke bagian yang memanggilnya.
Hasil akhir dari nilai yang akan dikembalikan oleh fungsi faktorial dari penjelasan di atas untuk 5 faktorial dapat 
dituliskan sebagai berikut: [2].
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/d22d18c8-25ac-4c13-81f6-f2493284729c)




### Guided
### 1. 1.Rekursif Langsung (Direct Recursion)

~~~C++
#include <iostream>

using namespace std;

// Recursive function to perform a countdown from n to 0
void countdown(int n) {
    if (n < 0) {  // Adjusted base case to include 0 in the countdown
        return;
    }

    cout << n << " ";
    countdown(n - 1);  // Recursive call with n decremented by 1
}

int main() {
    cout << "Rekursi langsung: ";
    countdown(5);  // Start the countdown from 5
    cout << endl;  // End the line after the countdown is complete
    return 0;
}
~~~
### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/ff0d2f45-5369-469f-9cdd-b7595d2ea7f9)

### interprestasi:

Fungsi countdown mengambil satu argumen integer n. Base case dari rekursi adalah if (n < 0) { return; }, yang berarti jika n kurang dari 0, fungsi akan berhenti dan tidak melakukan apa-apa. cout << n << " "; mencetak nilai n diikuti oleh spasi.
countdown(n - 1); adalah pemanggilan rekursif di mana fungsi memanggil dirinya sendiri dengan n yang telah dikurangi 1. main adalah titik awal eksekusi program. cout << "Rekursi langsung: " mencetak string "Rekursi langsung: " ke layar. countdown(5) untuk memulai countdown dari nilai 5. cout << endl; menambahkan baris baru setelah countdown selesai untuk menjaga output tetap rapi. return 0 untuk  mengakhiri fungsi main dan mengembalikan nilai 0, yang biasanya menunjukkan bahwa program telah selesai dengan sukses.

Rekursi langsung: 5 4 3 2 1 0
menunjukkan countdown dari 5 hingga 0, di mana setiap angka dicetak dengan spasi di antaranya.


### 2. [Rekursif Tidak Langsung (Indirect Recursion)]

~~~C++
#include <iostream>

using namespace std;

void functionB(int n);

void functionA(int n) {
    if (n > 0) {
        cout << n << " ";
        functionB(n - 1);
    }
}

void functionB(int n) {
    if (n > 0) {
        cout << n << " ";
        functionA(n / 2);
    }
}

int main() {
    int  num = 5;
    cout << " Rekursif tidak langsung:";
    functionA(num);
    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/0213f27f-a50f-45d0-8934-b4676e4d6648)

#### Interprestasi:

Fungsi functionB dideklarasikan sebelum didefinisikan. Ini diperlukan agar functionA dapat memanggil functionB meskipun definisinya muncul setelah functionA.
functionA menerima satu argumen integer n.
functionA dipanggil dengan argumen num yang diinisialisasi menjadi 5.
functionA mencetak 5 dan memanggil functionB dengan argumen 4 (karena 5 - 1 = 4).
functionB mencetak 4 dan memanggil functionA dengan argumen 2 (karena 4 / 2 = 2).
functionA mencetak 2 dan memanggil functionB dengan argumen 1 (karena 2 - 1 = 1).
functionB mencetak 1 dan memanggil functionA dengan argumen 0 (karena 1 / 2 = 0).
functionA tidak mencetak apa-apa karena kasus dasar n > 0 tidak terpenuhi.
functionB juga tidak mencetak apa-apa karena kasus dasar n > 0 tidak terpenuhi.

Output program adalah: 5 4 2 1, yang menunjukkan urutan bilangan yang dicetak selama proses rekursif tidak langsung.


## Unguided 

### 1.  [1.Buatlah sebuah program Rekursif Langsung (Direct Recursion) yang menghitung nilai faktorial dari sebuah inputan bilangan bulat positif!]
~~~C++
#include <iostream>

using namespace std;

int faktorial(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * faktorial(n - 1);
    }
}

int main() {
    int num;

    cout << "Masukkan bilangan bulat positif: ";
    cin >> num;

    if (num < 0) {
        cout << "Masukkan bilangan bulat positif!" << endl;
    } else {
        int hasil = faktorial(num);
        cout << "Faktorial dari " << num << " adalah: " << hasil << endl;
    }

    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/fc07d000-1077-4754-81ff-b4f2ea0508a8)

#### Interprestasikan:
Program ini menampilkan fungsi rekursif untuk menghitung faktorial dari sebuah bilangan bulat positif. Fungsi faktorial menerima satu argumen integer n dan memiliki base case yang mengembalikan nilai 1 jika n kurang dari atau sama dengan 1. Jika n lebih besar dari 1, fungsi mengembalikan hasil dari n dikalikan dengan faktorial dari n - 1, yang merupakan pemanggilan rekursif. Jika memasukkan bilangan bulat positif atau nol, program akan menghitung faktorial dari bilangan tersebut menggunakan fungsi rekursif faktorial.

output 
masukkan bilangan bulat positif : 13 
faktorial dari 13 : 1932053504


#### Kesimpulan:

## Sumber :
[1].  S. Esabella and M. Haq, Dasar-Dasar Pemrograman. Olat Maras Publishing, 2021:78-81.

[2]. U. Ta, “Pemograman C++ Bab 11 Fungsi rekursif.pdf,” Unindra, Dec. 2017. 