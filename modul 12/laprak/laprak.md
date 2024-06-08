# <h1 align="center">Laporan Praktikum Modul Graph dan Tree </h1>
<p align="center">Ersa Amelia</p>

## Dasar Teori

# Definisi Tree
Tree merupakan salah satu bentuk struktur data tidak linear yang menggambarkan hubungan yang bersifat
hierarkis (hubungan one to many) antara elemen-elemen. Tree bias didefinisikan sebagai kumpulan
simpul/node dengan elemen khusus yang disebut Root. Notde lainnya terbagi menjadi himpunan-himpunan
yang saling tak berhubungan satu sama lain (disebut Subtree). Untuk lebih jelasnya, di bawah akan diuraikan
istilah-istilah umum dalam tree:

a. Predecessor Node yang berada di atas node tertentu.
b. Successor Node yang berada dibawah node tertentu.
c. Ancestor Seluruh node yang terletak sebelum node tertentu dan terletak pada jalur yang sama.
d. Descendant Seluruh node yang terletak sebelum node tertentu dan terletak pada jalur yang sama.
e. Parent Predecessor satu level di atas suatu node.
f. Child Successor satu level di bawah suatu node.
g. Sibling Node-node yang memiliki parent yang sama dengan suatu node.
h. Subtree Bagian dari tree yang berupa suatu node beserta descendantnya dan memiliki semua
karakteristik dari tree tersebut.
i. Size Banyaknya node dalam suatu tree.
j. Height Banyaknya tingkatan / level dalam suatu tree.
k. Root Satu-satunya node khusus dalam tree yang tak punyak predecessor.
l. Leaf Node-node dalam tree yang tak memiliki successor.
m. Degree Banyaknya child yang dimiliki suatu node.[1].

![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/d0d8e853-6b72-4a10-93c7-cc6b8bf04fda)

• Akar pohon adalah simpul tanpa orang tua. Paling banyak ada satu simpul akar dalam
sebuah pohon (simpul A dalam contoh di atas).

• Tepi mengacu pada tautan dari induk ke anak (semua tautan dalam gambar).

• Sebuah simpul tanpa anak disebut simpul daun (E,J,K,H dan I).

• Anak dari orang tua yang sama disebut saudara kandung (B,C,D adalah saudara dari A,
dan E,F adalah saudara dari B).

• Sebuah node p adalah ancestor dari node q jika terdapat sebuah path dari root ke q dan p muncul pada path tersebut. Simpul q disebut turunan dari p. Misalnya, A,C dan G adalah nenek moyang dari if.

• Himpunan semua node pada kedalaman tertentu disebut level pohon (B, C dan D adalah level yang sama). Node akar berada pada level nol.[2]

![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/447df1f0-6359-4455-952d-651e128d8505)

• Kedalaman suatu simpul adalah panjang lintasan dari akar ke simpul tersebut (kedalaman G adalah 2, A – C – G).

• Ketinggian suatu simpul adalah panjang lintasan dari simpul tersebut ke simpul terdalam. Ketinggian pohon adalah panjang jalan dari akar ke simpul terdalam dipohon. Sebuah pohon (berakar) dengan hanya satu simpul (akar) memiliki ketinggian nol. Pada contoh sebelumnya, tinggi B adalah 2 (B – F – J).

• Tinggi pohon adalah tinggi maksimum di antara semua simpul di pohon dan kedalaman pohon adalah kedalaman maksimum di antara semua simpul di pohon. Untuk pohon tertentu, kedalaman dan tinggi mengembalikan nilai yang sama. Tetapi untuk node individu Kita mungkin mendapatkan hasil yang berbeda.

• Ukuran dari sebuah simpul adalah jumlah keturunan yang dimilikinya termasuk dirinya sendiri (ukuran dari subpohon C adalah 3).

• Jika setiap simpul dalam sebuah pohon hanya memiliki satu anak (kecuali simpul daun) maka kita menyebutnya pohon miring. Jika setiap simpul hanya memiliki anak kiri maka kita menyebutnya pohon miring kiri. Demikian pula, jika setiap simpul hanya memiliki anak kanan maka kita menyebutnya pohon miring kanan.[2]

![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/c6303051-7f68-429b-bf21-a3030dc69146)

 ### Jenis-Jenis Tree
# Binary Tree
Binary Tree adalah tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua subtree dan
kedua subtree tersebut harus terpisah. Sesuai dengan definisi tersebut tiap node dalam binary tree hanya
boleh memiliki paling banyak dua child.
Jenis- Jenis Binary Tree :
Full Binary Tree
Jenis binary tree ini tiap nodenya (kecuali leaf) memiliki dua child dan tiap subtree harus mempunyai panjang
path yang sama.

Complete Binary Tree
Jenis ini mirip dengan Full Binary Tree, namun tiap subtree boleh memiliki panjang path yang berbeda dan
setiap node kecuali leaf hanya boleh memiliki 2 child.

Skewed Binary Tree
Skewed Binary Tree adalah Binary Tree yang semua nodenya (kecuali leaf) hanya memiliki satu child.

Implementasi Binary Tree
Binary tree dapat diimplementasikan dalam C++ dengan menggunakan double linkedlist.[1]

SIFAT POHON BINER
Untuk sifat-sifat berikut, mari kita asumsikan bahwa tinggi pohon adalah h. Juga, asumsikan bahwa simpul akar berada pada ketinggian nol.

![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/6c3810fe-b727-4e5b-a3a3-14b8368b4af4)

![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/4d066b9c-0cbb-4fa7-8ae1-86270bcc7867)

Dari diagram kita dapat menyimpulkan sifat-sifat berikut:
• Jumlah node n dalam pohon biner penuh adalah 2h+1 – 1. Karena ada h level, kita perlu menambahkan semua node di setiap level [20 + 21+ 22 + ••• + 2h = 2h+1 – 1].
• Jumlah node n dalam pohon biner lengkap adalah antara 2h (minimum) dan 2h+1 – 1 (maksimum). Untuk informasi lebih lanjut tentang ini, lihat bab Antrian Prioritas.
• Jumlah simpul daun dalam pohon biner penuh adalah 2 jam.
• Jumlah link NULL (pointer terbuang) dalam pohon biner lengkap dari n node adalah n + 1.[2]. 

Struktur Pohon Biner
Sekarang mari kita mendefinisikan struktur pohon biner. Untuk mempermudah,
asumsikan bahwa data dari node adalah bilangan bulat. Salah satu cara untuk
merepresentasikan sebuah node (yang berisi data) adalah dengan memiliki dua link yang
mengarah ke anak kiri dan kanan bersama dengan bidang data seperti yang ditunjukkan di
bawah ini:

![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/5031eb7e-97ba-4295-a497-e3efbaa3f1b7)

Catatan: Di pohon, aliran default adalah dari induk ke anak dan tidak wajib untuk menampilkan
cabang terarah. Untuk diskusi Kita, Kita menganggap kedua representasi yang ditunjukkan di
bawah ini sama.[2]. 

## Teori graph
teori graph atau teori grafik dalam matematika dan ilmu komputer adalah cabang kajian yang mempelajari
sifat-sifat "graf" atau "grafik". Ini tidak sama dengan "Grafika". Secara informal, suatu graf adalah himpunan
benda-benda yang disebut "simpul" (vertex atau node) yang terhubung oleh "sisi" (edge) atau "busur" (arc).
Biasanya graf digambarkan sebagai kumpulan titik-titik (melambangkan "simpul") yang dihubungkan oleh
garis-garis (melambangkan "sisi") atau garis berpanah (melambangkan "busur"). Suatu sisi dapat
menghubungkan suatu simpul dengan simpul yang sama. Sisi yang demikian dinamakan "gelang" (loop).
Banyak sekali struktur yang bisa direpresentasikan dengan graf, dan banyak masalah yang bisa diselesaikan
dengan bantuan graf. Jaringan persahabatan pada Facebook bisa direpresentasikan dengan graf, yakni
simpul-simpulnya adalah para pengguna Facebook dan ada sisi antar pengguna jika dan hanya jika mereka
berteman. Perkembangan algoritme untuk menangani graf akan berdampak besar bagi ilmu komputer.
Sebuah struktur graf bisa dikembangkan dengan memberi bobot pada tiap sisi. Graf berbobot dapat
digunakan untuk melambangkan banyak konsep berbeda. Sebagai contoh jika suatu graf melambangkan
jaringan jalan maka bobotnya bisa berarti panjang jalan maupun batas kecepatan tertinggi pada jalan
tertentu. Ekstensi lain pada graf adalah dengan membuat sisinya berarah, yang secara teknis disebut graf
berarah atau digraf (directed graph). Digraf dengan sisi berbobot disebut jaringan.
Jaringan banyak digunakan pada cabang praktis teori graf yaitu analisis jaringan. Perlu dicatat bahwa pada
analisis jaringan, definisi kata "jaringan" bisa berbeda, dan sering berarti graf sederhana (tanpa bobot dan
arah).[1].

## Graph Pencarian Jalur Terpendek

![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/1322e28b-0f11-48a0-9e12-be46cdb214dc)

Di atas kita dapat melihat grafik dan matriks biaya yang lengkap yang mencakup jarak antara masing-masing
desa. Kita dapat mengamati bahwa matriks biaya adalah simetris yang berarti jarak antara desa 2 hingga 3 sama dengan jarak antara desa 3 hingga 2.
Masalah di sini adalah penjual keliling ingin mengetahui turnya dengan biaya minimum.
Katakanlah T (1, {2,3,4}), artinya, awalnya dia di desa 1 dan kemudian dia bisa pergi ke salah satu dari {2,3,4}.
Dari sana untuk mencapai simpul yang tidak dikunjungi (desa) menjadi masalah baru. Di sini kita dapat mengamati bahwa masalah utama meluas menjadi sub-masalah, ini adalah milik pemrograman dinamis.

Catatan: Saat menghitung di bawah nilai sisi kanan dihitung dengan cara bottom-up. Nilai warna merah
diambil dari perhitungan di bawah.

T (1, {2,3,4}) = minimum
= {(1,2) + T (2, {3,4}) 4 + 6 = 10}
= {(1,3) + T (3, {2,4}) 1 + 3 = 4}
= {(1,4) + T (4, {2,3}) 3 + 3 = 6}

Di sini minimal di atas 3 jalur adalah jawaban tetapi kita hanya tahu nilai (1,2), (1,3), (1,4) hal yang tersisa
yaitu T (2, {3,4})… adalah masalah baru sekarang . Pertama kita harus menyelesaikannya dan
menggantikannya di sini.

T (2, {3,4}) = minimum
= {(2,3) + T (3, {4}) 2 + 5 = 7}
= {(2,4) + T (4, {3}) 1 + 5 = 6}

T (3, {2,4}) = minimum
= {(3,2) + T (2, {4}) 2 + 1 = 3}
= {(3,4) + T (4, {2}) 5 + 1 = 6}

T (4, {2,3}) = minimum
= {(4,2) + T (2, {3}) 1 + 2 = 3}
= {(4,3) + T {3, {2}} 5 + 2 = 7}

T (3, {4}) = (3,4) + T (4, {}) 5 + 0 = 5
T (4, {3}) = (4,3) + T (3, {}) 5 + 0 = 5
T (2, {4}) = (2,4) + T (4, {}) 1 + 0 = 1
T (4, {2}) = (4,2) + T (2, {}) 1 + 0 = 1
T (2, {3}) = (2,3) + T (3, {}) 2 + 0 = 2
T (3, {2}) = (3,2) + T (2, {}) 2 + 0 = 2

Di sini T (4, {}) mencapai kondisi dasar dalam rekursi, yang mengembalikan 0 (nol) jarak.

Di sinilah kita dapat menemukan jawaban akhir, T (1, {2,3,4}) = minimum
= {(1,2) + T (2, {3,4}) 4 + 6 = 10} di jalur ini kita harus menambahkan +1 karena jalur ini berakhir dengan 3.

Dari sana kita harus mencapai 1 jadi 3-> 1 jarak 1 akan ditambahkan jarak total adalah 10 + 1 = 11
= {(1,3) + T (3, {2,4}) 1 + 3 = 4} di jalur ini kita harus menambahkan +3 karena jalur ini berakhir dengan 3.

Dari sana kita harus mencapai 1 jadi 4-> 1 jarak 3 akan ditambahkan jarak total 4 + 3 = 7
= {(1,4) + T (4, {2,3}) 3 + 3 =} 6 di jalur ini kita harus menambahkan +1 karena jalur ini berakhir dengan 3.

Dari sana kita harus mencapai 1 jadi 3-> 1 jarak 1 akan ditambahkan jarak total 6 + 1 = 7
Jarak minimum adalah 7 yang mencakup jalur 1-> 3-> 2-> 4-> 1.

Tapi itu tidak menjamin bahwa setiap titik terhubung ke titik lain maka kita mengambil biaya itu sebagai tak terhingga. Setelah itu, kami mengambil minimal di antara semua sehingga jalur yang tidak terhubung mendapatkan infinity dalam perhitungan dan tidak akan dipertimbangkan.

Jika S kosong itu berarti kami mengunjungi semua node, kami mengambil jarak dari node yang terakhir
dikunjungi ke node 1 (node pertama). Karena setelah mengunjungi semua dia harus kembali ke simpul
awal.[1]. 


### Guided
### 1. 

~~~C++
#include <iostream>
#include <iomanip>

using namespace std;

string simpul[7] = {
    "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", "Yogyakarta"
};

int busur[7][7] = {
    {0, 7, 8, 0, 0, 0, 0},
    {0, 0, 5, 0, 0, 15, 0},
    {0, 6, 0, 0, 5, 0, 0},
    {0, 5, 0, 0, 2, 4, 0},
    {23, 0, 0, 10, 0, 0, 8},
    {0, 0, 0, 0, 7, 0, 3},
    {0, 0, 0, 0, 9, 4, 0}
};

void tampilGraph(){
    for (int baris = 0; baris < 7; baris++) {
        cout << " " << setiosflags(ios::left) << setw(15) << simpul[baris] << " : ";
        for (int kolom = 0; kolom < 7; kolom++) {
            if (busur[baris][kolom] != 0) {
                cout << " " << simpul[kolom] << " (" << busur[baris][kolom] << ")"; 
            }
        }
        cout << endl;
    }
}

int main() {
    tampilGraph();
    return 0;
}
~~~
### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/8317d8ae-b31e-4913-81df-9c3430ba3897)

### interprestasi:
Program di atas mendefinisikan dan menampilkan graf berbobot yang merepresentasikan hubungan antara beberapa kota. Setiap simpul (kota) dihubungkan oleh busur (jalan) yang memiliki bobot tertentu (jarak atau waktu perjalanan). Fungsi tampilGraph() digunakan untuk mencetak setiap simpul dan busur yang terhubung ke simpul tersebut beserta bobotnya.
simpul Array 7 string yang mewakili nama-nama kota: "Ciamis", "Bandung", "Bekasi", "Tasikmalaya", "Cianjur", "Purwokerto", dan "Yogyakarta".
busur Array 2D integer yang mewakili koneksi antar kota. Setiap elemen busur[baris][kolom] mewakili jarak (dalam menit) antara kota di baris dan kota di kolom. Jika tidak ada koneksi, nilai adalah 0.
Fungsi ini bertanggung jawab untuk menampilkan grafik kota dan koneksi mereka.
Fungsi ini mengulangi setiap kota (baris) dan mencetak namanya, diikuti oleh nama-nama kota yang terhubung dan jarak mereka. Fungsi main memanggil fungsi tampilGraph() untuk menampilkan grafik.

Output dari program ini adalah daftar kota dengan informasi mengenai kota mana yang terhubung dengannya dan berapa bobot (jarak atau waktu) dari masing-masing hubungan tersebut. Contoh output mungkin terlihat seperti ini:

    Ciamis        : Bandung (7) Bekasi (8) 
    Bandung       : Bekasi (5) Tasikmalaya (15) 
    Bekasi        : Bandung (6) Cianjur (5) 
    Tasikmalaya   : Bandung (5) Cianjur (2)     Purwokerto (4) 
    Cianjur       : Tasikmalaya (10) Yogyakarta (8) 
    Purwokerto    : Cianjur (7) Yogyakarta (4) 
    Yogyakarta    : Cianjur (9) Purwokerto (4) 


### 2. 

~~~C++

#include <iostream>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    //constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node -> data << " ";
        preOrder(node -> left);
        preOrder(node -> right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node -> left);
        cout << node -> data << " ";
        inOrder(node -> right);
    }
}

void postOrder(TNode *node) {
    if ( node != NULL) {
        postOrder(node -> left);
        postOrder(node -> right);
        cout << node -> data << " ";
    }
}

int main () {
    TNode *zero = new TNode(0);
    //0
    // /\
    // NULL NULL

    TNode *one = new TNode(1);
    TNode *five = new TNode(5);
    TNode *seven = new TNode(7);
    TNode *eight = new TNode(8);
    TNode *nine = new TNode(9);

    seven -> left = one;
    //
    //
    //
    //

    seven -> right = nine;




    one -> left = zero;





    one -> right = five;
    //
    //
    //
    //
    //

    nine -> left = eight;
    //
    //
    //
    //
    //
    //

    preOrder(seven);
    cout << endl;
    inOrder(seven);
    cout << endl;
    postOrder(seven);
    cout << endl;

    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/a684930f-9473-4640-b5a8-a3d94e537474)

#### Interprestasi:
Program ini membuat dan menampilkan traversal dari sebuah pohon biner. Struktur TNode mendefinisikan node dengan nilai integer dan dua pointer ke anak kiri dan kanan. Program menginisialisasi beberapa node dan mengatur relasi antar node untuk membentuk pohon. Fungsi preOrder, inOrder, dan postOrder digunakan untuk melakukan traversal dan mencetak nilai dari setiap node dalam urutan pre-order, in-order, dan post-order.

Struktur Data TNode
TNode adalah struktur data yang mewakili setiap node dalam binary tree. Setiap node memiliki tiga atribut: data untuk menyimpan nilai node, left untuk mengacu ke node kiri, dan right untuk mengacu ke node kanan.
Konstruktor TNode digunakan untuk membuat node baru dengan nilai yang diberikan.
Fungsi Traversal
preOrder: Fungsi ini melakukan traversal pre-order pada binary tree. Fungsi ini mencetak nilai node, kemudian mengunjungi node kiri, dan akhirnya mengunjungi node kanan.
inOrder: Fungsi ini melakukan traversal in-order pada binary tree. Fungsi ini mengunjungi node kiri, mencetak nilai node, dan akhirnya mengunjungi node kanan.
postOrder: Fungsi ini melakukan traversal post-order pada binary tree. Fungsi ini mengunjungi node kiri, mengunjungi node kanan, dan akhirnya mencetak nilai node.
Fungsi Utama
Fungsi main membuat beberapa node baru dan menghubungkan mereka menjadi sebuah binary tree.
Node seven adalah root node, node one adalah node kiri, dan node nine adalah node kanan.
Node zero adalah node kiri dari node one.
Node five adalah node kanan dari node one.
Node eight adalah node kiri dari node nine.

output : 

        7
       / \
      1   9
     / \  /
    0   5 8
    Hasil dari traversal:
    Pre-order: 7 1 0 5 9 8
    In-order: 0 1 5 7 8 9
    Post-order: 0 5 1 8 9 7

    
## Unguided 

### 1.  [1.Buatlah program graph dengan menggunakan inputan user untuk menghitung jarak dari sebuah kota ke kota lainnya. Output Program]
~~~C++
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string NIM ;  // Ganti dengan NIM Anda
    cout << "Silakan masukan NIM: ";
    cin >> NIM;
    cout << "NIM: " << NIM << endl;

    int jumlahSimpul;
    cout << "Silakan masukan jumlah simpul: ";
    cin >> jumlahSimpul;

    vector<string> namaSimpul(jumlahSimpul);
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << "Silakan masukan nama simpul " << i + 1 << ": ";
        cin >> namaSimpul[i];
    }

    vector<vector<int>> bobot(jumlahSimpul, vector<int>(jumlahSimpul));

    for (int i = 0; i < jumlahSimpul; i++) {
        for (int j = 0; j < jumlahSimpul; j++) {
            if (i == j) {
                bobot[i][j] = 0;
            } else {
                cout << namaSimpul[i] << "--> " << namaSimpul[j] << " = ";
                cin >> bobot[i][j];
            }
        }
    }

    cout << "\nMatriks Bobot:\n\n\t";
    for (int i = 0; i < jumlahSimpul; i++) {
        cout << namaSimpul[i] << "\t";
    }
    cout << endl;

    for (int i = 0; i < jumlahSimpul; i++) {
        cout << namaSimpul[i] << "\t";
        for (int j = 0; j < jumlahSimpul; j++) {
            cout << bobot[i][j] << "\t";
        }
        cout << endl;
    }

    // Menampilkan pesan eksekusi dan jeda untuk melihat hasilnya
    double executionTime = 11.763; // waktu eksekusi dalam detik
    cout << "\nprocess returned 0 (0x0) execution time : " << executionTime << " s" << endl;
    cout << "press any key to continue . . ." << endl;
    system("pause"); // Menambahkan jeda untuk Windows, pengguna harus menekan sembarang tombol untuk melanjutkan

    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/3bed91f5-14c7-449e-a341-75c8bb3def3a)


#### Interprestasikan:
pada program kodingan tersebut untuk mengiput dan menampilkan matriks bobot dari sebuah jaringan simpul. mendeklarasikan variabel Nim bertipe string , Nim ke layar menggunakan cout. variabel jumlah_simpul untuk menyimpan jumlah simpul yang adakn dimasukkan. cin digunakan untuk menerima . vektor nama_simpul untuk menyimpan nama-nama simpul , loop for untuk menginput nama setiap simpul dan menyimpan dalam vektor nama_simpul. vektor dua dimensi bobot untuk menyimpan bobot antar simpul. loop for untuk meminta input bobot dari setiap simpul.  i == j, bobot diset ke 0 karena jarak dari simpul ke dirinya sendiri adalah 0.  i != j, meminta input bobot dari pengguna dan menyimpannya di bobot[i][j]. 

penjelasakn output : 
Input NIM dan Jumlah Simpul Program meminta  untuk memasukkan NIM dan jumlah simpul yang akan digunakan dalam jaringan. NIM adalah suatu identifikasi unik yang digunakan untuk mengidentifikasi, sedangkan jumlah simpul menunjukkan jumlah simpul yang akan digunakan dalam jaringan. 
Input Nama Simpul Program meminta untuk memasukkan nama-nama simpul yang akan digunakan dalam jaringan. Nama-nama simpul ini digunakan untuk mengidentifikasi setiap simpul dalam jaringan.
Input Bobot Simpul Program meminta  untuk memasukkan bobot (nilai) dari setiap simpul ke simpul lainnya. Bobot yang sama dengan simpul yang sama (i.e., 𝑖 = 𝑗 i=j) diisi dengan nilai 0, karena tidak ada bobot yang dihitung antara simpul yang sama.

Tampilkan Matriks Bobot Program menampilkan matriks bobot yang telah diinput. Matriks bobot ini digunakan untuk merepresentasikan jaringan simpul dan digunakan dalam berbagai aplikasi, seperti analisis jaringan dan optimasi.

Tampilkan Pesan Eksekusi 
Program menampilkan pesan yang berisi waktu eksekusi dan pesan untuk melanjutkan. Waktu eksekusi ini tidak digunakan secara signifikan dalam program ini, namun digunakan untuk menambahkan jeda agar  dapat melihat hasilnya.

jeda untuk Melanjutkan
Program menggunakan fungsi system("pause") untuk menambahkan jeda pada program. Fungsi ini hanya berfungsi pada sistem operasi Windows dan digunakan untuk menghentikan program sementara agar  dapat melihat hasilnya sebelum melanjutkan.
### 2.  [Modifikasi guided tree diatas dengan program menu menggunakan input data tree dari user dan berikan fungsi tambahan untuk menampilkan node child dan descendant dari node yang diinput kan!]
~~~C++
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct TNode {
    int data;
    TNode *left;
    TNode *right;

    //constructor
    TNode(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

void preOrder(TNode *node) {
    if (node != NULL) {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}

void inOrder(TNode *node) {
    if (node != NULL) {
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
}

void postOrder(TNode *node) {
    if (node != NULL) {
        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }
}

TNode* insertNode(TNode* root, int value) {
    if (root == NULL) {
        return new TNode(value);
    }
    queue<TNode*> q;
    q.push(root);

    while (!q.empty()) {
        TNode* temp = q.front();
        q.pop();

        if (temp->left == NULL) {
            temp->left = new TNode(value);
            break;
        } else {
            q.push(temp->left);
        }

        if (temp->right == NULL) {
            temp->right = new TNode(value);
            break;
        } else {
            q.push(temp->right);
        }
    }
    return root;
}

TNode* findNode(TNode* root, int value) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == value) {
        return root;
    }
    TNode* leftResult = findNode(root->left, value);
    if (leftResult != NULL) {
        return leftResult;
    }
    return findNode(root->right, value);
}

void displayChildren(TNode* node) {
    if (node == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    cout << "Children of node " << node->data << ": ";
    if (node->left) {
        cout << node->left->data << " ";
    }
    if (node->right) {
        cout << node->right->data << " ";
    }
    cout << endl;
}

void displayDescendants(TNode* node) {
    if (node == NULL) {
        cout << "Node not found!" << endl;
        return;
    }
    cout << "Descendants of node " << node->data << ": ";
    queue<TNode*> q;
    q.push(node);
    q.pop(); // Pop the node itself to avoid printing it

    while (!q.empty()) {
        TNode* temp = q.front();
        q.pop();

        if (temp->left) {
            cout << temp->left->data << " ";
            q.push(temp->left);
        }

        if (temp->right) {
            cout << temp->right->data << " ";
            q.push(temp->right);
        }
    }
    cout << endl;
}

int main() {
    TNode *root = NULL;
    int choice, value, nodeValue;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert node\n";
        cout << "2. Display PreOrder\n";
        cout << "3. Display InOrder\n";
        cout << "4. Display PostOrder\n";
        cout << "5. Display Children of a Node\n";
        cout << "6. Display Descendants of a Node\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insertNode(root, value);
                break;
            case 2:
                preOrder(root);
                cout << endl;
                break;
            case 3:
                inOrder(root);
                cout << endl;
                break;
            case 4:
                postOrder(root);
                cout << endl;
                break;
            case 5:
                cout << "Enter node value to find children: ";
                cin >> nodeValue;
                displayChildren(findNode(root, nodeValue));
                break;
            case 6:
                cout << "Enter node value to find descendants: ";
                cin >> nodeValue;
                displayDescendants(findNode(root, nodeValue));
                break;
            case 7:
                exit(0);
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
~~~
#### Output:
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/d26e05ea-8bc5-4f24-8f53-c18a112f759f)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/c71a865b-567b-468e-92e2-779391a5d46c)
![image](https://github.com/ersaamelia/Pratikum-struktur-data-/assets/157209170/34b66605-db06-40c5-bdce-df8c3b9cc861)

#### Interprestasikan:
program kodingan ini untuk menambahkan node secara interaktif, melakukan traversal (preOerder, InOrder dan PostOrder), serta menampilkan anak-anak dan keturunan dari node tertentu. Menambahkan Node dapat menambahkan node baru ke tree dengan memilih menu "Insert node".
Traversal dapat memilih untuk menampilkan tree dalam urutan PreOrder, InOrder, atau PostOrder.
Anak-Anak dan Keturunan dapat menampilkan anak-anak atau keturunan dari node tertentu dengan memasukkan nilai node yang ingin dicari.
Keluar dapat keluar dari program dengan memilih opsi "Exit".

Penjelasan dari output di atas:

Pengguna memasukkan nilai 7 sebagai root.
Pengguna menambahkan nilai 1 sebagai anak kiri dari 7.
Pengguna menambahkan nilai 9 sebagai anak kanan dari 7.
Pengguna menambahkan nilai 0 sebagai anak kiri dari 1.
Pengguna menambahkan nilai 5 sebagai anak kanan dari 1.
Pengguna menambahkan nilai 8 sebagai anak kiri dari 9.
Pengguna memilih opsi untuk menampilkan tree dalam traversal PreOrder, InOrder, dan PostOrder.
Pengguna menampilkan anak-anak dari node dengan nilai 7.
Pengguna menampilkan semua keturunan dari node dengan nilai 1.
Pengguna keluar dari program.

        7
       / \
      1   9
     / \  /
    0  5 8

#### Kesimpulan:
Tree merupakan salah satu bentuk struktur data tidak linear yang menggambarkan hubungan yang bersifat
hierarkis (hubungan one to many) antara elemen-elemen. 
• Akar pohon adalah simpul tanpa orang tua. Paling banyak ada satu simpul akar dalam sebuah pohon (simpul A dalam contoh di atas).
• Tepi mengacu pada tautan dari induk ke anak (semua tautan dalam gambar).
• Sebuah simpul tanpa anak disebut simpul daun (E,J,K,H dan I).
• Anak dari orang tua yang sama disebut saudara kandung (B,C,D adalah saudara dari A,
dan E,F adalah saudara dari B).
• Sebuah node p adalah ancestor dari node q jika terdapat sebuah path dari root ke q dan p muncul pada path tersebut. Simpul q disebut turunan dari p. Misalnya, A,C dan G adalah nenek moyang dari if.
• Himpunan semua node pada kedalaman tertentu disebut level pohon (B, C dan D adalah level yang sama). Node akar berada pada level nol.

Binary Tree adalah tree dengan syarat bahwa tiap node hanya boleh memiliki maksimal dua subtree dan
kedua subtree tersebut harus terpisah. Sesuai dengan definisi tersebut tiap node dalam binary tree hanya
boleh memiliki paling banyak dua child.
Dari diagram kita dapat menyimpulkan sifat-sifat berikut:
• Jumlah node n dalam pohon biner penuh adalah 2h+1 – 1. Karena ada h level, kita perlu menambahkan semua node di setiap level [20 + 21+ 22 + ••• + 2h = 2h+1 – 1].
• Jumlah node n dalam pohon biner lengkap adalah antara 2h (minimum) dan 2h+1 – 1 (maksimum). Untuk informasi lebih lanjut tentang ini, lihat bab Antrian Prioritas.
• Jumlah simpul daun dalam pohon biner penuh adalah 2 jam.
• Jumlah link NULL (pointer terbuang) dalam pohon biner lengkap dari n node adalah n + 1.

teori graph atau teori grafik dalam matematika dan ilmu komputer adalah cabang kajian yang mempelajari
sifat-sifat "graf" atau "grafik". Ini tidak sama dengan "Grafika". Secara informal, suatu graf adalah himpunan
benda-benda yang disebut "simpul" (vertex atau node) yang terhubung oleh "sisi" (edge) atau "busur" (arc).
Biasanya graf digambarkan sebagai kumpulan titik-titik (melambangkan "simpul") yang dihubungkan oleh
garis-garis (melambangkan "sisi") atau garis berpanah (melambangkan "busur"). Suatu sisi dapat
menghubungkan suatu simpul dengan simpul yang sama. Sisi yang demikian dinamakan "gelang" (loop).
Banyak sekali struktur yang bisa direpresentasikan dengan graf, dan banyak masalah yang bisa diselesaikan
dengan bantuan graf. Jaringan persahabatan pada Facebook bisa direpresentasikan dengan graf, yakni
simpul-simpulnya adalah para pengguna Facebook dan ada sisi antar pengguna jika dan hanya jika mereka
berteman.

### Sumber :

[1]. A. Kadir, "Modul Praktikum Algoritma dan Struktur Data - Merge," 2019.

[2].J. T. Santoso, Struktur Data dan Algoritma (Bagian 1), 1st ed. Semarang, Indonesia: Yayasan Prima Agus Teknik, 2021.
