#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
  int n;

  // Meminta user untuk memasukkan jumlah karakter
  cout << "Masukkan jumlah karakter: ";
  cin >> n;

  // Deklarasi array untuk menyimpan karakter
  char karakter[n];

  // Meminta user untuk memasukkan karakter
  cout << "Masukkan " << n << " karakter: ";
  for (int i = 0; i < n; i++) {
    cin >> karakter[i];
  }

  // Menampilkan karakter sebelum sorting
  cout << "\nKarakter sebelum sorting: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }

  // Sorting karakter secara ascending
  sort(karakter, karakter + n);

  // Menampilkan karakter setelah sorting ascending
  cout << "\n\nKarakter setelah sorting ascending: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }

  // Sorting karakter secara descending
  reverse(karakter, karakter + n);

  // Menampilkan karakter setelah sorting descending
  cout << "\n\nKarakter setelah sorting descending: ";
  for (int i = 0; i < n; i++) {
    cout << karakter[i];
  }

  cout << endl;

  return 0;
}