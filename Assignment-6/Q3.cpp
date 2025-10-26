//Find Size of DLL & CLL.

#include <iostream>
using namespace std;

// Doubly Node
struct DNode {
    int data;
    DNode *prev, *next;
    DNode(int x){ data=x; prev=next=NULL; }
};

int sizeDLL(DNode* head){
    int c=0;
    while(head){ c++; head=head->next; }
    return c;
}

// Circular Node
struct CNode{
    int data;
    CNode* next;
    CNode(int x){ data=x; next=NULL; }
};

int sizeCLL(CNode* last){
    if(!last) return 0;
    int c=0;
    CNode* p=last->next;
    do{
        c++; p=p->next;
    }while(p!=last->next);
    return c;
}

int main(){
    // DLL Example
    DNode *a=new DNode(10);
    a->next=new DNode(20); a->next->prev=a;
    a->next->next=new DNode(30); a->next->next->prev=a->next;

    cout<<"Size of Doubly Linked List: "<<sizeDLL(a)<<endl;

    // CLL Example
    CNode* last=new CNode(1);
    last->next=last;
    CNode* t1=new CNode(2); t1->next=last->next; last->next=t1; last=t1;
    CNode* t2=new CNode(3); t2->next=last->next; last->next=t2; last=t2;

    cout<<"Size of Circular Linked List: "<<sizeCLL(last)<<endl;
}
