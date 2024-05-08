#include <iostream>

using namespace std;

struct Node {
    string data;
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

    void enqueue(string data) {
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
        cout << "Data antrian teller:" << endl;
        int i = 1;
        while (current != nullptr) {
            cout << i << ". " << current->data << endl;
            current = current->next;
            i++;
        }
    }
};

int main() {
    Queue myQueue(5);
    myQueue.enqueue("Andi");
    myQueue.enqueue("Maya");
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl;
    myQueue.dequeue();
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl;
    myQueue.clear();
    myQueue.display();
    cout << "Jumlah antrian = " << myQueue.count() << endl;
    return 0;
}
