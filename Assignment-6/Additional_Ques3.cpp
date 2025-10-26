// Reverse Doubly Linked List in Groups of k.

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *prev,*next;
    Node(int x){ data=x; prev=next=NULL; }
};

Node* reverseK(Node* head,int k){
    Node *curr=head, *next=NULL, *prev=NULL;
    int c=0;
    while(curr && c<k){
        next=curr->next;
        curr->next=prev;
        if(prev) prev->prev=curr;
        prev=curr; curr=next; c++;
    }
    if(next){
        head->next=reverseK(next,k);
        head->next->prev=head;
    }
    prev->prev=NULL;
    return prev;
}

void display(Node* head){
    while(head){ cout<<head->data<<" "; head=head->next; }
    cout<<"\n";
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2); head->next->prev=head;
    head->next->next=new Node(3); head->next->next->prev=head->next;
    head->next->next->next=new Node(4); head->next->next->next->prev=head->next->next;
    head->next->next->next->next=new Node(5); head->next->next->next->next->prev=head->next->next->next;

    head = reverseK(head,2);
    display(head);
}
