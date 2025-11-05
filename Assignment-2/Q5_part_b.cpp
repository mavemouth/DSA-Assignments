#include <iostream>
using namespace std;

class TriDiagonal {
    int *A;
    int n;
public:
    TriDiagonal(int n){
        this->n = n;
        A = new int[3*n - 2];
        for(int i=0;i<3*n - 2;i++) A[i] = 0;
    }

    void set(int i, int j, int x){
        if(i == j) A[i-1] = x;
        else if(i == j+1) A[n + j - 1] = x;
        else if(i + 1 == j) A[2*n + i - 1] = x;
    }

    int get(int i, int j){
        if(i == j) return A[i-1];
        else if(i == j+1) return A[n + j - 1];
        else if(i + 1 == j) return A[2*n + i - 1];
        return 0;
    }

    void display(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                cout << get(i,j) << " ";
            cout << endl;
        }
    }
};

int main(){
    TriDiagonal t(4);
    t.set(1,1,3);
    t.set(1,2,2);
    t.set(2,1,4);
    t.set(2,2,6);
    t.set(2,3,7);
    t.display();
}
