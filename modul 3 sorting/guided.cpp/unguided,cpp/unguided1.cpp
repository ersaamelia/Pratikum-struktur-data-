#include <iostream>
using namespace std;

void selectSort(float arr[], int n) {
    int pos_min;
    float temp;
    for (int i = 0; i < n - 1; i++) {
        pos_min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[pos_min])
                pos_min = j;
        }
        if (pos_min != i) {
            temp = arr[i];
            arr[i] = arr[pos_min];
            arr[pos_min] = temp;
        }
    }
}

int main() {
    int Mahasiswa= 5;
    float IPS[] = {3.8, 2.9, 3.3, 4.0, 2.4};
    

    cout << "IPS sebelum diurutkan: ";
    for (int i = 0; i < Mahasiswa; i++) {
        cout << IPS[i] << " ";
    }

    selectSort(IPS, Mahasiswa);

    cout << "\nIPS setelah diurutkan dari terbesar ke terkecil: ";
    for (int i = 0; i < Mahasiswa; i++) {
        cout << IPS[i] << " ";
    }
}
