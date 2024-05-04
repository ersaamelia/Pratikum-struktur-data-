# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori

# Stack

Stack adalah suatu tumpukan dari benda. Konsep utamanya adalah LIFO (Last In First Out), benda yang
terakhir masuk dalam stack akan menjadi benda pertama yang dikeluarkan dari stack.

![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/552c28dc-8304-4b38-be9f-c917167e6269)

Ada	dua	cara	penerapan	prinsip	stack,	yakni	dengan	array	dan	linked	list.	Setidaknya	stack	haruslah	memiliki	
operasi-operasi	sebagai	berikut.
• Push Untuk	menambahkan	item	pada	tumpukan	paling	atas
• Pop Untuk	mengambil	item	teratas
• Clear Untuk	mengosongkan	stack
• IsEmpty Untuk	memeriksa	apakah	stack	kosong
• IsFull Untuk	memeriksa	apakah	stack	sudah	penuh
• Retreive Untuk	mendapatkan	nilai	dari	item	teratas.


Stack	dengan	Array

Sesuai	 dengan	 sifat	 stack,	 pengambilan	 /	 penghapusan	 di	elemen	 dalam	 stack	 harus	 dimulai	 dari	elemen	
teratas.	Operasi-operasi	pada	Stack	dengan	Array.
a. IsFull	Fungsi	ini	memeriksa	apakah	stack	yang	ada	sudah	penuh.	Stack	penuh	jika	puncak	stack	terdapat	tepat di	bawah	jumlah	maksimum	yang	dapat	ditampung	stack	atau	dengan	kata	lain	Top	=	MAX_STACK	-1.
b.  Push	Fungsi	ini	menambahkan	sebuah	elemen	ke	dalam	stack	dan	tidak	bisa	dilakukan	lagi	jika	stack	sudah	
penuh.
c. IsEmpty	Fungsi	menentukan	apakah	stack	kosong	atau	tidak.	Tanda	bahwa	stack	kosong	adalah Top	bernilai kurang dari nol.
d. Pop	Fungsi	ini	mengambil	elemen	teratas	dari	stack	dengan	syarat	stack	tidak	boleh	kosong.
e.  Clear	Fungsi	ini	mengosongkan	stack	dengan	cara	mengeset	Top	dengan	-1.	Jika	Top	bernilai	kurang	dari	nol	maka	stack	dianggap	kosong.
f. Retreive	Fungsi	ini	untuk	melihat	nilai	yang	berada	pada	posisi	tumpukan	teratas.



### Guided
### 1. 

~~~C++
#include <iostream>

using namespace std;

string arrayBuku[5];
int maksimal = 5, top = 0;

bool isFull() {
    return (top == maksimal);
}

bool isEmpty() {
    return (top == 0);
}

void pushArrayBuku(string data) {
    if (isFull()) {
        cout << "Data telah penuh" << endl;
    }

    else {
        arrayBuku[top] = data;
        top++;
    }
}

void popArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang dihapus" << endl;
    } else {
        arrayBuku[top - 1] == "";
        top--;
    }
}

void peekArrayBuku(int posisi) {
    if (isEmpty()) {
        cout << "Tidak ada data yang bisa dilihat" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }

        cout << "Posisi ke " << posisi << " adalah "  << arrayBuku[index] << endl;
    }
}

int countStack() {
    return top;
}

void changeArrayBuku(int posisi, string data) {
    if (posisi > top) {
        cout << "Posisi melebihi data yang ada" << endl;
    } else {
        int index = top;
        for (int i = 1; i <= posisi; i++) {
            index--;
        }
        arrayBuku[index] = data;
    }
}

void destroyArrayBuku() {
    for (int i = top; i > 0; i--) {
        arrayBuku[i] = "";
    }
    top = 0;
}

void cetakArrayBuku() {
    if (isEmpty()) {
        cout << "Tidak ada data yang 70 dicetak" << endl;
    } else {
        for (int i = top - 1; i >= 0; i--) {
            cout << arrayBuku[i] << endl;
        }
    }
}

int main () {
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout << "\n";

    cout << "Apakah data stack suda penuh?" << isFull() << endl;
    cout << "Apakah data stack kososng?" << isEmpty() << endl;

    peekArrayBuku(2);
    popArrayBuku();
    
    cout << "Banyakanya Data = " << countStack() << endl;
    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout << "\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();
    return 0;
}
~~~
### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/08c3cca3-8b47-4953-b7a6-41009c324d6a)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/a853aa7a-6642-4e63-a469-97d8ad6b853d)

### interprestasi:
Push (Menambah Data) Fungsi pushArrayBuku(string data) digunakan untuk menambahkan data ke dalam stack.
Data pada indeks top-1 dihapus dengan mengubah nilainya menjadi string kosong, dan nilai top dikurangi.
Peek (Melihat Data) Fungsi peekArrayBuku(int posisi) digunakan untuk melihat data pada posisi tertentu dalam stack.
Change (Mengubah Data) Fungsi changeArrayBuku(int posisi, string data) digunakan untuk mengubah data pada posisi tertentu dalam stack.
Destroy (Menghapus Semua Data) Fungsi destroyArrayBuku() digunakan untuk menghapus semua data dalam stack.
Cetak (Menampilkan Semua Data) Fungsi cetakArrayBuku() digunakan untuk menampilkan semua data dalam stack.
Fungsi main() Pada fungsi main(), beberapa operasi stack dijalankan: Data dimasukkan ke dalam stack menggunakan fungsi pushArrayBuku().

Lima data telah ditambahkan ke dalam stack: "Kalkulus", "Struktur Data", "Matematika Diskrit", "Dasar Multimedia", dan "Inggris". Pengecekan apakah stack sudah penuh atau kosong: (Stack belum penuh, sehingga isFull() mengembalikan nilai 0), sedangkan (Stack tidak kosong, sehingga isEmpty() mengembalikan nilai 0). Data pada posisi ke-2 dalam stack adalah "Matematika Diskrit". Data teratas dalam stack, yaitu "Inggris", dihapus. Data pada posisi ke-2 dalam stack diubah menjadi "Bahasa Jerman". Semua data dalam stack dihapus.

## Unguided 

### 1.  [Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.]

~~~C++
#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Menghapus karakter non-alphanumeric dari string
string removeNonAlphaNumeric(string str) {
    string result = "";
    for (char c : str) {
        if (isalnum(c)) {
            result += tolower(c);
        }
    }
    return result;
}

// Mengecek apakah sebuah string adalah palindrom
bool isPalindrome(string str) {
    stack<char> s;
    int n = str.size();
    
    // Menyimpan setengah karakter pertama ke dalam stack
    for (int i = 0; i < n/2; i++) {
        s.push(str[i]);
    }

    // Membandingkan setengah karakter kedua dengan karakter yang disimpan di stack
    for (int i = (n+1)/2; i < n; i++) {
        if (s.top() != str[i]) {
            return false;
        }
        s.pop();
    }
    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Menghapus karakter non-alphanumeric dan membuat string menjadi lowercase
    string kalimatBersih = removeNonAlphaNumeric(kalimat);
    
    // Menentukan apakah kalimat adalah palindrom atau tidak
    if (isPalindrome(kalimatBersih)) {
        cout << "Kalimat merupakan palindrom." << endl;
    } else {
        cout << "Kalimat bukan palindrom." << endl;
    }

    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/0f882ea8-dea1-4f40-bcd0-e198f6b24f09)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/96f06443-24aa-44ce-87e5-acfa76f48663)

#### Interprestasikan:
Fungsi removeNonAlphaNumeric() Fungsi ini digunakan untuk menghapus karakter non-alphanumeric dari sebuah string.
Setiap karakter dalam string diperiksa, dan jika karakter tersebut adalah alphanumeric (huruf atau angka), maka karakter tersebut ditambahkan ke dalam string hasil.
Fungsi isPalindrome() Fungsi ini digunakan untuk menentukan apakah sebuah string adalah palindrom atau tidak.
Fungsi ini menggunakan stack untuk membandingkan setengah karakter pertama dengan setengah karakter kedua dari string.
Jika semua karakter cocok, maka string tersebut adalah palindrom.
Kalimat tersebut diubah menjadi lowercase dan karakter non-alphanumeric dihapus menggunakan fungsi removeNonAlphaNumeric().
Selanjutnya, fungsi isPalindrome() dipanggil untuk menentukan apakah kalimat tersebut adalah palindrom atau tidak.
‘‘ jika kalimat tersebut adalah palindrom, dan mencetak ‘‘Kalimat bukan palindrom.
kalimat : ibu ratna antar ubi ( jika diubah dari belakang ke depan maka akan sama hasilnya).
jika kalimat bukan palindrome itu kalimat : roti tawar serabi (jika diubah dari belakang ke depan maka berbeda hasilnya).

### 2.  [Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?]
~~~C++
#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan kalimat menggunakan stack
string reverseString(string kalimat) {
    stack<char> s;
    string reversedKalimat = "";

    // Memasukkan setiap karakter dari kalimat ke dalam stack
    for (char c : kalimat) {
        s.push(c);
    }

    // Mengambil setiap karakter dari stack untuk membentuk kalimat terbalik
    while (!s.empty()) {
        reversedKalimat += s.top();
        s.pop();
    }

    return reversedKalimat;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, kalimat);

    // Memanggil fungsi untuk membalikkan kalimat
    string kalimatTerbalik = reverseString(kalimat);

    // Menampilkan kalimat asli dan kalimat terbalik
    cout << "Kalimat asli: " << kalimat << endl;
    cout << "Kalimat terbalik: " << kalimatTerbalik << endl;

    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/1b441949-8400-42aa-9958-3a7ba70158bb)

#### Interprestasikan:
Setiap karakter dari kalimat dimasukkan ke dalam stack. Kemudian, program mengambil setiap karakter dari stack untuk membentuk kalimat terbalik. Fungsi main(): Pada fungsi main(), program meminta pengguna untuk memasukkan sebuah kalimat. Program memanggil fungsi reverseString() untuk membalikkan kalimat yang dimasukkan.
Program menampilkan kalimat asli yang dimasukkan oleh pengguna.

#### Kesimpulan:
Push Untuk menambahkan item pada tumpukan paling atas. Pop Untuk mengambil item teratas. Clear Untuk mengosongkan stack. IsEmpty Untuk memeriksa apakah stack kosong. IsFull Untuk memeriksa apakah stack sudah penuh.  Retreive Untuk mendapatkan nilai dari item teratas. IsFull Fungsi ini memeriksa apakah stack yang ada sudah penuh.
 Push Fungsi ini menambahkan sebuah elemen ke dalam stack dan tidak bisa dilakukan lagi jika stack sudah penuh.
IsEmpty Fungsi menentukan apakah stack kosong atau tidak. Tanda bahwa stack kosong adalah Top bernilai kurang dari nol. Pop Fungsi ini mengambil elemen teratas dari stack dengan syarat stack tidak boleh kosong. Clear Fungsi ini mengosongkan stack dengan cara mengeset Top dengan -1. Retreive Fungsi ini untuk melihat nilai yang berada pada posisi tumpukan teratas.

### Sumber:

[1]. Pemrograman C++ ALGORITMA & STRUKTUR DATA, Rizki Muliono, S.Kom, M.Kom. 2018.