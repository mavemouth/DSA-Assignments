#include <iostream>
using namespace std;

int main() {
    int arr[100], n;
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Reversed Array:\n";
    for (int i = n - 1; i >= 0; i--)
        cout << arr[i] << " ";
}
