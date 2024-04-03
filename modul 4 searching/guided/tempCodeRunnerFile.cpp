#include <iostream>
#include <conio.h>
#include <iomanip>

using namespace std;

int cari;

void selection_sort(int data[], int length) {
    int temp, min, i, j;
    for(i =0; i < length; i++) {
        for(j = i; j < length; j++) {
            if(data[j] < data[min]) { 
                min = j;
            }
        }
        temp = data[i];
        data[i] = data[min];
        data[min] = temp;
    }
}

void binaryseacrh(int data[], int length) {
    int awal , akhir, tengah, b_flag = 0;
    awal = 0;
    akhir = length - 1;
    while (b_flag == 0 && awal <= akhir) {
        tengah = (awal + akhir ) / 2;
        if (data[tengah] == cari) {
            b_flag - 1;
            break;
        } else if(data[tengah] < cari)
            awal = tengah +1;
        else 
            akhir  = tengah -1;
    }
    if(b_flag == 1)
       cout << "\n data ditemukan pada index ke-" << tengah << endl;
    else 
       cout << "\n data tidak ditambahkan";
}

int main() {
    int data[7] = {1, 8, 2, 5, 4, 9, 7};
    int length = sizeof(data) / sizeof(data[0]);

    cout<<"\t BINARY SEARCH "<<endl;
    cout<<"\n Data : ";
    //tampilkan data awal
    for(int x = 0; x<7; x++)
       cout<<setw(3)<<data[x];
    cout<<endl;

    cout<<"\n Masukkan data yang ingin Anda cari : ";
    cin>>cari;
    cout<<"\n Data diurutkan : ";
     //urutkan data dengan selection sort
     selection_sort;

    //tampilkan data setelah diurutkan
    for(int x = 0; x<7;x++)
          cout<<setw(3)<<data[x];

 cout<<endl;
   
    binaryseacrh;

 _getche();
 return EXIT_SUCCESS;
}
