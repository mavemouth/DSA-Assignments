#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data = x; next = NULL; }
};

Node* reverseK(Node* head, int k){
    if(!head) return NULL;
    Node *curr = head, *prev = NULL, *next = NULL;
    int count = 0;

    while(curr && count < k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next)
        head->next = reverseK(next, k);

    return prev;
}

void print(Node* head){
    while(head){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(6);
    head->next->next->next->next->next->next=new Node(7);
    head->next->next->next->next->next->next->next=new Node(8);

    int K=3;
    head = reverseK(head, K);

    print(head);
}
