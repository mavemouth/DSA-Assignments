#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    int n = temp.size();
    vector<int> ans(n, 0);
    stack<int> st; // store indices

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && temp[st.top()] <= temp[i])
            st.pop();
        if (!st.empty()) ans[i] = st.top() - i;
        st.push(i);
    }

    cout << "Days until warmer temperature: ";
    for (int x : ans) cout << x << " ";
    cout << endl;
}
