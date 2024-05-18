# <h1 align="center">Laporan Praktikum PRIORITY QUEUE DAN HEAPS</h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori
PRIORITY QUEUE DAN HEAPS

Priority Queues (pengembangan lebih lanjut dari konsep Queue) yaitu sebuah queue yang setiap komponen terdiri atas key dan value.[1].

Priority queue mirip antrian, yaitu penghapusan / pengurangan anggota selalu dilakukan pada anggota antrian yang terdepan dan penambahan anggota selalu dilakukan dari belakang antrian berdasarkan prioritas anggota tersebut, akan tetapi pada priority queue diliat dari prioritasnya (anggota yang memiliki prioritas lebih besar selalu berada di 
depan anggota yang memiliki prioritas lebih rendah).[1].

Salah satu contoh Implementasi Priority 
Queue adalah Heap Tree. Suatu heap tree adalah Complete Binary Tree (CBT) di mana nilai key pada node-nodenya 
sedemikian rupa sehingga nilai key pada node-node anaknya tidak ada yang lebih besar dari nilai key pada node orang tuanya.[1].

Heap merupakan sebuah Tree yang memenuhi syarat Binary Tree secara lengkap, terdiri atas internal node dan external node dan setiap internal node menyimpan sebuah nilai. Nilai-nilai pada setiap node-nya memenuhi syarat Heap Minimum atau Heap Maksimum. Heap Maksimum jika nilai root lebih besar dari nilai left child dan right child, sedangkan Heap 
Minimum jika nilai root lebih kecil dari nilai left child dan right child.[1].

![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/856ae73d-4cae-40d1-b771-0bf5df21cf27)

heap: Sebuah pohon biner lengkap 𝑇 yang elemennya disimpan di node internal dan memiliki kunci yang memenuhi properti urutan heap. Untuk setiap node internal v dari 𝑇, kami menyebut kunci dari elemen yang disimpan di 𝑣 sebagai 𝑘(𝑣).
last: Sebuah referensi ke node terakhir dari 𝑇
comp: Sebuah aturan perbandingan yang mendefinisikan hubungan urutan total di antara kunci-kunci. Tanpa kehilangan generalitas, kita mengasumsikan bahwa comp mempertahankan elemen minimum di akar. Jika kita ingin elemen maksimum berada di akar, maka kita dapat mendefinisikan ulang aturan perbandingan kita sesuai dengan itu.[2].


### Guided
### 1.

~~~C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;
    std::cout << "Masukkan jumlah elemen yang ingin dimasukkan: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "Masukkan elemen ke-" << i + 1 << ": ";
        std::cin >> value;
        insert(value);
    }

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int choice;
    do {
        std::cout << "\nMenu: \n";
        std::cout << "1. Ekstrak elemen dengan prioritas maksimum\n";
        std::cout << "2. Ubah prioritas elemen\n";
        std::cout << "3. Hapus elemen\n";
        std::cout << "4. Keluar\n";
        std::cout << "Masukkan pilihan Anda: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                int maxElement = extractMax();
                std::cout << "Node dengan prioritas maksimum: " << maxElement << "\n";
                std::cout << "Priority queue setelah ekstraksi maksimum: ";
                for (int i = 0; i <= heapSize; ++i) {
                    std::cout << H[i] << " ";
                }
                std::cout << "\n";
                break;
            }
            case 2: {
                int changeIndex, newPriority;
                std::cout << "Masukkan indeks elemen yang ingin diubah prioritasnya: ";
                std::cin >> changeIndex;
                std::cout << "Masukkan prioritas baru: ";
                std::cin >> newPriority;
                changePriority(changeIndex, newPriority);
                std::cout << "Priority queue setelah perubahan prioritas: ";
                for (int i = 0; i <= heapSize; ++i) {
                    std::cout << H[i] << " ";
                }
                std::cout << "\n";
                break;
            }
            case 3: {
                int removeIndex;
                std::cout << "Masukkan indeks elemen yang ingin dihapus: ";
                std::cin >> removeIndex;
                remove(removeIndex);
                std::cout << "Priority queue setelah menghapus elemen: ";
                for (int i = 0; i <= heapSize; ++i) {
                    std::cout << H[i] << " ";
                }
                std::cout << "\n";
                break;
            }
            case 4: {
                std::cout << "Keluar dari program.\n";
                break;
            }
            default: {
                std::cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            }
        }
    } while (choice != 4);

    return 0;
}
~~~
### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/45aafd76-9356-4634-be34-048f5ca3cac4)

### interprestasi:
 struktur data «heap» atau «priority queue» menggunakan array. Heap ini adalah max-heap, yang berarti elemen terbesar selalu berada di posisi paling atas . Jika elemen pada i lebih besar dari elemen parent-nya, maka kedua elemen ditukar. shiftDown menggeser elemen pada indeks i ke bawah dalam heap hingga heap property terpenuhi. Jika salah satu anak lebih besar dari elemen pada i. insert menambahkan elemen baru p ke dalam heap dan mengatur elemen tersebut pada posisi yang benar dengan memanggil shiftUp. extractMax mengeluarkan elemen maksimum dari heap dan mengatur ulang heap untuk mempertahankan heap property. Jika heap kosong, mencetak pesan kesalahan. remove menghapus elemen pada indeks i dari heap.  

Heap akan ditampilkan dalam urutan yang menunjukkan struktur max-heap. Outputnya akan menjadi:
45 adalah elemen terbesar dan berada di root.
31 dan 14 adalah anak-anak dari 45.
13 dan 20 adalah anak-anak dari 31.
7 dan 11 adalah anak-anak dari 14.
12 dan 7 adalah anak-anak dari 13.
Elemen maksimum (45) dikeluarkan dari heap. Heap akan disusun ulang untuk mempertahankan properti max-heap.Elemen pada indeks 2 yang awalnya adalah 14 diubah menjadi 49 dan heap disusun ulang. Elemen pada indeks 3 (yang saat ini adalah 13) dihapus dari heap. Heap disusun ulang untuk mempertahankan properti max-heap.


## Unguided 

### 1.  [Modifikasi guided diatas yang mana heap dikonstruksi secara manual berdasarkan user.]
~~~C++
#include <iostream>
#include <algorithm>

int H[50];
int heapSize = -1;

int parent(int i) {
    return (i - 1) / 2;
}

int leftChild(int i) {
    return (2 * i) + 1;
}

int rightChild(int i) {
    return (2 * i) + 2;
}

void shiftUp(int i) {
    while (i > 0 && H[parent(i)] < H[i]) {
        std::swap(H[parent(i)], H[i]);
        i = parent(i);
    }
}

void shiftDown(int i) {
    int maxIndex = i;
    int l = leftChild(i);
    if (l <= heapSize && H[l] > H[maxIndex]) {
        maxIndex = l;
    }
    int r = rightChild(i);
    if (r <= heapSize && H[r] > H[maxIndex]) {
        maxIndex = r;
    }
    if (i != maxIndex) {
        std::swap(H[i], H[maxIndex]);
        shiftDown(maxIndex);
    }
}

void insert(int p) {
    heapSize = heapSize + 1;
    H[heapSize] = p;
    shiftUp(heapSize);
}

int extractMax() {
    int result = H[0];
    H[0] = H[heapSize];
    heapSize = heapSize - 1;
    shiftDown(0);
    return result;
}

void changePriority(int i, int p) {
    int oldp = H[i];
    H[i] = p;
    if (p > oldp) {
        shiftUp(i);
    } else {
        shiftDown(i);
    }
}

int getMax() {
    return H[0];
}

void remove(int i) {
    H[i] = getMax() + 1;
    shiftUp(i);
    extractMax();
}

int main() {
    int n;
    std::cout << "Masukkan jumlah elemen yang ingin dimasukkan: ";
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int value;
        std::cout << "Masukkan elemen ke-" << i + 1 << ": ";
        std::cin >> value;
        insert(value);
    }

    std::cout << "Priority Queue : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    std::cout << "Node dengan prioritas maksimum : " << extractMax() << "\n";

    std::cout << "Priority queue setelah ekstraksi maksimum: ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int changeIndex, newPriority;
    std::cout << "Masukkan indeks elemen yang ingin diubah prioritasnya: ";
    std::cin >> changeIndex;
    std::cout << "Masukkan prioritas baru: ";
    std::cin >> newPriority;
    changePriority(changeIndex, newPriority);

    std::cout << "Priority queue setelah perubahan prioritas : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    std::cout << "\n";

    int removeIndex;
    std::cout << "Masukkan indeks elemen yang ingin dihapus: ";
    std::cin >> removeIndex;
    remove(removeIndex);

    std::cout << "Priority queue setelah menghapus elemen : ";
    for (int i = 0; i <= heapSize; ++i) {
        std::cout << H[i] << " ";
    }
    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/f65bb86c-b76c-4d1f-9a32-2a9ad2f78328)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/cf6c59ff-c3b5-4892-8729-0879b2fd426e)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/25d8c17e-03e5-49c3-918a-f201605dad0e)

#### Interprestasikan:
Memasukkan Elemen ke Heap untuk  diminta untuk memasukkan jumlah elemen dan nilai elemen satu per satu. Setelah semua elemen dimasukkan, heap ditampilkan.
Menu Interaktif untuk  memilih opsi dari menu untuk melakukan operasi tertentu pada heap.
Ekstraksi Elemen Maksimum untuk Opsi ini mengeluarkan elemen dengan prioritas tertinggi dari heap, dan menampilkan heap setelah operasi.
Mengubah Prioritas Elemen untuk  mengubah prioritas elemen di heap dengan memasukkan indeks elemen dan nilai prioritas baru, dan menampilkan heap setelah perubahan.
Menghapus Elemen untuk menghapus elemen dari heap dengan memasukkan indeks elemen yang ingin dihapus, dan menampilkan heap setelah operasi.
Keluar dari Program untuk Mengakhiri program.

Diminta untuk memasukkan jumlah elemen yang akan dimasukkan ke dalam heap, dalam hal ini 5 elemen.
kemudian diminta untuk memasukkan nilai dari setiap elemen satu per satu:
Elemen ke-1: 30
Elemen ke-2: 77
Elemen ke-3: 44
Elemen ke-4: 23
Elemen ke-5: 11
Setelah semua elemen dimasukkan, heap ditampilkan dalam bentuk array. Nilai-nilai ditampilkan dalam urutan yang mencerminkan struktur heap, dengan elemen dengan prioritas tertinggi di root. Pengguna memilih opsi untuk mengekstrak elemen dengan prioritas maksimum (pilihan 2).
Program mengeluarkan dan menampilkan elemen dengan prioritas tertinggi, yaitu 77. Setelah ekstraksi, heap diperbarui dan ditampilkan kembali. Elemen dengan prioritas tertinggi berikutnya (44) sekarang menjadi root heap.

Memilih opsi untuk mengubah prioritas elemen (pilihan 2).
Program meminta pengguna untuk memasukkan indeks elemen yang ingin diubah prioritasnya (indeks 4).
Program meminta pengguna untuk memasukkan prioritas baru (100).
Heap diperbarui sehingga elemen dengan nilai baru 100 dipindahkan ke posisi yang sesuai, dan heap ditampilkan kembali.

Memilih opsi untuk menghapus elemen (pilihan 3).
Program meminta pengguna untuk memasukkan indeks elemen yang ingin dihapus (indeks 1).
Elemen pada indeks tersebut dihapus dari heap, dan heap diperbarui serta ditampilkan kembali.

Memilih opsi untuk keluar dari program (pilihan 4).
Program menampilkan pesan bahwa program akan keluar, dan eksekusi dihentikan


#### Kesimpulan:

Priority Queues yaitu sebuah queue yang setiap komponen terdiri atas key dan value. .


Salah satu contoh Implementasi Priority

Queue adalah Heap Tree. Suatu heap tree adalah Complete Binary Tree di mana nilai key pada node-nodenya sedemikian rupa sehingga nilai key pada node-node anaknya tidak ada yang lebih besar dari nilai key pada node orang tuanya. .
Heap merupakan sebuah Tree yang memenuhi syarat Binary Tree secara lengkap, terdiri atas internal node dan external node dan setiap internal node menyimpan sebuah nilai. Nilai-nilai pada setiap node-nya memenuhi syarat Heap Minimum atau Heap Maksimum.

comp: Sebuah aturan perbandingan yang mendefinisikan hubungan urutan total di antara kunci-kunci. Tanpa kehilangan generalitas, kita mengasumsikan bahwa comp mempertahankan elemen minimum di akar.

## Sumber :

[1]. A. Furqan, “Heap & Priority queue struktur data,” www.academia.edu, Dec. 2014.

[2]. “The panic of 1907,” Federal Reserve History. https://www.federalreservehistory.org/essays/panic-of-1907. 