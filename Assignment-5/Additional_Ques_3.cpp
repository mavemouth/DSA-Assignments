#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x){ data = x; next = NULL; }
};

void removeLoop(Node* head){
    Node *slow = head, *fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }

    if(slow != fast) return; // no loop

    slow = head;
    Node* prev = NULL;

    while(slow != fast){
        prev = fast;
        slow = slow->next;
        fast = fast->next;
    }

    prev->next = NULL; // loop removed
}

int main(){
    Node* head=new Node(1);
    head->next=new Node(7);
    head->next->next=new Node(3);
    head->next->next->next=new Node(6);
    head->next->next->next->next=head->next; // loop created

    removeLoop(head);

    Node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
