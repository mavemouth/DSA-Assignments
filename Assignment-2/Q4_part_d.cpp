#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    string arr[100];

    cout << "Enter strings:\n";
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n);

    cout << "Sorted strings: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
