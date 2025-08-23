#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int arr[] = {1, 5, 3, 4, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;

    sort(arr, arr+n);
    int i=0, j=1, count=0;

    while (i<n && j<n) {
        if (arr[j]-arr[i]==k) { count++; i++; j++; }
        else if (arr[j]-arr[i] < k) j++;
        else i++;
    }
    cout << "Pairs with difference " << k << " = " << count << endl;
    return 0;
}
