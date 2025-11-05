#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data=x; next=NULL; }
};

Node* rotate(Node* head, int k){
    if(!head) return NULL;

    Node* tail=head;
    int len=1;
    while(tail->next){
        tail=tail->next;
        len++;
    }

    k = k % len;
    if(k == 0) return head;

    tail->next = head;

    while(k--) tail = tail->next;

    Node* newHead = tail->next;
    tail->next = NULL;

    return newHead;
}

void print(Node* head){
    while(head){ cout<<head->data<<" "; head=head->next; }
}

int main(){
    Node* head=new Node(10);
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head->next->next->next->next=new Node(50);

    head = rotate(head, 4);

    print(head);
}
