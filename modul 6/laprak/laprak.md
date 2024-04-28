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
### 2. 

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
## Unguided 

### 1.  [Setelah membuat menu tersebut, masukkan data sesuai urutan berikut, lalu  tampilkan data yang telah dimasukkan. (Gunakan insert depan, belakang atau tengah) ]

![Cuplikan layar 2024-04-27 232534](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/5efd50eb-4f6a-4710-b55d-286344a23acb)

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
void insertBelakang(string data, int nim) {
    //Buat Node Baru
    buatNode(data, nim);

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
void insertTengah(string data, int nim, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        buatNode(data, nim);

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
Deklarasi Struct Node: Mendefinisikan struktur data Node, yang memiliki dua variabel, yaitu data dan nim, serta satu pointer next yang menunjuk ke Node selanjutnya. head: Menyimpan alamat node pertama.
tail: Menyimpan alamat node terakhir.
baru, bantu, hapus: Variabel untuk operasi tambah dan hapus data. Fungsi init(): Menginisialisasi head dan tail menjadi NULL. Fungsi isEmpty(): Memeriksa apakah linked list kosong. Fungsi buatNode(): Membuat node baru dengan data dan NIM yang diberikan. 
baru, bantu, hapus: Variabel untuk operasi tambah dan hapus data. Fungsi init(): Menginisialisasi head dan tail menjadi NULL. Fungsi isEmpty(): Memeriksa apakah linked list kosong. Fungsi buatNode(): Membuat node baru dengan data dan NIM yang diberikan. Fungsi insertDepan(): Menambahkan node baru di depan linked list. Fungsi insertBelakang(): Menambahkan node baru di belakang linked list. Fungsi insertTengah(): Menambahkan node baru di tengah linked list pada posisi tertentu. Fungsi hapusDepan(): Menghapus node pertama dari linked list. Fungsi clearList(): Menghapus seluruh isi linked list. Fungsi tampil(): Menampilkan isi dari linked list. Fungsi main(): Penggunaan fungsi-fungsi yang telah didefinisikan untuk mengoperasikan linked list.

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
void insertBelakang(string data, int nim) {
    //Buat Node Baru
    buatNode(data, nim);

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
        tail = baru;
    }
}

// Tambah Tengah
void insertTengah(string data, int nim, int posisi) {
    if (isEmpty() == 1) {
        head = baru;
        tail = head;
        baru->next = head;
    } else {
        buatNode(data, nim);

        //transvering
        int nomor = 1;
        bantu = head;

        while (nomor < posisi - 1) {
            bantu = bantu->next;
            nomor++;
        }

        baru->next = bantu->next;
        bantu->next = baru;
        if (baru->next == head) // Jika elemen ditambahkan di akhir
            tail = baru; // Perbarui tail
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
            tail = tail->next; // Perbarui tail
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
        if (hapus == tail) // Jika elemen yang dihapus adalah elemen terakhir
            tail = bantu; // Perbarui tail
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
        tail = NULL; // Perbarui tail
    }

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

    // a) Tambahkan data Wati di antara Farrel dan Denis
    insertTengah("Wati", 23300004, 4);
    tampil();

    // b) Hapus data Denis
    hapusTengah(4);
    tampil();

    // c) Tambahkan data Owi di awal
    insertDepan("Owi", 23300000);
    tampil();

    // d) Tambahkan data David di akhir
    insertBelakang("David", 23300100);
    tampil();

    // e) Ubah data Udin menjadi Idin 23300045
    hapusTengah(8);
    insertTengah("Idin", 23300045, 8);
    tampil();

    // f) Ubah data terakhir menjadi Lucy 23300101
    hapusBelakang();
    insertBelakang("Lucy", 23300101);
    tampil();

    // g) Hapus data awal
    hapusDepan();
    tampil();

    // h) Ubah data awal menjadi Bagas 2330002
    hapusDepan();
    insertDepan("Bagas", 23300002);
    tampil();

    // i) Hapus data akhir
    hapusBelakang();
    tampil();

    // j) Tampilkan seluruh data
    cout << "Tampilkan seluruh data:" << endl;
    tampil();

    return 0;
}
~~~
#### Output:
![Cuplikan layar 2024-04-28 150428](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/1ecf8551-4f99-47ec-8d67-e94f69ecd9cd)
![Cuplikan layar 2024-04-28 150428](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/6a4a9c11-099d-4ed2-b285-5ad4839661a2)
![Cuplikan layar 2024-04-28 151028](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/cf6d39c5-6550-4cb1-840f-acd0db555798)
![Cuplikan layar 2024-04-28 151040](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/61aa6218-633e-4f63-aebb-099195d0e61e)
![Cuplikan layar 2024-04-28 151052](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/f2d698cd-37f4-4044-baf2-9325252b7b1e)
![Cuplikan layar 2024-04-28 151059](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/566bf686-70b4-4e47-8e10-81dbcd5fd4ea)

#### Interprestasikan:
insertDepan(data, nim) Menambahkan node baru di depan list. Fungsi ini membuat node baru, kemudian mengatur pointer next dari node baru ke head, dan terakhir memperbarui head dan tail.
insertBelakang(data, nim) Menambahkan node baru di belakang list. Fungsi ini membuat node baru, kemudian mencari node terakhir (tail), mengatur pointer next dari node baru ke head, dan terakhir memperbaruitail`.
insertTengah(data, nim, posisi) Menambahkan node baru di posisi tertentu dalam list. Fungsi ini mencari node pada posisi sebelum posisi yang diberikan, kemudian membuat node baru, mengatur pointer next dari node baru ke node berikutnya, dan terakhir memperbarui pointer next dari node sebelum ke node baru.
hapusDepan() Menghapus node pertama dalam list. Fungsi ini menyimpan pointer ke node pertama (head), kemudian mengatur head ke pointer next dari node pertama, dan terakhir menghapus node pertama.
hapusBelakang() Menghapus node terakhir dalam list. Fungsi ini mencari node terakhir (tail), kemudian mengatur pointer next dari node sebelum terakhir ke head, dan terakhir menghapus node terakhir.
hapusTengah(posisi) Menghapus node di posisi tertentu dalam list. Fungsi ini mencari node pada posisi sebelum posisi yang diberikan, kemudian mengatur pointer next dari node sebelum ke node berikutnya dari node yang akan dihapus, dan terakhir menghapus node yang akan dihapus. tampil() Menampilkan seluruh data dalam list. Fungsi ini memulai dari node head dan terus mengikuti pointer next hingga kembali ke head. Pada setiap node, data dan nim ditampilkan. init()Inisialisasi list dengan setting head dan tail ke NULL.
isEmpty()Mengecek apakah list kosong dengan memeriksa apakah head sama dengan NULL. buatNode(data, nim) Membuat node baru dengan data dan nim yang diberikan. hitungList() Menghitung jumlah node dalam list dengan cara incrementing counter setiap kali node baru dijumpai.
clearList() Menghapus seluruh node dalam list. Fungsi ini terus menghapus node satu per satu hingga list kosong.
fungsi di atas digunakan untuk mendemonstrasikan fungsionalitasnya:
Menambahkan data
insertDepan("Jawad", 23300001) untuk Menambahkan node baru bernama "Jawad" dengan NIM 23300001 di depan list.
insertBelakang("Ersa", 2311110009) untuk Menambahkan node baru bernama "Ersa" dengan NIM 2311110009 di belakang list.
insertBelakang("Farrel", 23300003)untuk Menambahkan node baru bernama "Farrel" dengan NIM 23300003 di belakang list. ... (dan seterusnya)
Menambahkan data di tengah , insertTengah("Wati", 23300004, 4) untuk Menambahkan node baru bernama "Wati" dengan NIM 23300004 di antara

#### Kesimpulan:
Circular list dan single linked list non circular adalah dua struktur data yang berbeda dengan kelebihan dan kekurangannya masing-masing. Circular list menawarkan fleksibilitas dalam melewatkan elemen, sedangkan single linked list non circular lebih sederhana dan mudah diimplementasikan. Pilihan struktur data yang tepat tergantung pada kebutuhan spesifik aplikasi.
#### Sumber:
[1] A. S. R. St. MTi, STRUKTUR DATA DAN ALGORITMA DENGAN C++. CV. AA. RIZKY, 2019.

[2] R. I. Oktavian, “MODUL PRAKTIKUM STRUKTUR DATA BAHASA PEMROGRAMAN C++", Fkipunlam, Dec. 2017.

