# <h1 align="center">Laporan Praktikum Modul Circular dan Non Circular</h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori
Circular dan Non Circular

Circular list adalah bentuk lain dari linked list yang 
memberikan fleksibilitas dalam melewatkan elemen. 
Circular list bisa berupa single linked list atau double linked 
list, tetapi tidak mempunyai tail. Pada circular list, pointer 
next dari elemen terakhir menunjuk ke elemen pertama dan 
bukan menunjuk NULL. Pada double linked circular list, 
pointer prev dari elemen pertama menunjuk ke elemen 
terakhir. susunan dari single linked circular list, hanya 
menangani link dari elemen terakhir kembali ke elemen 
pertama. [1]

Single Linked List Non 
Circular artinya field pointer-nya hanya satu buah saja dan satu arah dan saling terhubung satu 
sama lain, untuk setiap node pada linked list mempunyai field yang berisi pointer ke node 
berikutnya, dan juga memiliki field yang berisi data. Pada akhir linked list, node terakhir akan 
menunjuk ke NULL yang akan digunakan sebagai kondisi berhenti pada saat pembacaan isi 
linked list. [2]

Linked list adalah struktur data linier yang terdiri dari sejumlah simpul (node) yang saling terhubung melalui referensi atau pointer. Setiap simpul dalam linked list menyimpan data dan memiliki sebuah pointer yang menunjuk ke simpul berikutnya dalam urutan linear. Konsep dasar dari linked list adalah bahwa setiap simpul mengandung dua bagian utama: data dan pointer. Data mewakili informasi yang ingin disimpan, misalnya bilangan, teks, atau objek lainnya. Pointer, juga disebut sebagai “next pointer,” menunjuk ke simpul berikutnya dalam urutan. [3] 

### Guided
### 1. 

~~~C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node {
    int data;
    Node *next;
};

Node *head;
Node *tail;

// Inisialisasi Node
void init() {
    head = NULL;
    tail = NULL;
}

// Pengecekan apakah list kosong
bool isEmpty() {
    return (head == NULL);
}

// Tambah Data di Depan
void insertDepan(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        baru->next = head;
        head = baru;
    }
}

// Tambah Data di Belakang
void insertBelakang(int nilai) {
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty()) {
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Hitung Jumlah Node
int hitungList() {
    Node *hitung = head;
    int jumlah = 0;
    while (hitung != NULL) {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}

// Tambah Data di Tengah
void insertTengah(int data, int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi diluar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *baru = new Node();
        baru->data = data;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Node di Depan
void hapusDepan() {
    if (!isEmpty()) {
        Node *hapus = head;
        if (head->next != NULL) {
            head = head->next;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Belakang
void hapusBelakang() {
    if (!isEmpty()) {
        Node *hapus = tail;
        if (head != tail) {
            Node *bantu = head;
            while (bantu->next != tail) {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
        } else {
            head = tail = NULL;
        }
        delete hapus;
    } else {
        cout << "List kosong!" << endl;
    }
}

// Hapus Node di Tengah
void hapusTengah(int posisi) {
    if (posisi < 1 || posisi > hitungList()) {
        cout << "Posisi di luar jangkauan" << endl;
    } else if (posisi == 1) {
        cout << "Posisi bukan posisi tengah" << endl;
    } else {
        Node *hapus;
        Node *bantu = head;
        for (int nomor = 1; nomor < posisi - 1; nomor++) {
            bantu = bantu->next;
        }
        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    }
}

// Ubah Data di Depan
void ubahDepan(int data) {
    if (!isEmpty()) {
        head->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Tengah
void ubahTengah(int data, int posisi) {
    if (!isEmpty()) {
        if (posisi < 1 || posisi > hitungList()) {
            cout << "Posisi di luar jangkauan" << endl;
        } else if (posisi == 1) {
            cout << "Posisi bukan posisi tengah" << endl;
        } else {
            Node *bantu = head;
            for (int nomor = 1; nomor < posisi; nomor++) {
                bantu = bantu->next;
            }
            bantu->data = data;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Ubah Data di Belakang
void ubahBelakang(int data) {
    if (!isEmpty()) {
        tail->data = data;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Semua Node
void clearList() {
    Node *hapus;
    while (head != NULL) {
        hapus = head;
        head = head->next;
        delete hapus;
    }
    tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}

// Tampilkan List
void tampil() {
    Node *bantu = head;
    if (!isEmpty()) {
        while (bantu != NULL) {
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        cout << endl;
    } else {
        cout << "List masih kosong!" << endl;
    }
}

int main() {
    init();
    insertDepan(3); tampil();
    insertBelakang(5); tampil();
    insertDepan(2); tampil();
    insertDepan(1); tampil();
    hapusDepan(); tampil();
    hapusBelakang(); tampil();
    insertTengah(7, 2); tampil();
    hapusTengah(2); tampil();
    ubahDepan(1); tampil();
    ubahBelakang(8); tampil();
    ubahTengah(11, 2); tampil();
    clearList();
    return 0;
}
~~~
### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/6bb4450a-6774-4552-a13e-b83355babcd2)
### interprestasi:
kodingan ini fungsi node berfungsi untuk menyimpan data dan referensi ke node. fungsi head itu untuk menunjuk ke node pertama dalam daftar. fungsi tail menunjuk ke node terakhir dalam daftar. init() inisialisasi daftar keadaan kosong, head dan tail diset ke NULL. isEmpaty itu berfungsi membalikan true jika head null dan false sebaliknya. fungsi insertDepan berfungsi menambahkan data baru ke bagian depan terdaftar, buat node baru dengan niali yang diberikan, dan jika daftar tidak kosong set node baru sebagai head dan upted head ke node baru. hitunglist berfungsi menghitung jumlah node dalam daftar. insertTengah menghubungkan node baru ke node sebelumnya dan node berikutnya, dan perbarui head jika posisi pertama. fungsi hapusDepan untuk menghapus data dari bagian depan, fungsi hapusBelakanguntuk menghapus data dari bagian belakang, dan fungsi hapusTengah untuk menghapus data diposisi tertentu dalam daftar. fungsi ubah untuk mengubah nilai data dibagian depan daftar. clearlist berfungsi untuk menghapus semua node dalam daftar. 

### 2. single linked list circular

~~~C++
#include <iostream>
using namespace std;

///Program Single Linked List Circular

// Deklarasi Struct Node
struct Node {
    string data;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init(){
    head = NULL;
    tail = head;
}

//Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; //true
    else
        return 0; //false
}

// Buat Node Baru
void buatNode(string data) {
    baru = new Node;
    baru->data = data;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL){
        jumlah++;
        bantu = bantu -> next;
    }

    return jumlah;
}

// Tambah depan
void insertDepan(string data) {
    //Buat Node baru
    buatNode(data);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        baru->next = head;
        head = baru;
        tail->next = head;
    }
}

// Tambah belakang
void insertBelakang(string data) {
    //Buat Node Baru
    buatNode(data);

    if(isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        while (tail->next != head) {
            tail = tail->next;
        }

        tail->next = baru;
        baru->next = head;
    }
}

// Tambah Tengah
void insertTengah(string data, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        baru->data = data;

        //transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
    }
}

// Hapus Depan
void hapusDepan() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if(hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (tail->next != hapus) {
                tail = tail->next;
            }

            head = head->next;
            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong!" << endl;
    }
}

// Hapus Belakang
void hapusBelakang() {
    if (isEmpty() == 0) {
        hapus = head;
        tail = head;

        if (hapus->next == head) {
            head = NULL;
            tail = NULL;
            delete hapus;
        } else {
            while (hapus->next != head) {
                hapus = hapus->next;
            }
            
            while (tail->next != hapus) {
                tail = tail->next;
            }

            tail->next = head;
            hapus->next = NULL;
            delete hapus;
        }
    } else {
        cout << "List masih kosong !" << endl;
    }
}

//Hapus tengah
void hapusTengah(int posisi) {
    if (isEmpty() == 0) {
        // transvering 
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor ++;
        } 

        hapus = bantu->next;
        bantu->next = hapus->next;
        delete hapus;
    } else {
        cout << "List masih kosong! " << endl;
    }
}

// Hapus List
void clearList() {
    if (head != NULL) {
        hapus = head->next;

        while (hapus != head) {
            bantu = hapus->next;
            delete hapus;
            hapus = bantu;
        }

        delete head;
        head = NULL;
    }

    cout << "List berhasil dihapus !" << endl; 
}

// Tampilkan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << ends;
            tail = tail->next;
        } while (tail != head) ;

        cout << endl;
    } else {
        cout << "List masih kosong !" << endl;
    }
}

int main() {
    init();
    insertDepan("Ayam");
    tampil();
    insertDepan("Bebek");
    tampil();
    insertBelakang("Cicak");
    tampil();
    insertBelakang("Domba");
    tampil();
    hapusBelakang();
    tampil();
    hapusDepan();
    tampil();
    insertTengah("Sapi", 2);
    tampil();
    hapusTengah(2);
    tampil();
    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/a028b8ba-2509-42b7-99c9-6c5094e54733)

#### Interprestasi:
kodingan ini menggunakan single list linked circular. fungsi init sendiri untuk menganisialisasi daftar kosong, dalam fungsinya ada variabel head dan tail diset menjadi NULL.fungsi isEmpaty untuk memriksa akah daftar kosong atau tidak. fungsi buatnode untuk membuat node baru dengan data yang diberikan. fungsi hitunglist untuk menghitung jumlah node dalam daftar. fungsi insertdepan untuk menambahkan node baru di depan. fungsi insertbelakang untuk menambahkan node baru dibelakang. fungsi inserttengah untuk menambahkan node baru ditengah pada posisiyang ditentukan. fungsi hapusdepan untuk menghapus node di depan. penjelasan output ayam dimasukkan di depan, memasukkan bebek di depan untuk menambahkan sebelum ayam. memsukkan cicak di belakang ke urutan terakhir . bebek ayam menghapus cicak node terakhir. ayam menghapus elemn depan bebek node pertama. memasukkan sapi pada posisi 2 antara ayam .   

3. guided doubel linked
   ~~~C++
   #include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push(int data) {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void pop() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
    }

    bool update(int oldData, int newData) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == oldData) {
                current->data = newData;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void deleteAll() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
        tail = nullptr;
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    while (true) {
        cout << "1. Add data" << endl;
        cout << "2. Delete data" << endl;
        cout << "3. Update data" << endl;
        cout << "4. Clear data" << endl;
        cout << "5. Display data" << endl;
        cout << "6. Exit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data to add: ";
                cin >> data;
                list.push(data);
                break;
            }
            case 2: {
                list.pop();
                break;
            }
            case 3: {
                int oldData, newData;
                cout << "Enter old data: ";
                cin >> oldData;
                cout << "Enter new data: ";
                cin >> newData;
                bool updated = list.update(oldData, newData);
                if (!updated) {
                    cout << "Data not found" << endl;
                }
                break;
            }
            case 4: {
                list.deleteAll();
                break;
            }
            case 5: {
                list.display();
                break;
            }
            case 6: {
                return 0;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
    }
    return 0;
}
~~~
    Doubly linked list adalah jenis dari linked list di mana setiap node memiliki dua pointer, yaitu pointer prev yang menunjukkan ke node sebelumnya dan pointer next yang menunjukkan ke node selanjutnya. blueprint dari node dalam doubly linked list. Memiliki tiga atribut: data untuk menyimpan nilai data, prev untuk menunjukkan ke node sebelumnya, dan next untuk menunjukkan ke node selanjutnya. Memiliki dua pointer head untuk  menunjukkan ke node pertama dalam linked list dan tail yang menunjukkan ke node terakhir dalam linked list. Constructor DoublyLinkedList() untuk Menginisialisasi head dan tail menjadi nullptr.
Method push(int data) untuk Menambahkan node baru di depan linked list dengan nilai data yang diberikan. Jika linked list masih kosong, maka tail akan menunjuk ke node baru. Jika linked list tidak kosong, maka node baru akan menjadi prev dari head yang lama. Node baru akan menjadi head yang baru.
Method pop() untukMenghapus node pertama dari linked list. Jika linked list masih kosong, tidak dilakukan apa-apa. Jika linked list tidak kosong, maka head akan menunjuk ke node berikutnya dari node yang dihapus. Jika node yang dihapus adalah node terakhir, maka tail akan diatur menjadi nullptr.
Method update(int oldData, int newData) untuk Mengganti nilai data node dengan oldData menjadi newData. Jika data yang dicari tidak ditemukan, maka akan dikembalikan false. Method deleteAll() untuk  Menghapus semua node dari linked list. Setelah semua node dihapus, head dan tail diatur menjadi nullptr.
Method display() untuk Menampilkan semua nilai data dari linked list. main() Function untuk Berisi menu interaktif untuk menambah, menghapus, mengubah, dan menampilkan data dalam doubly linked list.
## Unguided 

### 2. Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) 

![Cuplikan layar 2024-04-27 232534](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/5efd50eb-4f6a-4710-b55d-286344a23acb)

~~~C++
#include <iostream>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    Mahasiswa* next;
};

class LinkedList {
private:
    Mahasiswa* head;
    Mahasiswa* tail;
    int count; // Menyimpan jumlah elemen dalam linked list

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

<<<<<<< HEAD
    cout << "List berhasil dihapus !" << endl; 
}

// Tampilkan List
void tampil() {
    if (isEmpty() == 0) {
        tail = head;

        do {
            cout << tail->data << "\t" << tail->nim << endl;
            tail = tail->next;
        } while (tail != head) ;

        cout << endl;
    } else {
        cout << "List masih kosong !" << endl;
    }
}

int main() {
    init();
    insertDepan("Jawad", 23300001);
    tampil();
    insertBelakang("Ersa", 2311110009);
    tampil();
    insertBelakang("Farrel", 23300003);
    tampil();
    insertBelakang("Denis", 23300005);
    tampil();
    insertBelakang("Anis", 23300008);
    tampil();
    insertBelakang("Bowo", 23300015);
    tampil();
    insertBelakang("Gahar", 23300040);
    tampil();
    insertBelakang("Udin", 23300048);
    tampil();
    insertBelakang("Ucok", 23300050);
    tampil();
    insertBelakang("Budi", 23300099);
    tampil();
    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/030640f7-a02b-4d14-9e4f-b9347dcdbde9)

#### Interprestasikan:
Deklarasi Struct Node: Mendefinisikan struktur data Node, yang memiliki dua variabel, yaitu data dan nim, serta satu pointer next yang menunjuk ke Node selanjutnya. head untuk Menyimpan alamat node pertama. tail untuk Menyimpan alamat node terakhir. baru, bantu, hapus: Variabel untuk operasi tambah dan hapus data. Fungsi init() untuk Menginisialisasi head dan tail menjadi NULL. Fungsi isEmpty(): Memeriksa apakah linked list kosong. Fungsi buatNode() untuk Membuat node baru dengan data dan NIM yang diberikan. Baru bantu, hapus untuk Variabel untuk operasi tambah dan hapus data. Fungsi init() untukMenginisialisasi head dan tail menjadi NULL. Fungsi isEmpty() untuk Memeriksa apakah linked list kosong. Fungsi buatNode(): Membuat node baru dengan data dan NIM yang diberikan. Fungsi insertDepan() untuk  Menambahkan node baru di depan linked list. Fungsi insertBelakang() untuk Menambahkan node baru di belakang linked list. Fungsi insertTengah() untuk  Menambahkan node baru di tengah linked list pada posisi tertentu. Fungsi hapusDepan() untuk Menghapus node pertama dari linked list. Fungsi clearList() untuk Menghapus seluruh isi linked list. Fungsi tampil() untuk Menampilkan isi dari linked list. Fungsi main() untuk Penggunaan fungsi-fungsi yang telah didefinisikan untuk mengoperasikan linked list.

### 2.  [Lakukan perintah berikut: 
a) Tambahkan data berikut diantara Farrel dan Denis: 
Wati 2330004 
b) Hapus data Denis 
c) Tambahkan data berikut di awal: 
Owi 2330000 
d) Tambahkan data berikut di akhir: 
David 23300100 
e) Ubah data Udin menjadi data berikut: 
Idin 23300045 
f) Ubah data terkahir menjadi berikut: 
Lucy 23300101 
g) Hapus data awal 
h) Ubah data awal menjadi berikut: 
Bagas 2330002 
i) Hapus data akhir 
j) Tampilkan seluruh data]

~~~C++
#include <iostream>
using namespace std;

///Program Single Linked List Circular

// Deklarasi Struct Node
struct Node {
    string data;
    int nim;
    Node *next;
};

Node *head, *tail, *baru, *bantu, *hapus;

void init(){
    head = NULL;
    tail = head;
}

//Pengecekan
int isEmpty() {
    if (head == NULL)
        return 1; //true
    else
        return 0; //false
}

// Buat Node Baru
void buatNode(string data, int nim) {
    baru = new Node;
    baru->data = data;
    baru->nim = nim;
    baru->next = NULL;
}

// Hitung List
int hitungList() {
    bantu = head;
    int jumlah = 0;

    while (bantu != NULL){
        jumlah++;
        bantu = bantu -> next;
    }

    return jumlah;
}

// Tambah depan
void insertDepan(string data, int nim) {
    //Buat Node baru
    buatNode(data, nim);

    if (isEmpty() == 1) {
        head = baru;
        tail = head;
=======
    void tambahDepan(string nama, string nim) {
        Mahasiswa* baru = new Mahasiswa;
        baru->nama = nama;
        baru->nim = nim;
>>>>>>> 091b38a (lari lari)
        baru->next = head;
        head = baru;
        if (tail == NULL) {
            tail = head;
        }
        count++;
        cout << "Data telah ditambahkan" << endl;
    }

    void tambahBelakang(string nama, string nim) {
        Mahasiswa* baru = new Mahasiswa;
        baru->nama = nama;
        baru->nim = nim;
        baru->next = NULL;
        if (tail != NULL) {
            tail->next = baru;
        }
        tail = baru;
        if (head == NULL) {
            head = tail;
        }
        count++;
        cout << "Data telah ditambahkan" << endl;
    }

    void tambahTengah(string nama, string nim, int posisi) {
        if (posisi < 1 || posisi > count + 1) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        Mahasiswa* baru = new Mahasiswa;
        baru->nama = nama;
        baru->nim = nim;
        Mahasiswa* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        baru->next = temp->next;
        temp->next = baru;
        count++;
        cout << "Data telah ditambahkan" << endl;
    }

    void hapusDepan() {
        if (head == NULL) {
            cout << "List kosong" << endl;
            return;
        }
        Mahasiswa* temp = head;
        head = head->next;
        cout << "Data " << temp->nama << " berhasil dihapus" << endl;
        delete temp;
        count--;
    }

    void hapusBelakang() {
        if (head == NULL) {
            cout << "List kosong" << endl;
            return;
        }
        Mahasiswa* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
        cout << "Data berhasil dihapus" << endl;
        count--;
    }

    void hapusTengah(int posisi) {
        if (head == NULL) {
            cout << "List kosong" << endl;
            return;
        }
        if (posisi < 1 || posisi > count) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        Mahasiswa* temp = head;
        for (int i = 1; i < posisi - 1; i++) {
            temp = temp->next;
        }
        Mahasiswa* hapus = temp->next;
        temp->next = hapus->next;
        cout << "Data " << hapus->nama << " berhasil dihapus" << endl;
        delete hapus;
        count--;
    }

    void ubahDepan(string nama, string nim) {
        if (head == NULL) {
            cout << "List kosong" << endl;
            return;
        }
        head->nama = nama;
        head->nim = nim;
        cout << "Data telah diubah" << endl;
    }

    void ubahBelakang(string nama, string nim) {
        if (head == NULL) {
            cout << "List kosong" << endl;
            return;
        }
        tail->nama = nama;
        tail->nim = nim;
        cout << "Data telah diubah" << endl;
    }

    void ubahTengah(string nama, string nim, int posisi) {
        if (head == NULL) {
            cout << "List kosong" << endl;
            return;
        }
        if (posisi < 1 || posisi > count) {
            cout << "Posisi tidak valid" << endl;
            return;
        }
        Mahasiswa* temp = head;
        for (int i = 1; i < posisi; i++) {
            temp = temp->next;
        }
        temp->nama = nama;
        temp->nim = nim;
        cout << "Data telah diubah" << endl;
    }

    void tampilkan() {
        if (head == NULL) {
            cout << "List kosong" << endl;
            return;
        }
        cout << "\tDATA MAHASISWA" << endl;
        cout << setw(5) << left << "No" << setw(20) << left << "NAMA" << setw(15) << "NIM" << endl;
        cout << setfill('-') << setw(40) << "-" << endl;
        Mahasiswa* temp = head;
        int no = 1;
        while (temp != NULL) {
            cout << setfill(' ') << setw(5) << left << no << setw(20) << temp->nama << setw(15) << temp->nim << endl;
            temp = temp->next;
            no++;
        }
    }
};

int main() {
    LinkedList list;
    int pilihan, posisi;
    string nama, nim;

    do {
        cout << "\nPROGRAM SINGLE LINKED LIST NON-CIRCULAR" << endl;
        cout << "1. Tambah Depan" << endl;
        cout << "2. Tambah Belakang" << endl;
        cout << "3. Tambah Tengah" << endl;
        cout << "4. Ubah Depan" << endl;
        cout << "5. Ubah Belakang" << endl;
        cout << "6. Ubah Tengah" << endl;
        cout << "7. Hapus Depan" << endl;
        cout << "8. Hapus Belakang" << endl;
        cout << "9. Hapus Tengah" << endl;
        cout << "10. TAMPILKAN" << endl;
        cout << "0. KELUAR" << endl;
        cout << "Pilih Operasi : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n1. Tambah Depan" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.tambahDepan(nama, nim);
                break;
            case 2:
                cout << "\n2. Tambah Belakang" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.tambahBelakang(nama, nim);
                break;
            case 3:
                cout << "\n3. Tambah Tengah" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                list.tambahTengah(nama, nim, posisi);
                break;
            case 4:
                cout << "\n4. Ubah Depan" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.ubahDepan(nama, nim);
                break;
            case 5:
                cout << "\n5. Ubah Belakang" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                list.ubahBelakang(nama, nim);
                break;
            case 6:
                cout << "\n6. Ubah Tengah" << endl;
                cout << "Masukkan Nama : ";
                cin >> nama;
                cout << "Masukkan NIM : ";
                cin >> nim;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                list.ubahTengah(nama, nim, posisi);
                break;
            case 7:
                cout << "\n7. Hapus Depan" << endl;
                list.hapusDepan();
                break;
            case 8:
                cout << "\n8. Hapus Belakang" << endl;
                list.hapusBelakang();
                break;
            case 9:
                cout << "\n9. Hapus Tengah" << endl;
                cout << "Masukkan Posisi : ";
                cin >> posisi;
                list.hapusTengah(posisi);
                break;
            case 10:
                cout << "\n10. Tampilkan" << endl;
                list.tampilkan();
                break;
            case 0:
                cout << "Terima kasih!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
                break;
        }
    } while (pilihan != 0);

    return 0;
}
~~~~
###Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/011b02cf-9c23-4664-b556-086cf635ff4e)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/0ea88af1-dba9-40ce-b4b8-52e03c6ed28c)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/3824c74a-c12d-456d-a25c-292151fa5318)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/817dcab3-0a40-43f7-8775-1402b8f5ec2d)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/dda36945-ce5a-4596-aefb-512351000173)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/807cad8a-d1c8-4bf8-a25b-bc529c61bf31)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/98edd911-cb69-4d15-865b-4bcb968fa49c)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/b3f52d95-7b18-4adf-8eb2-eb4f817f4853)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/44d3c623-d1f4-4c47-af76-b849ad00682d)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/ad3bfccb-16a5-4e25-b8b7-afb93aec3e41)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/0a88d8c4-c145-40d5-87f1-e1f0e97fa4bd)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/7d80de99-ec5e-4eec-ac10-3153dc4353b0)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/7d50bf0d-6f1e-46cb-a86f-e4ef422d2df4)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/0941763b-3582-4440-8c63-1102b1c2419a)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/c7489bce-70b1-4974-ad7a-ddeede5ebe38)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/7cafd2c6-0da7-40fb-879e-bc73c492426a)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/0ec4feab-1591-4513-98ae-f6367bb78006)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/c52c5af7-066d-435e-8ff6-a5802328177a)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/033fd04c-ca3c-416f-a87f-5dac8caa2486)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/a39bf455-08c4-4635-93e4-acfa23e83d3f)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/3ad8ce34-d56b-4bb3-882d-7a7d8aded141)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/4b1dad7e-863e-4b75-8058-2203d9dd005d)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/f7e58cca-34f6-4c4b-89f4-e500ed6ef2d9)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/9a361ed5-6fc9-4195-a7c1-a6647b138f29)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/7296412f-1469-4408-96ad-daac5ebc69a8)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/aa561626-bef5-47b4-881f-25a4d9232d2e)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/8f81ce4f-9098-49fa-8658-9db9b8cd16e6)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/c79e0963-3f7b-47d2-8a15-63cafd03eac7)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/85bfcf7c-7737-4c19-bc0e-df710477b478)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/94c1dcf6-0f8a-4802-b131-c4175185307e)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/7a910884-0b42-46f3-ab09-1f21076f0051)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/427e1be4-4ab8-4a5b-83cf-faeff451a22d)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/31ea9b22-19ac-4b99-a41f-885bc6dee00a)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/b4c7ffc9-e3f1-4c27-b345-0162e06a5e81)

####Interprestasi:

struct mahasiswa untuk menyimpan informasi mengenai nama dan nim dari seorang mahasiswa. next untuk menunjukkan elemen selanjutnya dalam linked list. class untuk implementasi dari linked list. head yang menunjukkan elemen pertama dalam linked list. pointer tail yang menunjukkan elemen terakhir dalam linked list. variabel count yang menyimpan jumlah elemen dalam linked list. Constructor LinkedList() head, tail, dan count menjadi NULL dan 0. Method tambahDepan(string nama, string nim) untuk menambahkan elemen baru di depan linked list dengan nama dan NIM yang diberikan. Jika tail masih NULL, maka tail akan menunjuk ke head. Method tambahTengah(string nama, string nim, int posisi) untuk Menambahkan elemen baru di tengah linked list pada posisi yang ditentukan. Jika posisi yang dimasukkan tidak valid, maka akan ditampilkan pesan kesalahan. Method hapusDepan()untuk Menghapus elemen pertama dari linked list. Method tampilkan() untuk Menampilkan semua elemen dalam linked list dalam bentuk tabel.
Setiap elemen akan ditampilkan dengan nomor urutan, nama, dan NIM. Jika linked list kosong, akan ditampilkan pesan "List kosong".

#### Kesimpulan:
Circular list dan single linked list non circular adalah dua struktur data yang berbeda dengan kelebihan dan kekurangannya masing-masing. Circular list menawarkan fleksibilitas dalam melewatkan elemen, sedangkan single linked list non circular lebih sederhana dan mudah diimplementasikan. Pilihan struktur data yang tepat tergantung pada kebutuhan spesifik aplikasi.

#### Sumber:
[1] A. S. R. St. MTi, STRUKTUR DATA DAN ALGORITMA DENGAN C++. CV. AA. RIZKY, 2019.

[2] R. I. Oktavian, “MODUL PRAKTIKUM STRUKTUR DATA BAHASA PEMROGRAMAN C++", Fkipunlam, Dec. 2017.

[3] Riczky Pratama, "Panduan Lengkap Mengenai Linked List: Definisi, Implementasi, dan Penggunaan dalam Pemrograman", Mei.2023.

