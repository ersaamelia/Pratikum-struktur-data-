# <h1 align="center">Laporan Praktikum Modul Queue</h1>
<p align="center">Ersa Amelia</p>

### Dasar Teori

## Queue

Queue disebut juga antrian dimana data masuk di satu sisi dan keluar di sisi yang lain. Queue bersifat FIFO
(First In First Out). Antrian (Queue) merupakan suatu kumpulan data yang penambahan elemennya (masuk
antrian) hanya bisa dilakukan pada suatu ujung (disebut dengan sisi belakang/rear) atau disebut juga
enqueue yaitu apabila seseorang masuk ke dalam sebuah antrian dan keluar dari antrian adalah dequeue.[1]

QUEUE merupakan struktur data dinamis, ketika
program dijalankan, jumlah elemennya dapat berubah secara dinamis sesuai keperluan.

 Berikut ini operasi-operasi standar
pada queue :

a. Inisialisasi, merupakan prosedur untuk membuat queue
pada kondisi awal, yaitu queue yang masih kosong
(belum mempunyai elemen).

b. InQueue, Insert Queue merupakan prosedur untuk
memasukkan sebuah elemen baru pada queue. Jumlah
elemen Queue akan bertambah satu dan elemen tersebut
merupakan elemen belakang.

c. DeQueue, Delete Queue merupakan prosedur untuk
menghapus/mengambil sebuah elemen dari queue.
Elemen yang diambil adalah elemen depan dan jumlah
elemen queue akan berkurang satu.[2].

# Operasi-operasi yang berhubungan dengan jumlah
elemen suatu queue adalah :
1. Size, yaitu operasi untuk mendapatkan banyaknya
elemen queue.
2. Empty, yaitu prosedur untuk mengetahui apakah queue
dalam keadaan kosong atau tidak. Dengan status ini
maka dapat dicegah dilakukannya operasi Dequeue dari
suatu queue yang kosong.
3. Full, merupakan prosedur untuk mengetahui apakah
Queue penuh atau tidak.
Prosedur ini hanya berlaku untuk queue yang jumlahnya
terbatas.[2].

![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/a9139a97-568e-4b28-a42c-70a33d3ea326)

Struktur data queue setidaknya harus memiliki operasi-operasi sebagai berikut :
EnQueue : Memasukkan data ke dalam antrian
DeQueue : Mengeluarkan data terdepan dari antrian
Clear : Menghapus seluruh antrian
IsEmpty : Memeriksa apakah antrian kosong
IsFull : Memeriksa apakah antrian penuh. [1].


### Guided
### 1. 

~~~C++
#include <iostream>

using namespace std;

const int maksimalQueue = 5;
int front = 0;
int back = 0;

string queueTeller[5];

bool isfull() {
    if(back == maksimalQueue) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty() {
    if (back == 0) {
        return true;
    }else {
        return false;
    }
}

void enqueueAntrian(string data) {
    if (isfull()) {
        cout << "Antrian Penuh" << endl;
    } else {
        if (isEmpty()) {
            queueTeller[0] = data;
            front++;
            back++;
        } else {
            queueTeller[back] = data;
            back++;
        }
    }
}

void dequeueAntrian() {
    if(isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for(int i =0; i < back; i++) {
            queueTeller[i] = queueTeller[i+ 1];
        }
        back--;
    }
}

int countQueue() {
    return back;
}

void clearQueue() {
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
            queueTeller[i] = "";
        }
        back =0;
        front = 0;
    }
}

void viewQueue() {
    cout << "data antrian teller: " << endl;
    for(int i =0; i < maksimalQueue; i++) {
        if(queueTeller[i] !="") {
            cout << i + 1 << "." << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}

int main() {
    enqueueAntrian("Andi");
    enqueueAntrian("Maya");
    viewQueue();
    cout << "jumlah antrian =" << countQueue() << endl;
    dequeueAntrian();
    viewQueue();
    cout << "jumlah antrian = " << countQueue() << endl;
    clearQueue();
    viewQueue();
    cout << "jumlah antrian = " << countQueue() << endl;
    return 0; 
}
~~~
### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/f6e2412e-df26-46a0-813d-4104d0303f94)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/357abf71-6258-463d-955c-5b31fba6d589)

### interprestasi:
Fungsi enqueueAntrian(string data) untuk Menambahkan data ke dalam antrian. Jika antrian penuh, maka akan menampilkan pesan "Antrian Penuh". Fungsi dequeueAntrian() untuk Menghapus data dari antrian. Jika antrian kosong, maka akan menampilkan pesan "Antrian kosong". Fungsi countQueue() untuk  Mengembalikan jumlah elemen dalam antrian.
Fungsi clearQueue() untuk Mengosongkan antrian. Fungsi viewQueue() untuk Menampilkan data dalam antrian beserta nomor antriannya. Jika antrian kosong, nomor antriannya akan ditampilkan dengan status "(kosong)".
main() function untuk Memanggil fungsi-fungsi di atas untuk menambah, menghapus, mengosongkan, dan menampilkan antrian, kemudian menampilkan jumlah antrian setiap saat.

Pada awalnya, Andi dan Maya dimasukkan ke dalam antrian, sehingga jumlah antrian menjadi 2.
Setelah itu, Andi dikeluarkan dari antrian menggunakan operasi dequeue. Sekarang, hanya Maya yang tersisa dalam antrian, sehingga jumlah antrian menjadi 1.
Kemudian, antrian dikosongkan menggunakan operasi clearQueue, sehingga tidak ada lagi yang tersisa dalam antrian dan jumlah antrian menjadi 0.

## Unguided 

### 1.  [Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list]
~~~C++
#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
    const int maksimalQueue;

public:
    Queue(int maksimal) : maksimalQueue(maksimal) {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isFull() {
        return size == maksimalQueue;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(string data) {
        if (isFull()) {
            cout << "Antrian Penuh" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    int count() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* current = front;
        cout << "Data antrian teller:" << endl;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". " << current->data << endl;
            current = current->next;
            i++;
        }
    }
};

int main() {
    Queue myQueue(5);
    myQueue.enqueue("Andi");
    myQueue.enqueue("Maya");
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl;
    myQueue.dequeue();
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl;
    myQueue.clear();
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl;
    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/ecd580fa-e9a5-478d-9f07-4a0f69359275)

#### Interprestasikan:
Struktur Node digunakan untuk membuat simpul dalam linked list, yang berisi data antrian dan pointer ke simpul berikutnya.Kelas Queue memiliki anggota-anggota untuk mewakili antrian, yaitu front (depan antrian), rear (belakang antrian), size (jumlah elemen dalam antrian), dan maksimalQueue (maksimal ukuran antrian).
Metode-metode dalam kelas Queue adalah:
isFull() untuk Memeriksa apakah antrian penuh.
isEmpty() untuk Memeriksa apakah antrian kosong.
enqueue(string data) untuk Menambahkan data ke dalam antrian.
dequeue() untuk Menghapus data dari antrian.
count()untuk Mengembalikan jumlah elemen dalam antrian.
clear() untuk Mengosongkan antrian.
display() untuk Menampilkan data dalam antrian.
Pada main() function, sebuah objek myQueue dibuat dengan ukuran maksimal antrian 5. Data "Andi" dan "Maya" dimasukkan ke dalam antrian. Kemudian, data dalam antrian ditampilkan beserta jumlah antrian, lalu data pertama ("Andi") dihapus dari antrian. Setelah itu, data dalam antrian kembali ditampilkan beserta jumlah antrian, dan akhirnya antrian dikosongkan dan ditampilkan kembali beserta jumlah antrian.

Data "Andi" dan "Maya" dimasukkan ke dalam antrian, sehingga jumlah antrian menjadi 2.
Data pertama ("Andi") dihapus dari antrian, sehingga jumlah antrian menjadi 1.
Antrian dikosongkan, sehingga jumlah antrian menjadi 0.

### 2.  [Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa]
~~~C++
#include <iostream>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
    const int maksimalQueue;

public:
    Queue(int maksimal) : maksimalQueue(maksimal) {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isFull() {
        return size == maksimalQueue;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(Mahasiswa data) {
        if (isFull()) {
            cout << "Antrian Penuh" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    int count() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* current = front;
        cout << "Data antrian mahasiswa:" << endl;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". Nama: " << current->data.nama << endl;
            cout << "   NIM: " << current->data.nim << endl;
            current = current->next;
            i++;
        }
    }
};

int main() {
    Queue myQueue(5);

    Mahasiswa m1 = {"Andi", "12345"};
    Mahasiswa m2 = {"Maya", "67890"};
    Mahasiswa m3 = {"Ersa", "2311110009"};

    myQueue.enqueue(m1);
    myQueue.enqueue(m2);
    myQueue.enqueue(m3);

    cout << "Data awal:" << endl;
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl << endl;

    myQueue.dequeue();

    cout << "Setelah dequeue:" << endl;
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl << endl;

    myQueue.clear();

    cout << "Setelah clear:" << endl;
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl << endl;

    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/d4a0476d-e29d-4c5d-97ac-0d2d336f142c)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/b7bf63cb-a9f9-4033-bcbb-65f65ef18c49)


#### Interprestasikan:
Struktur Mahasiswa digunakan untuk menyimpan data mahasiswa, yaitu nama dan NIM.
Struktur Node digunakan untuk membuat simpul dalam linked list, yang berisi data mahasiswa dan pointer ke simpul berikutnya.
Kelas Queue memiliki anggota-anggota untuk mewakili antrian, yaitu front (depan antrian), rear (belakang antrian), size (jumlah elemen dalam antrian), dan maksimalQueue (maksimal ukuran antrian). isFull() untuk  Memeriksa apakah antrian penuh.
isEmpty() untuk  Memeriksa apakah antrian kosong.
enqueue(Mahasiswa data): Menambahkan data mahasiswa ke dalam antrian. dequeue() untuk Menghapus data dari antrian.
count() untuk Mengembalikan jumlah elemen dalam antrian. clear() untuk Mengosongkan antrian.
display() untuk Menampilkan data mahasiswa dalam antrian beserta NIM mereka.
Pada main() function, sebuah objek myQueue dibuat dengan ukuran maksimal antrian 5. Tiga data mahasiswa ("Andi", "Maya", dan "Ersa") dimasukkan ke dalam antrian. Kemudian, data dalam antrian ditampilkan beserta jumlah antrian, lalu data pertama ("Andi") dihapus dari antrian. Setelah itu, antrian dikosongkan dan ditampilkan kembali beserta jumlah antrian.

tiga data mahasiswa dimasukkan ke dalam antrian:
Nama: Andi, NIM: 12345
Nama: Maya, NIM: 67890
Nama: Ersa, NIM: 2311110009
Jumlah antrian saat ini adalah 3.


Setelah operasi dequeue dilakukan, data pertama dari antrian (Andi) dihapus. Sekarang antrian hanya berisi dua data mahasiswa:
Nama: Maya, NIM: 67890
Nama: Ersa, NIM: 2311110009
Jumlah antrian saat ini adalah 2.

Setelah operasi clear dilakukan, seluruh data dalam antrian dihapus sehingga antrian menjadi kosong. Jumlah antrian saat ini adalah 0.

#### Kesimpulan:
Antrian (Queue) merupakan suatu kumpulan data yang penambahan elemennya (masuk antrian) hanya bisa dilakukan pada suatu ujung (disebut dengan sisi belakang/rear) atau disebut juga enqueue yaitu apabila seseorang masuk ke dalam sebuah antrian dan keluar dari antrian adalah dequeue.
Jumlah elemen Queue akan bertambah satu dan elemen tersebut merupakan elemen belakang. 
elemen suatu queue adalah :
1. Size, yaitu operasi untuk mendapatkan banyaknya
elemen queue.
2. Empty, yaitu prosedur untuk mengetahui apakah queue
dalam keadaan kosong atau tidak. Dengan status ini
maka dapat dicegah dilakukannya operasi Dequeue dari
suatu queue yang kosong.
3. Full, merupakan prosedur untuk mengetahui apakah
Queue penuh atau tidak.
Prosedur ini hanya berlaku untuk queue yang jumlahnya
terbatas.

#### sumber:

[1].Pemrograman C++ ALGORITMA & STRUKTUR DATA, Rizki Muliono, S.Kom, M.Kom. 2018.

[2]. A. S. R. St. MTi, STRUKTUR DATA DAN ALGORITMA DENGAN C++. CV. AA. RIZKY, 2017.