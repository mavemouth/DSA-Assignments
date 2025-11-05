#include <iostream>
using namespace std;

void transpose(int B[][3], int BT[][3]) {
    int nz = B[0][2];
    BT[0][0] = B[0][1];
    BT[0][1] = B[0][0];
    BT[0][2] = nz;

    int k2 = 1;
    for(int col = 0; col < B[0][1]; col++){
        for(int i = 1; i <= nz; i++){
            if(B[i][1] == col){
                BT[k2][0] = B[i][1];
                BT[k2][1] = B[i][0];
                BT[k2][2] = B[i][2];
                k2++;
            }
        }
    }
}

void multiply(int A[][3], int B[][3], int C[][3]) {
    if(A[0][1] != B[0][0]){
        cout<<"Multiplication not possible!"; return;
    }

    int BT[20][3];
    transpose(B, BT);

    int k = 1;
    C[0][0] = A[0][0];
    C[0][1] = B[0][1];

    for(int i=1;i<=A[0][2];){
        int row = A[i][0];
        for(int j=1;j<=BT[0][2];){
            int col = BT[j][0];
            int x = i, y = j;
            int sum = 0;

            while(x<=A[0][2] && A[x][0]==row &&
                  y<=BT[0][2] && BT[y][0]==col){
                if(A[x][1] == BT[y][1]){
                    sum += A[x][2] * BT[y][2];
                    x++; y++;
                }
                else if(A[x][1] < BT[y][1]) x++;
                else y++;
            }

            if(sum != 0){
                C[k][0] = row;
                C[k][1] = col;
                C[k][2] = sum;
                k++;
            }

            while(j<=BT[0][2] && BT[j][0]==col) j++;
        }

        while(i<=A[0][2] && A[i][0]==row) i++;
    }

    C[0][2] = k-1;
}

void display(int M[][3]) {
    for(int i=0;i<=M[0][2];i++)
        cout<<M[i][0]<<" "<<M[i][1]<<" "<<M[i][2]<<endl;
}

int main(){
    int A[5][3] = {{3,3,3},{0,0,1},{1,1,2},{2,2,3}};
    int B[5][3] = {{3,3,3},{0,0,4},{1,1,5},{2,2,6}};
    int C[10][3];

    multiply(A, B, C);

    cout<<"Matrix A:\n"; display(A);
    cout<<"\nMatrix B:\n"; display(B);
    cout<<"\nResult (A×B):\n"; display(C);
}
