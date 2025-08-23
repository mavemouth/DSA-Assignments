#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

int main() {
    int rows, cols, nonZero;
    cout << "Enter rows, cols and non-zero elements: ";
    cin >> rows >> cols >> nonZero;

    Element triplet[100];
    cout << "Enter row col value:\n";
    for (int i=0; i<nonZero; i++) {
        cin >> triplet[i].row >> triplet[i].col >> triplet[i].val;
    }

    cout << "Transpose (col, row, val):\n";
    for (int i=0; i<nonZero; i++) {
        cout << triplet[i].col << " " << triplet[i].row << " " << triplet[i].val << endl;
    }
    return 0;
}
