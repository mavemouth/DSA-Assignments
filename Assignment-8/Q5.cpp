#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i, bool increasing) {
    int extreme = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (increasing) {
        // For max heap (increasing order)
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } else {
        // For min heap (decreasing order)
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }
    
    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, increasing);
    }
}

void heapSort(vector<int>& arr, bool increasing = true) {
    int n = arr.size();
    
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, increasing);
    
    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, increasing);
    }
}

int main() {
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    
    cout << "Original array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    // Increasing order
    heapSort(arr, true);
    cout << "Sorted in increasing order: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    // Reset array
    arr = {12, 11, 13, 5, 6, 7};
    
    // Decreasing order
    heapSort(arr, false);
    cout << "Sorted in decreasing order: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}