#include <iostream>
#include <queue>
using namespace std;

class Stack2Q {
    queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) { q2.push(q1.front()); q1.pop(); }
        swap(q1, q2);
    }
    void pop() { if (!q1.empty()) q1.pop(); }
    int top() { return q1.empty()? -1 : q1.front(); }
};

int main() {
    Stack2Q s;
    s.push(10); s.push(20); s.push(30);
    cout << "Top: " << s.top() << endl;
    s.pop();
    cout << "Top after pop: " << s.top() << endl;
}
