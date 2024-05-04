#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Menghapus karakter non-alphanumeric dari string
string removeNonAlphaNumeric(string str) {
    string result = "";
    for (char c : str) {
        if (isalnum(c)) {
            result += tolower(c);
        }
    }
    return result;
}

// Mengecek apakah sebuah string adalah palindrom
bool isPalindrome(string str) {
    stack<char> s;
    int n = str.size();
    
    // Menyimpan setengah karakter pertama ke dalam stack
    for (int i = 0; i < n/2; i++) {
        s.push(str[i]);
    }

    // Membandingkan setengah karakter kedua dengan karakter yang disimpan di stack
    for (int i = (n+1)/2; i < n; i++) {
        if (s.top() != str[i]) {
            return false;
        }
        s.pop();
    }
    return true;
}

int main() {
    string kalimat;
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    // Menghapus karakter non-alphanumeric dan membuat string menjadi lowercase
    string kalimatBersih = removeNonAlphaNumeric(kalimat);
    
    // Menentukan apakah kalimat adalah palindrom atau tidak
    if (isPalindrome(kalimatBersih)) {
        cout << "Kalimat merupakan palindrom." << endl;
    } else {
        cout << "Kalimat bukan palindrom." << endl;
    }

    return 0;
}
