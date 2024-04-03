 #include <iostream>
#include <algorithm>

using namespace std;

int main() {
  string kalimat;
  int jumlah_vokal = 0;

  // Input kalimat
  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  // Konversi semua huruf menjadi huruf kecil
  transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);

  // Hitung jumlah huruf vokal
  for (int i = 0; i < kalimat.length(); i++) {
    if (kalimat[i] == 'a' || kalimat[i] == 'i' || kalimat[i] == 'u' || kalimat[i] == 'e' || kalimat[i] == 'o') {
      jumlah_vokal++;
    }
  }

  // Tampilkan hasil
  cout << "Jumlah huruf vokal dalam kalimat: " << jumlah_vokal << endl;

  return 0;
}
