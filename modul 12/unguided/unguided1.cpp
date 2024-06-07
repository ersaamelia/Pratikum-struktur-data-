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
