//Check if Singly Linked List is Circular.

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

bool isCircular(Node* head){
    if(!head) return false;
    Node* p=head->next;
    while(p && p!=head)
        p=p->next;
    return (p==head);
}

int main(){
    Node* a=new Node(10);
    a->next=new Node(20);
    a->next->next=new Node(30);

    cout<<"Before making circular: "<<(isCircular(a)?"Circular":"Not Circular")<<endl;

    // make circular
    a->next->next->next=a;

    cout<<"After making circular: "<<(isCircular(a)?"Circular":"Not Circular")<<endl;
}
