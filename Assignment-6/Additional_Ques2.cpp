// Remove Nodes whose Binary has Even Number of 1s.

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

int parity(int x){
    int c=0; while(x){ c+=x&1; x>>=1; } return c;
}

Node* removeEvenParity(Node* head){
    Node* curr=head, *prev=NULL;
    while(curr){
        if(parity(curr->data)%2==0){
            if(!prev) head=curr->next;
            else prev->next=curr->next;
            Node* t=curr; curr=curr->next;
            delete t;
        } else {
            prev=curr; curr=curr->next;
        }
    }
    return head;
}

void display(Node* head){
    while(head){ cout<<head->data<<" "; head=head->next; }
    cout<<"\n";
}

int main(){
    Node* head=new Node(5);          
    head->next=new Node(7);          
    head->next->next=new Node(10);   
    head->next->next->next=new Node(15); 

    head = removeEvenParity(head);
    display(head);
}
