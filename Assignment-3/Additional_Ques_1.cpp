#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= arr[i])
            st.pop();
        if (st.empty()) ans.push_back(-1);
        else ans.push_back(st.top());
        st.push(arr[i]);
    }

    cout << "Nearest Smaller to Left: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}
