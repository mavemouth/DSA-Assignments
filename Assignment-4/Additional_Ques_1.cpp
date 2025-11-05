#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;

    q.push("1"); // First binary number

    while(n--) {
        string s1 = q.front();
        q.pop();

        cout << s1 << " ";

        q.push(s1 + "0");
        q.push(s1 + "1");
    }
}

int main() {
    int n = 5;
    cout << "Binary numbers from 1 to " << n << ":\n";
    generateBinary(n);
}
