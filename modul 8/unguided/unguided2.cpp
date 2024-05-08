#include <iostream>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
};

struct Node {
    Mahasiswa data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
    int size;
    const int maksimalQueue;

public:
    Queue(int maksimal) : maksimalQueue(maksimal) {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }

    bool isFull() {
        return size == maksimalQueue;
    }

    bool isEmpty() {
        return size == 0;
    }

    void enqueue(Mahasiswa data) {
        if (isFull()) {
            cout << "Antrian Penuh" << endl;
            return;
        }
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
        size--;
    }

    int count() {
        return size;
    }

    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
            return;
        }
        Node* current = front;
        cout << "Data antrian mahasiswa:" << endl;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". Nama: " << current->data.nama << endl;
            cout << "   NIM: " << current->data.nim << endl;
            current = current->next;
            i++;
        }
    }
};

int main() {
    Queue myQueue(5);

    Mahasiswa m1 = {"Andi", "12345"};
    Mahasiswa m2 = {"Maya", "67890"};
    Mahasiswa m3 = {"Ersa", "2311110009"};

    myQueue.enqueue(m1);
    myQueue.enqueue(m2);
    myQueue.enqueue(m3);

    cout << "Data awal:" << endl;
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl << endl;

    myQueue.dequeue();

    cout << "Setelah dequeue:" << endl;
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl << endl;

    myQueue.clear();

    cout << "Setelah clear:" << endl;
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl << endl;

    return 0;
}
