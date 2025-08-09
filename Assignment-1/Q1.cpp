#include <iostream>
using namespace std;

#define SIZE 100

class ArrayOps {
    int arr[SIZE];
    int n;

public:
    ArrayOps() { n = 0; }

    void create() {
        cout << "Enter number of elements: ";
        cin >> n;
        cout << "Enter " << n << " elements:\n";
        for (int i = 0; i < n; i++)
            cin >> arr[i];
    }

    void display() {
        if (n == 0) {
            cout << "Array is empty.\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "\n";
    }

    void insert() {
        if (n == SIZE) {
            cout << "Array is full.\n";
            return;
        }
        int pos, value;
        cout << "Enter position (0 to " << n << "): ";
        cin >> pos;
        cout << "Enter value: ";
        cin >> value;
        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = value;
        n++;
    }

    void remove() {
        if (n == 0) {
            cout << "Array is empty.\n";
            return;
        }
        int pos;
        cout << "Enter position (0 to " << n - 1 << "): ";
        cin >> pos;
        for (int i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;
    }

    void linearSearch() {
        int key;
        bool found = false;
        cout << "Enter element to search: ";
        cin >> key;
        for (int i = 0; i < n; i++) {
            if (arr[i] == key) {
                cout << "Element found at position " << i << "\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Element not found.\n";
    }
};

int main() {
    ArrayOps obj;
    int choice;
    while (true) {
        cout << "\n---- MENU ----\n";
        cout << "1.CREATE\n2.DISPLAY\n3.INSERT\n4.DELETE\n5.LINEAR SEARCH\n6.EXIT\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: obj.create(); break;
            case 2: obj.display(); break;
            case 3: obj.insert(); break;
            case 4: obj.remove(); break;
            case 5: obj.linearSearch(); break;
            case 6: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}
