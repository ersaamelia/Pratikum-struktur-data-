#include <iostream>
using namespace std;
void bubble_sort(double arr[], int length){
    bool not_sorted = true;
    int j=0;
    doubel tmp;
    while (not_sorted){
        not_sorted = false;
        j++;
        for (int i =0; i < length - j; i++){
            if (arr[i] > arr [i + 1]) {
                tmp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = tmp;
                not_sorted = true;
            }//end of if
        }//end of for loop
    }//end of while loop
}//end of bubbel_sort
void print_array(double a[], int length) {
    for (int i=0; i<length; i++) {
        cout << a[i] << "\t";
    } 
    cout << endl;
}
int main() {
    int length = 5;
    doubel a[] = {22.1, 15.3, 8.2, 33.21, 99.99};
    cout << "urutan bilangan sebelum sorting: " << endl;
    print_array(a, length);
    bubble_sort(a, length);
    cout << "\nurutan bilangan setelh sorting: " ,< endl;
    print_array(a, length);
}
