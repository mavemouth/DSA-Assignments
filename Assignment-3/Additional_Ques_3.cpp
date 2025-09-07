#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int arr[] = {4, 5, 2, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> nge(n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) st.pop();
        if (st.empty()) nge[i] = -1;
        else nge[i] = st.top();
        st.push(arr[i]);
    }

    cout << "Next Greater Elements:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " -> " << nge[i] << endl;
}
