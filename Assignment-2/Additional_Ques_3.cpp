#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s1, s2;
    cout << "Enter two strings: ";
    cin >> s1 >> s2;

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    if (s1 == s2) cout << "Anagram" << endl;
    else cout << "Not Anagram" << endl;
    return 0;
}
