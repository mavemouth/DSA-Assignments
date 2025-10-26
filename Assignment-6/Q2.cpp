//Display Circular List and Repeat Head.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

class CLL {
    Node* last;
public:
    CLL(){ last=NULL; }

    void insertEnd(int x){
        Node* t = new Node(x);
        if(!last){
            last=t;
            t->next=t;
            return;
        }
        t->next=last->next;
        last->next=t;
        last=t;
    }

    void displayRepeatHead(){
        if(!last){
            cout<<"Empty\n"; return;
        }
        Node* p = last->next; // head
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=last->next);

        cout<<last->next->data<<" (head again)\n";
    }
};

int main(){
    CLL c;
    c.insertEnd(10);
    c.insertEnd(20);
    c.insertEnd(30);

    cout<<"Circular List with Repeat Head:\n";
    c.displayRepeatHead();
}
