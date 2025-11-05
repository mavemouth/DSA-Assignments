#include <iostream>
using namespace std;

void add(int A[][3], int B[][3], int C[][3]) {
    if(A[0][0] != B[0][0] || A[0][1] != B[0][1]){
        cout<<"Addition not possible!"; return;
    }

    int nzA = A[0][2], nzB = B[0][2];
    int i=1, j=1, k=1;

    C[0][0] = A[0][0];
    C[0][1] = A[0][1];

    while(i<=nzA && j<=nzB){
        if(A[i][0] == B[j][0] && A[i][1] == B[j][1]){
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
        else if(A[i][0] < B[j][0] || 
               (A[i][0] == B[j][0] && A[i][1] < B[j][1])){
            C[k][0] = A[i][0];
            C[k][1] = A[i][1];
            C[k][2] = A[i][2];
            i++; k++;
        }
        else{
            C[k][0] = B[j][0];
            C[k][1] = B[j][1];
            C[k][2] = B[j][2];
            j++; k++;
        }
    }

    while(i<=nzA) C[k][0]=A[i][0], C[k][1]=A[i][1], C[k][2]=A[i][2], i++, k++;
    while(j<=nzB) C[k][0]=B[j][0], C[k][1]=B[j][1], C[k][2]=B[j][2], j++, k++;

    C[0][2] = k-1;
}

void display(int M[][3]) {
    for(int i=0;i<=M[0][2];i++)
        cout<<M[i][0]<<" "<<M[i][1]<<" "<<M[i][2]<<endl;
}

int main(){
    int A[5][3] = {{3,3,3},{0,0,5},{1,1,4},{2,2,7}};
    int B[5][3] = {{3,3,3},{0,0,2},{1,2,3},{2,2,6}};
    int C[10][3];

    add(A, B, C);

    cout<<"Matrix A:\n"; display(A);
    cout<<"\nMatrix B:\n"; display(B);
    cout<<"\nResult (A+B):\n"; display(C);
}
