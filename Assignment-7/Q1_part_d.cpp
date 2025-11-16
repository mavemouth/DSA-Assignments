#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int a[100], b[100];  
    for(int i = 0; i < n1; i++) a[i] = arr[l+i];
    for(int i = 0; i < n2; i++) b[i] = arr[m+1+i];

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }

    while(i < n1) arr[k++] = a[i++];
    while(j < n2) arr[k++] = b[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l >= r) return;

    int m = (l + r) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m+1, r);
    merge(arr, l, m, r);
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[100];
    cout << "Enter elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];

    mergeSort(arr, 0, n-1);

    cout << "Sorted: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}
