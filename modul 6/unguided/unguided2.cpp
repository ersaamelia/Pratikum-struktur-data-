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

    void tambahDepan(string nama, string nim) {
        Mahasiswa* baru = new Mahasiswa;
        baru->nama = nama;
        baru->nim = nim;
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
