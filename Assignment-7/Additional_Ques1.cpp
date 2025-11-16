#include <iostream>
using namespace std;

void countingSort(int arr[], int n) {
    int maxVal = arr[0];
    for(int i = 1; i < n; i++)
        maxVal = max(maxVal, arr[i]);

    int count[1000] = {0};

    for(int i = 0; i < n; i++)
        count[arr[i]]++;

    int k = 0;
    for(int i = 0; i <= maxVal; i++)
        while(count[i]--) arr[k++] = i;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    countingSort(arr, n);

    cout << "Sorted: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
