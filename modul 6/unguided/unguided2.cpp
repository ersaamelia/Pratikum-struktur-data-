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
