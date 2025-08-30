#include <iostream>
#include <stack>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    stack<char> st;
    for (char c : str) st.push(c);

    string rev = "";
    while (!st.empty()) {
        rev += st.top();
        st.pop();
    }
    cout << "Reversed: " << rev << endl;
}
