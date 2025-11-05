#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int minIndex(queue<int> q, int sortedIndex) {
    int min_val = INT_MAX, min_idx = -1;
    int n = q.size();

    for(int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if(curr <= min_val && i <= sortedIndex) {
            min_val = curr;
            min_idx = i;
        }
        q.push(curr);
    }
    return min_idx;
}

void insertAtRear(queue<int> &q, int min_idx) {
    int n = q.size();
    int min_val;
    for(int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if(i != min_idx)
            q.push(curr);
        else
            min_val = curr;
    }
    q.push(min_val);
}

void sortQueue(queue<int> &q) {
    for(int i = 1; i <= q.size(); i++) {
        int min_idx = minIndex(q, q.size() - i);
        insertAtRear(q, min_idx);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    cout << "Sorted Queue:\n";
    while(!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
