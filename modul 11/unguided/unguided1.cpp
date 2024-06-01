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
