#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int arr[SIZE];
    int front, rear;
public:
    CircularQueue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return (front == 0 && rear == SIZE-1) || (rear+1)%SIZE == front; }

    void enqueue(int x) {
        if (isFull()) { cout << "Queue Full\n"; return; }
        if (front == -1) front = 0;
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
    }

    void dequeue() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front = (front + 1) % SIZE;
    }

    void display() {
        if (isEmpty()) { cout << "Queue Empty\n"; return; }
        cout << "Queue: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int ch, val;
    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.Display 4.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.display(); break;
            case 4: return 0;
        }
    }
}
