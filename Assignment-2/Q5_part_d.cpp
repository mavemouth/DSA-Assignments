#include <iostream>
using namespace std;

class UpperTriangular {
    int *A;
    int n;
public:
    UpperTriangular(int n){
        this->n = n;
        A = new int[n*(n+1)/2];
    }

    void set(int i, int j, int x){
        if(i <= j)
            A[(i-1)*n - (i*(i-1))/2 + (j-i)] = x;
    }

    int get(int i, int j){
        if(i <= j)
            return A[(i-1)*n - (i*(i-1))/2 + (j-i)];
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
    UpperTriangular u(4);
    u.set(1,2,7);
    u.set(2,3,9);
    u.display();
}
