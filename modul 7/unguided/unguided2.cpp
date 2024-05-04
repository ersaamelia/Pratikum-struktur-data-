#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Fungsi untuk membalikkan kalimat menggunakan stack
string reverseString(string kalimat) {
    stack<char> s;
    string reversedKalimat = "";

    // Memasukkan setiap karakter dari kalimat ke dalam stack
    for (char c : kalimat) {
        s.push(c);
    }

    // Mengambil setiap karakter dari stack untuk membentuk kalimat terbalik
    while (!s.empty()) {
        reversedKalimat += s.top();
        s.pop();
    }

    return reversedKalimat;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat (minimal 3 kata): ";
    getline(cin, kalimat);

    // Memanggil fungsi untuk membalikkan kalimat
    string kalimatTerbalik = reverseString(kalimat);

    // Menampilkan kalimat asli dan kalimat terbalik
    cout << "Kalimat asli: " << kalimat << endl;
    cout << "Kalimat terbalik: " << kalimatTerbalik << endl;

    return 0;
}
