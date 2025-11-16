#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    insertionSort(arr, n);

    cout << "Sorted: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
