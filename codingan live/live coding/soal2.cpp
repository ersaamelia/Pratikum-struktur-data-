#include <iostream>

int faktorial(int n) {
    if (n <= 1) return 1;
    return n * faktorial( n - 1);
    return 1;
}

int main() {
    int angka = 6;
    std::cout << "faktorial" << angka << "adalah " << faktorial(angka) << std::endl;
    return 0;
}