//Check Palindrome in Doubly Linked List.

#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *prev, *next;
    Node(int x){ data=x; prev=next=NULL; }
};

bool isPalindrome(Node* head){
    if(!head) return true;
    Node* left=head;
    Node* right=head;

    while(right->next) right=right->next; // go to last node

    while(left!=right && right->next!=left){
        if(left->data!=right->data)
            return false;
        left=left->next;
        right=right->prev;
    }
    return true;
}

int main(){
    Node* a=new Node(1);
    a->next=new Node(2); a->next->prev=a;
    a->next->next=new Node(3); a->next->next->prev=a->next;
    a->next->next->next=new Node(2); a->next->next->next->prev=a->next->next;
    a->next->next->next->next=new Node(1); a->next->next->next->next->prev=a->next->next->next;

    if(isPalindrome(a)) cout<<"Palindrome";
    else cout<<"Not Palindrome";
}
