//Split a Circular Linked List into Two Halves.

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

class CLL {
public:
    Node* last;
    CLL(){ last=NULL; }

    void insertEnd(int x){
        Node* t=new Node(x);
        if(!last){ last=t; t->next=t; return; }
        t->next=last->next;
        last->next=t;
        last=t;
    }

    void split(Node* &head1, Node* &head2){
        if(!last) return;
        Node* slow = last->next;       // head
        Node* fast = last->next;

        while(fast->next!=last->next && fast->next->next!=last->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        head1 = last->next;   // head of 1st half
        head2 = slow->next;   // head of 2nd half

        slow->next = head1;   // complete 1st circle

        Node* p = head2;
        while(p->next != last->next) p=p->next;
        p->next = head2;      // complete 2nd circle
    }

    void display(Node* head){
        if(!head) return;
        Node* p=head;
        do{ cout<<p->data<<" "; p=p->next; }while(p!=head);
        cout<<"\n";
    }
};

int main(){
    CLL c;
    c.insertEnd(10);
    c.insertEnd(20);
    c.insertEnd(30);
    c.insertEnd(40);
    c.insertEnd(50);

    Node *h1=NULL, *h2=NULL;
    c.split(h1,h2);

    cout<<"First Half: ";
    c.display(h1);
    cout<<"Second Half: ";
    c.display(h2);
}
