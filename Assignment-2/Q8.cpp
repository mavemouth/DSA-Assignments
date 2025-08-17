#include <iostream>
#include <set>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    set<int> distinct;
    for (int i = 0; i < n; i++)
        distinct.insert(arr[i]);

    cout << "Total distinct elements = " << distinct.size() << endl;
    return 0;
}
