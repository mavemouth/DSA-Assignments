#include <iostream>
#include <queue>
using namespace std;

class Stack1Q {
    queue<int> q;
public:
    void push(int x) {
        int n = q.size();
        q.push(x);
        for (int i = 0; i < n; i++) { q.push(q.front()); q.pop(); }
    }
    void pop() { if (!q.empty()) q.pop(); }
    int top() { return q.empty()? -1 : q.front(); }
};
