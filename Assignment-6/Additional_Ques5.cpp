// Convert 2D Matrix to 4-Pointer Doubly Linked Grid.

#include <iostream>
using namespace std;

struct Cell {
    int val;
    Cell *up, *down, *left, *right;
    Cell(int x){
        val = x;
        up = down = left = right = NULL;
    }
};

Cell* convert(int** mat, int r, int c){
    // Create 2D dynamic pointer matrix
    Cell*** a = new Cell**[r];
    for(int i=0; i<r; i++){
        a[i] = new Cell*[c];
        for(int j=0; j<c; j++)
            a[i][j] = new Cell(mat[i][j]);
    }

    // Set links
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(i>0)     a[i][j]->up = a[i-1][j];
            if(i<r-1)   a[i][j]->down = a[i+1][j];
            if(j>0)     a[i][j]->left = a[i][j-1];
            if(j<c-1)   a[i][j]->right = a[i][j+1];
        }
    }

    return a[0][0]; // return top-left cell
}

int main(){
    int r, c;
    cout<<"Enter number of rows and columns: ";
    cin>>r>>c;

    // Create input matrix dynamically
    int** mat = new int*[r];
    for(int i=0; i<r; i++){
        mat[i] = new int[c];
        for(int j=0; j<c; j++){
            cin >> mat[i][j];
        }
    }

    Cell* head = convert(mat, r, c);

    cout<<"Top-left cell value = "<<head->val<<"\n";
    if(head->right) cout<<"Right cell = "<<head->right->val<<"\n";
    if(head->down)  cout<<"Down cell = "<<head->down->val<<"\n";

    return 0;
}
