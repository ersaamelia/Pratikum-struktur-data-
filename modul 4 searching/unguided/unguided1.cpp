#include <iostream>
#include <algorithm>

using namespace std;

// Fungsi untuk mencari sebuah huruf pada sebuah string menggunakan Binary Search
bool binarySearch(string str, char target) {
    int left = 0;
    int right = str.length() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Jika karakter pada posisi mid adalah target, kembalikan true
        if (str[mid] == target)
            return true;

        // Jika karakter pada posisi mid lebih kecil dari target, geser ke kanan
        if (str[mid] < target)
            left = mid + 1;
        // Jika karakter pada posisi mid lebih besar dari target, geser ke kiri
        else
            right = mid - 1;
    }

    // Jika tidak ditemukan, kembalikan false
    return false;
}

int main() {
    string sentence;
    char target;

    // Input kalimat dan huruf yang akan dicari
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, sentence);
    cout << "Masukkan huruf yang ingin dicari: ";
    cin >> target;

    // Konversi semua huruf dalam kalimat menjadi huruf kecil untuk mempermudah pencarian
    transform(sentence.begin(), sentence.end(), sentence.begin(), ::tolower);

    // Lakukan binary search pada kalimat
    bool found = binarySearch(sentence, tolower(target));

    // Tampilkan hasil
    if (found)
        cout << "Huruf '" << target << "' ditemukan dalam kalimat.\n";
    else
        cout << "Huruf '" << target << "' tidak ditemukan dalam kalimat.\n";

    return 0;
}
