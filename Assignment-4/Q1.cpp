#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    int arr[SIZE];
    int front, rear;
public:
    Queue() { front = rear = -1; }

    bool isEmpty() { return front == -1; }
    bool isFull() { return rear == SIZE - 1; }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue Overflow\n"; return;
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow\n"; return;
        }
        cout << "Dequeued: " << arr[front] << endl;
        if (front == rear) front = rear = -1;
        else front++;
    }

    void peek() {
        if (isEmpty()) cout << "Queue Empty\n";
        else cout << "Front element: " << arr[front] << endl;
    }

    void display() {
        if (isEmpty()) cout << "Queue Empty\n";
        else {
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) cout << arr[i] << " ";
            cout << endl;
        }
    }
};

int main() {
    Queue q;
    int ch, val;
    while (true) {
        cout << "\n1.Enqueue 2.Dequeue 3.Peek 4.Display 5.Exit\n";
        cin >> ch;
        switch (ch) {
            case 1: cout << "Enter value: "; cin >> val; q.enqueue(val); break;
            case 2: q.dequeue(); break;
            case 3: q.peek(); break;
            case 4: q.display(); break;
            case 5: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
