#include <iostream>
#include <stack>
using namespace std;

int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}

int evalPostfix(string exp) {
    stack<int> st;
    for (char c : exp) {
        if (isdigit(c)) st.push(c-'0');  // convert char to int
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            st.push(applyOp(val1, val2, c));
        }
    }
    return st.top();
}

int main() {
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;
    cout << "Result = " << evalPostfix(exp) << endl;
}
