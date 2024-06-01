# <h1 align="center">Laporan Praktikum Modul Hash_table</h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori
# Hash Table
Hash Table atau tabel hash digunakan untuk mengindeks sekumpulan array untuk memudahkan proses pencarian. 
Sebagai contoh PIN perusahaan menggunakan 5 digit, rentang nilainya adalah 00000-99999. Saat menggunakan array, dapat menggunakan array yang berisi 100.000 elemen. Pada kenyataan perusahaan hanya memiliki 100
karyawan. Tentu saja, menggunakan 100.000 elemen akan menyebabkan banyak ruang yang tidak terpakai atau memori yang
terbuang. Jadi berapa banyak array yang harus digunakan untuk mengisi data pencarian kunci dengan cepat? Tentu saja membutuhkan array kecil yang dapat menampung semua data. Jadi bagaimana memetakan antara lokasi PIN dan Array? Jawabannya adalah menggunakan fungsi hash (hash function). Hash function adalah fungsi yang digunakan untuk mengubah nilai kunci menjadi nilai yang disebut alamat hash. Alamat hash ini mewakili indeks posisi dalam array. Teknologi yang dapat dengan mudah dan cepat memperoleh lokasi rekaman melalui fungsi hash disebut hashing,
sehingga data karyawan dapat dicari tanpa membandingkan dengan kunci lainnya.[1]

# Menangani Tabrakan (Collision) Dalam Tabel Hash
Apapun metode yang digunakan bisa saja menimbulkan 2 buah
kunci atau lebih diterjemahkan oleh fungsi hash ke dalam nilai yang
sama. Situasi yang membuat beberapa kunci memiliki alamat hash yang
sama atau disebut dengan tabrakan hash (hash collision). Untuk
mengatasinya terdapat 3 teknik yaitu: Pengalamatan Terbuka (Open
Addressing), Pembentukan rantai (Chaining) dan Pengalamatan Buket
(bucket addressing).[1]

### Guided
### 1. 

~~~C++
#include <iostream>
using namespace std;
const int MAX_SIZE = 10;

// Fungsi hash sederhana
int hash_func(int key) {
    return key % MAX_SIZE;
}

// Struktur data untuk setiap node
struct Node {
    int key;
    int value;
    Node* next;
    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

// Class hash table
class HashTable {
private:
    Node** table;
public:
    HashTable() {
        table = new Node*[MAX_SIZE]();
    }
    ~HashTable() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    // Insertion
    void insert(int key, int value) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* node = new Node(key, value);
        node->next = table[index];
        table[index] = node;
    }

    // Searching
    int get(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1;
    }

    // Deletion
    void remove(int key) {
        int index = hash_func(key);
        Node* current = table[index];
        Node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Traversal
    void traverse() {
        for (int i = 0; i < MAX_SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << ": " << current->value << endl;
                current = current->next;
            }
        }
    }
};

int main() {
    HashTable ht;
    // Insertion
    ht.insert(1, 10);
    ht.insert(2, 20);
    ht.insert(3, 30);

    // Searching
    cout << "Get key 1: " << ht.get(1) << endl;
    cout << "Get key 4: " << ht.get(4) << endl;
   
    // Deletion
    ht.remove(4);
   
    // Traversal
    ht.traverse();
   
    return 0;
}
~~~
### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/dd802f8b-2cf2-40b3-8177-b4105d501cb9)

### interprestasi:
Struktur data Node digunakan untuk mewakili setiap elemen dalam hash table. Setiap node memiliki tiga atribut: key, value, dan next. key dan value mewakili nilai kunci dan nilai yang terkait dengan kunci tersebut, sedangkan next mewakili pointer ke node berikutnya dalam linked list. Fungsi hash_func digunakan untuk menghitung indeks hash dari suatu kunci. Dalam program ini, fungsi ini menggunakan algoritma sederhana yaitu menghitung sisa bagi kunci dengan ukuran hash table (MAX_SIZE).Konstruktor HashTable ini menginisialisasi tabel hash dengan ukuran MAX_SIZE.Dekonstruktor ~HashTable ini digunakan untuk menghapus semua node dalam hash table ketika objek hash table dihapus.Fungsi insert digunakan untuk menambahkan suatu kunci dan nilai ke dalam hash table. Fungsi ini terlebih dahulu menghitung indeks hash dari kunci, lalu mencari node yang memiliki kunci yang sama. Jika ditemukan, nilai tersebut diganti. Jika tidak ditemukan, node baru dibuat dan ditambahkan ke dalam linked list di indeks hash yang sesuai.
 Fungsi get digunakan untuk mencari nilai dari suatu kunci dalam hash table. Fungsi ini terlebih dahulu menghitung indeks hash dari kunci, lalu mencari node yang memiliki kunci yang sama. Jika ditemukan, nilai tersebut dikembalikan. Jika tidak ditemukan, fungsi ini mengembalikan nilai -1. Fungsi remove digunakan untuk menghapus suatu kunci dan nilai dari hash table. Fungsi ini terlebih dahulu menghitung indeks hash dari kunci, lalu mencari node yang memiliki kunci yang sama. Jika ditemukan, node tersebut dihapus dari linked list di indeks hash yang sesuai. Fungsi traverse digunakan untuk menampilkan semua elemen dalam hash table.

### 2. 

~~~C++
#include <iostream>
#include <string>
#include <vector>

using namespace std;
const int TABLE_SIZE = 11;

string name;
string phone_number;

class HashNode {
public:
    string name;
    string phone_number;

    HashNode(string name, string phone_number) {
        this->name = name;
        this->phone_number = phone_number;
    }
};

class HashMap {
private:
    vector<HashNode*> table[TABLE_SIZE];
public:
    int hashFunc(string key) {
        int hash_val = 0;
        for (char c : key) {
            hash_val += c;
        }
        return hash_val % TABLE_SIZE;
    }

    void insert(string name, string phone_number) {
        int hash_val = hashFunc(name);

        for (auto node : table[hash_val]) {
            if (node->name == name) {
                node->phone_number = phone_number;
                return;
            }
        }
        table[hash_val].push_back(new HashNode(name, phone_number));
    }

    void remove(string name) {
        int hash_val = hashFunc(name);

        for (auto it = table[hash_val].begin(); it != table[hash_val].end(); it++) {
            if ((*it)->name == name) {
                table[hash_val].erase(it);
                return;
            }
        }
    }

    string searchByName(string name) {
        int hash_val = hashFunc(name);
        for (auto node : table[hash_val]) {
            if (node->name == name) {
                return node->phone_number;
            }
        }
        return "";
    }

    void print() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            for (auto pair : table[i]) {
                if (pair != nullptr) {
                    cout << "[" << pair->name << ", " << pair->phone_number << "]";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap employee_map;

    employee_map.insert("Mistah", "1234");
    employee_map.insert("Pastah", "5678");
    employee_map.insert("Ghana", "91011");

    cout << "Nomer Hp Mistah : " << employee_map.searchByName("Mistah") << endl;
    cout << "Phone Hp Pastah : " << employee_map.searchByName("Pastah") << endl;

    employee_map.remove("Mistah");

    cout << "Nomer Hp Mistah setelah dihapus : " << employee_map.searchByName("Mistah") << endl << endl;

    cout << "Hash Table : " << endl;

    employee_map.print();

    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/156a3c1b-8c93-4e97-80d2-dc44dc9dbcac)

#### Interprestasi:
Struktur data HashNode digunakan untuk mewakili setiap elemen dalam hash map. Setiap node memiliki dua atribut: name dan phone_number, yang mewakili nama dan nomor telepon karyawan. Fungsi hashFunc digunakan untuk menghitung indeks hash dari suatu nama karyawan. Fungsi ini menggunakan algoritma sederhana yaitu menghitung jumlah nilai ASCII dari setiap karakter dalam nama karyawan, lalu menghitung sisa bagi dengan ukuran hash table (TABLE_SIZE).
Fungsi insert digunakan untuk menambahkan suatu nama karyawan dan nomor telepon ke dalam hash map. Fungsi ini terlebih dahulu menghitung indeks hash dari nama karyawan, lalu mencari node yang memiliki nama yang sama. Jika ditemukan, nomor telepon tersebut diganti. Jika tidak ditemukan, node baru dibuat dan ditambahkan ke dalam linked list di indeks hash yang sesuai. Fungsi remove digunakan untuk menghapus suatu nama karyawan dari hash map. Fungsi ini terlebih dahulu menghitung indeks hash dari nama karyawan, lalu mencari node yang memiliki nama yang sama. Jika ditemukan, node tersebut dihapus dari linked list di indeks hash yang sesuai. Fungsi searchByName digunakan untuk mencari nomor telepon dari suatu nama karyawan dalam hash map. Fungsi ini terlebih dahulu menghitung indeks hash dari nama karyawan, lalu mencari node yang memiliki nama yang sama. Jika ditemukan, nomor telepon tersebut dikembalikan. Jika tidak ditemukan, fungsi ini mengembalikan nilai kosong. Fungsi print digunakan untuk menampilkan semua elemen dalam hash map.


## Unguided 

### 1. 
 Implementasikan hash table untuk menyimpan data mahasiswa. Setiap mahasiswa memiliki NIM dan nilai. Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan nilai. Dengan ketentuan :
a.Setiap mahasiswa memiliki NIM dan nilai.
b.Program memiliki tampilan pilihan menu berisi poin C.
c.Implementasikan fungsi untuk menambahkan data baru, menghapus data, mencari data berdasarkan NIM, dan mencari data berdasarkan rentang nilai (80 – 90).


~~~C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk mahasiswa
struct Mahasiswa {
    string NIM;
    int nilai;
    char poin;
    bool isEmpty = true; // Flag to indicate if the slot is empty
};

// Deklarasi hash table
vector<Mahasiswa> hashTable(10); // Ukuran hash table (dapat diubah sesuai kebutuhan)

// Fungsi hash untuk menghitung indeks hash dari NIM
int hashFunction(string NIM) {
    int hash = 0;
    for (char c : NIM) {
        hash += c;
    }
    return hash % hashTable.size(); // Modulo dengan ukuran hash table
}

// Fungsi untuk menentukan poin berdasarkan nilai
char tentukanPoin(int nilai) {
    if (nilai >= 80 && nilai <= 90) {
        return 'A';
    } else if (nilai >= 66 && nilai <= 79) {
        return 'B';
    } else if (nilai >= 50 && nilai <= 65) {
        return 'C';
    } else {
        return 'F'; // Nilai diluar rentang yang ditentukan
    }
}

// Fungsi untuk menambahkan data mahasiswa baru
void tambahMahasiswa() {
    Mahasiswa mhs;
    cout << "Masukkan NIM: ";
    cin >> mhs.NIM;
    cout << "Masukkan nilai: ";
    cin >> mhs.nilai;
    mhs.poin = tentukanPoin(mhs.nilai);
    mhs.isEmpty = false;

    int index = hashFunction(mhs.NIM);
    while (!hashTable[index].isEmpty) {
        index = (index + 1) % hashTable.size(); // Linear probing
    }
    hashTable[index] = mhs;
    cout << "Mahasiswa berhasil ditambahkan!" << endl;
}

// Fungsi untuk menghapus data mahasiswa berdasarkan NIM
void hapusMahasiswa() {
    string NIM;
    cout << "Masukkan NIM yang akan dihapus: ";
    cin >> NIM;

    int index = hashFunction(NIM);
    int startIndex = index;
    bool found = false;
    while (!hashTable[index].isEmpty) {
        if (hashTable[index].NIM == NIM) {
            hashTable[index].isEmpty = true;
            found = true;
            cout << "Mahasiswa berhasil dihapus!" << endl;
            break;
        }
        index = (index + 1) % hashTable.size();
        if (index == startIndex) break; // Prevent infinite loop
    }

    if (!found) {
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
void cariMahasiswaNIM() {
    string NIM;
    cout << "Masukkan NIM yang dicari: ";
    cin >> NIM;

    int index = hashFunction(NIM);
    int startIndex = index;
    bool found = false;
    while (!hashTable[index].isEmpty) {
        if (hashTable[index].NIM == NIM) {
            cout << "NIM: " << hashTable[index].NIM << endl;
            cout << "Nilai: " << hashTable[index].nilai << endl;
            cout << "Poin: " << hashTable[index].poin << endl;
            found = true;
            break;
        }
        index = (index + 1) % hashTable.size();
        if (index == startIndex) break; // Prevent infinite loop
    }

    if (!found) {
        cout << "Mahasiswa dengan NIM tersebut tidak ditemukan." << endl;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan rentang nilai (80 - 90)
void cariMahasiswaRentangNilai() {
    bool found = false;
    cout << "Mahasiswa dengan nilai antara 80 dan 90:" << endl;
    for (const auto& mhs : hashTable) {
        if (!mhs.isEmpty && mhs.nilai >= 80 && mhs.nilai <= 90) {
            cout << "NIM: " << mhs.NIM << endl;
            cout << "Nilai: " << mhs.nilai << endl;
            cout << "Poin: " << mhs.poin << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada mahasiswa dengan nilai di antara 80 dan 90." << endl;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan nilai spesifik
void cariMahasiswaNilaiSpesifik() {
    int nilai;
    bool found = false;
    cout << "Masukkan nilai yang dicari: ";
    cin >> nilai;
    cout << "Mahasiswa dengan nilai " << nilai << ":" << endl;
    for (const auto& mhs : hashTable) {
        if (!mhs.isEmpty && mhs.nilai == nilai) {
            cout << "NIM: " << mhs.NIM << endl;
            cout << "Nilai: " << mhs.nilai << endl;
            cout << "Poin: " << mhs.poin << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Tidak ada mahasiswa dengan nilai tersebut." << endl;
    }
}

// Fungsi untuk menampilkan semua data mahasiswa
void tampilData() {
    cout << "\nDaftar Mahasiswa:" << endl;
    for (const auto& mhs : hashTable) {
        if (!mhs.isEmpty) {
            cout << "NIM: " << mhs.NIM << endl;
            cout << "Nilai: " << mhs.nilai << endl;
            cout << "Poin: " << mhs.poin << endl;
        }
    }
}

// Fungsi untuk menampilkan informasi poin
void tampilkanInfoPoin() {
    cout << "\nInformasi Poin Berdasarkan Nilai:" << endl;
    cout << "Nilai 80 - 90: Poin A" << endl;
    cout << "Nilai 66 - 79: Poin B" << endl;
    cout << "Nilai 50 - 65: Poin C" << endl;
    cout << "Nilai < 50 atau > 90: Poin F" << endl;
}

// Tampilan menu
void menu() {
    cout << "\nMenu:" << endl;
    cout << "1. Tambah Mahasiswa" << endl;
    cout << "2. Hapus Mahasiswa" << endl;
    cout << "3. Cari Mahasiswa (NIM)" << endl;
    cout << "4. Cari Mahasiswa (Rentang Nilai 80-90)" << endl;
    cout << "5. Cari Mahasiswa (Nilai Spesifik)" << endl;
    cout << "6. Tampilkan Data" << endl;
    cout << "7. Tampilkan Informasi Poin" << endl;
    cout << "8. Keluar" << endl;
    cout << "Pilihan Anda: ";
}

int main() {
    int pilihan;

    do {
        menu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahMahasiswa();
                break;
            case 2:
                hapusMahasiswa();
                break;
            case 3:
                cariMahasiswaNIM();
                break;
            case 4:
                cariMahasiswaRentangNilai();
                break;
            case 5:
                cariMahasiswaNilaiSpesifik();
                break;
            case 6:
                tampilData();
                break;
            case 7: // Menampilkan informasi poin
                tampilkanInfoPoin();
                break;
            case 8:
                cout << "Keluar dari program" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 8);
    return 0;
}
~~~
#### Output:
![Cuplikan layar 2024-06-01 150803](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/343e85ed-4e59-4773-a4fe-59ae06ae2825)
![Cuplikan layar 2024-06-01 151037](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/75d10aee-8b88-4840-b85d-ca2b64ed117d)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/8fe2ef21-ad51-473b-ba4e-7c5be356c9b4)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/3c1c7fb1-8fdc-4070-8ba5-c143d7ba2da0)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/5536e18a-caa6-414c-b63a-4564ed7d58da)

#### Interprestasikan:
Tambah Mahasiswa Fungsi ini memungkinkan pengguna untuk menambahkan data mahasiswa baru. Pengguna diminta untuk memasukkan NIM dan nilai mahasiswa. Nilai tersebut kemudian diproses untuk mendapatkan poin berdasarkan skala nilai yang telah ditentukan. Data mahasiswa baru kemudian disimpan dalam hash table.
Hapus Mahasiswa Fungsi ini memungkinkan pengguna untuk menghapus data mahasiswa berdasarkan NIM. Pengguna diminta untuk memasukkan NIM yang akan dihapus. Jika NIM tersebut ditemukan, data mahasiswa tersebut akan dihapus dari hash table.
Cari Mahasiswa (NIM) Fungsi ini memungkinkan pengguna untuk mencari data mahasiswa berdasarkan NIM. Pengguna diminta untuk memasukkan NIM yang akan dicari. Jika NIM tersebut ditemukan, data mahasiswa tersebut akan ditampilkan. Cari Mahasiswa (Rentang Nilai 80-90) Fungsi ini memungkinkan pengguna untuk mencari data mahasiswa yang memiliki nilai antara 80 dan 90. Data mahasiswa yang memenuhi kriteria tersebut akan ditampilkan.
Cari Mahasiswa (Nilai Spesifik) Fungsi ini memungkinkan pengguna untuk mencari data mahasiswa yang memiliki nilai spesifik. Pengguna diminta untuk memasukkan nilai yang akan dicari. Jika nilai tersebut ditemukan, data mahasiswa yang memenuhi kriteria tersebut akan ditampilkan.
Tampilkan Data Fungsi ini memungkinkan pengguna untuk menampilkan semua data mahasiswa yang tersimpan dalam hash table.Fungsi ini memungkinkan pengguna untuk keluar dari aplikasi.


#### Kesimpulan:
Hash table adalah struktur data yang digunakan untuk menyimpan dan mengakses data dengan efisiensi waktu operasi. Struktur ini memungkinkan pengguna untuk menambahkan, menghapus, dan mencari data dengan menggunakan kunci yang unik. Kunci ini digunakan untuk menghitung indeks array hash table yang sesuai, sehingga memungkinkan akses cepat dan efisien ke data.
Hash table mempunyai beberapa kelebihan, seperti:
Efisiensi Waktu Operasi: Hash table memungkinkan akses cepat ke data dengan menggunakan kunci yang unik. Proses ini memastikan bahwa data dapat dipertukarkan dengan aman dan efisien.
Mengatasi Collision: Hash table menggunakan teknik seperti linear probing untuk mengatasi collision, yaitu kondisi di mana nilai data yang berbeda mendapatkan nilai hashing atau posisi pada hash table yang sama.
Menggunakan Fungsi Hash: Hash table menggunakan fungsi hash untuk menghitung indeks array yang sesuai berdasarkan kunci. Fungsi hash ini harus mempunyai sifat mudah dihitung, dua key yang berbeda akan dipetakan pada dua sel yang berbeda pada array, dan meminimalkan collision.
Dalam implementasinya, hash table dapat dibuat dengan menggunakan berbagai teknik, seperti hashing, folding, dan modular arithmetic. Teknik ini digunakan untuk menghitung indeks array yang sesuai dan mengatasi collision yang mungkin terjadi.

## Sumber 
[1]. ALGORITMA PEMROGRAMAN TERSTRUKTUR, Muhammad Bahit., vol. 113. Poliban Press, 2024. 

[2]. “Struktur data – contoh program hashing,” INFO KNOWLEDGE, Jan. 02, 2013. 