#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x){ data = x; next = NULL; }
};

int getLength(Node* head){
    int len = 0;
    while(head){ len++; head = head->next; }
    return len;
}

Node* getIntersection(Node* a, Node* b){
    int lenA = getLength(a);
    int lenB = getLength(b);

    int diff = abs(lenA - lenB);

    if(lenA > lenB) while(diff--) a = a->next;
    else while(diff--) b = b->next;

    while(a && b){
        if(a == b) return a;
        a = a->next;
        b = b->next;
    }
    return NULL;
}

int main(){
    Node* common = new Node(8);
    common->next = new Node(5);

    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = common;

    Node* headB = new Node(5);
    headB->next = new Node(6);
    headB->next->next = new Node(1);
    headB->next->next->next = common;

    Node* ans = getIntersection(headA, headB);

    if(ans) cout<<"Intersected at "<<ans->data;
    else cout<<"No intersection";

    return 0;
}
