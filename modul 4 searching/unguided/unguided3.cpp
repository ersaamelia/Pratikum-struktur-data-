~~~C++
#include <iostream>

using namespace std;

int hitungAngkaEmpat(int data[], int panjang) {
    int jumlahEmpat = 0;
    for (int i = 0; i < panjang; ++i) {
        if (data[i] == 4) {
            jumlahEmpat++;
        }
    }
    return jumlahEmpat;
}  

int main() {
  int data[] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int n = sizeof(data) / sizeof(data[0]);
  int jumlah_angka_4 = 0;

  // Algoritma Sequential Search
  for (int i = 0; i < n; i++) {
    if (data[i] == 4) {
      jumlah_angka_4++;
    }
  }

  // Tampilkan hasil
  cout << "Jumlah angka 4 dalam data: " << jumlah_angka_4 << endl;

  return 0;
}
~~~
