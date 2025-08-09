#include <iostream>
using namespace std;

int main() {
    int mat[10][10], r, c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];

    for (int i = 0; i < r; i++) {
        int rowSum = 0;
        for (int j = 0; j < c; j++)
            rowSum += mat[i][j];
        cout << "Sum of row " << i << " = " << rowSum << "\n";
    }

    for (int j = 0; j < c; j++) {
        int colSum = 0;
        for (int i = 0; i < r; i++)
            colSum += mat[i][j];
        cout << "Sum of column " << j << " = " << colSum << "\n";
    }
}
