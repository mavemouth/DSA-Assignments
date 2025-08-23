#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char c;
    cout << "Enter a character: ";
    cin >> c;

    cout << "Lowercase: " << (char)tolower(c) << endl;
    return 0;
}
