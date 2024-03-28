#include <iostream>
#include <string>

using namespace std;

void bubbleSort(string nama[], int n) {
  bool swapped;
  int i, j;

  for (i = 0; i < n - 1; i++) {
    swapped = false;
    for (j = 0; j < n - i - 1; j++) {
      if (nama[j] > nama[j + 1]) {
        swap(nama[j], nama[j + 1]);
        swapped = true;
      }
    }

    // Jika tidak ada pertukaran pada iterasi ini, maka array sudah terurut
    if (!swapped) {
      break;
    }
  }
}

int main() {
  // Array untuk menyimpan nama-nama warga
  string nama[] = {"siti", "situ", "sana", "ana", "ani", "caca", "cici", "dida", "dodo", "dadi"};

  // Jumlah warga
  int Warga = 10;

  // Mengurutkan nama-nama warga
  bubbleSort(nama, Warga);

  // Menampilkan nama-nama warga yang telah diurutkan
  for (int i = 0; i < Warga; i++) {
    cout << nama[i] << " ";
  }
}
