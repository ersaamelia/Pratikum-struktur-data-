#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Fungsi untuk menghitung jumlah huruf vokal dalam sebuah kalimat
int hitungVokal(string kalimat) {
    int jumlahVokal = 0;
    // Konversi kalimat menjadi huruf kecil untuk mempermudah penghitungan
    transform(kalimat.begin(), kalimat.end(), kalimat.begin(), ::tolower);
    
    // Loop untuk mengiterasi setiap karakter dalam kalimat
    for (char karakter : kalimat) {
        // Periksa apakah karakter merupakan huruf vokal
        if (karakter == 'a' || karakter == 'e' || karakter == 'i' || karakter == 'o' || karakter == 'u') {
            jumlahVokal++;
        }
    }
    
    return jumlahVokal;
}

int main() {
    string kalimat;
    cout << "Masukkan sebuah kalimat: ";
    getline(cin, kalimat);
    
    int jumlahVokal = hitungVokal(kalimat);
    cout << "Jumlah huruf vokal dalam kalimat tersebut adalah: " << jumlahVokal << endl;
    
    return 0;
}
