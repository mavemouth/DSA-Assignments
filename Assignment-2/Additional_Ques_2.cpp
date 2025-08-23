#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    int n = s.length();

    bool possible = false;

    // Try every split into 3 parts
    for (int i = 1; i < n; i++) {        // first cut
        for (int j = i + 1; j < n; j++) { // second cut
            string A = s.substr(0, i);
            string B = s.substr(i, j - i);
            string C = s.substr(j);

            if (A.find(B + C) != string::npos ||
                (B + C).find(A) != string::npos ||
                (A + C).find(B) != string::npos ||
                (A + B).find(C) != string::npos) {
                possible = true;
                cout << "Yes, possible with split: "
                     << "A=" << A << ", B=" << B << ", C=" << C << endl;
                goto end; // break out of both loops
            }
        }
    }

end:
    if (!possible) cout << "No, not possible." << endl;
    return 0;
}
