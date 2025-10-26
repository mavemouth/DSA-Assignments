#include <iostream>
using namespace std;

// ----------- DOUBLY LINKED LIST NODE -----------
struct Node {
    int data;
    Node *prev, *next;
    Node(int x){ data=x; prev=next=NULL; }
};

// ----------- DOUBLY LINKED LIST CLASS -----------
class DoublyList {
    Node* head;
public:
    DoublyList(){ head=NULL; }

    void insertBeg(int x){
        Node* t = new Node(x);
        t->next = head;
        if(head) head->prev = t;
        head = t;
    }

    void insertEnd(int x){
        Node* t = new Node(x);
        if(!head){ head=t; return; }
        Node* p=head;
        while(p->next) p=p->next;
        p->next=t;
        t->prev=p;
    }

    void insertAfter(int key,int x){
        Node* p=head;
        while(p && p->data!=key) p=p->next;
        if(!p){ cout<<"Key Not Found\n"; return; }
        Node* t=new Node(x);
        t->next=p->next;
        if(p->next) p->next->prev=t;
        p->next=t; 
        t->prev=p;
    }

    void deleteVal(int key){
        if(!head) return;
        Node* p=head;
        while(p && p->data!=key) p=p->next;
        if(!p) return;
        if(p->prev) p->prev->next=p->next;
        else head=p->next;
        if(p->next) p->next->prev=p->prev;
        delete p;
    }

    void search(int key){
        int pos=0;
        Node* p=head;
        while(p){
            if(p->data==key){
                cout<<"Found at position "<<pos<<"\n";
                return;
            }
            pos++; p=p->next;
        }
        cout<<"Not Found\n";
    }

    void display(){
        Node* p=head;
        while(p){
            cout<<p->data<<" ";
            p=p->next;
        }
        cout<<"\n";
    }
};

// ----------- CIRCULAR LINKED LIST NODE -----------
struct CNode{
    int data;
    CNode* next;
    CNode(int x){ data=x; next=NULL; }
};

// ----------- CIRCULAR LINKED LIST CLASS -----------
class CircularList{
    CNode* last;
public:
    CircularList(){ last=NULL; }

    void insertEnd(int x){
        CNode* t=new CNode(x);
        if(!last){
            last=t;
            t->next=t;
            return;
        }
        t->next=last->next;
        last->next=t;
        last=t;
    }

    void deleteVal(int key){
        if(!last) return;
        CNode* p=last->next, *prev=last;
        do{
            if(p->data==key){
                prev->next=p->next;
                if(p==last) last=prev;
                if(p==last->next && p==last) last=NULL;
                delete p;
                return;
            }
            prev=p; p=p->next;
        }while(p!=last->next);
    }

    void search(int key){
        if(!last){ cout<<"Empty\n"; return; }
        CNode* p=last->next; int pos=0;
        do{
            if(p->data==key){
                cout<<"Found at position "<<pos<<"\n"; return;
            }
            p=p->next; pos++;
        }while(p!=last->next);
        cout<<"Not Found\n";
    }

    void display(){
        if(!last){ cout<<"Empty\n"; return; }
        CNode* p=last->next;
        do{
            cout<<p->data<<" ";
            p=p->next;
        }while(p!=last->next);
        cout<<"\n";
    }
};

// --------------- MAIN FUNCTION -------------------
int main(){
    DoublyList d;
    CircularList c;
    int ch, sub, val, key;

    while(true){
        cout<<"\nSelect Linked List Type:\n";
        cout<<"1. Doubly Linked List\n";
        cout<<"2. Circular Linked List\n";
        cout<<"3. Exit\n";
        cin>>ch;

        if(ch==3) break;

        if(ch==1){ // DOUBLY MENU
            while(true){
                cout<<"\n--- DOUBLY LINKED LIST MENU ---\n";
                cout<<"1.Insert at Beginning\n2.Insert at End\n3.Insert After Value\n4.Delete Value\n5.Search\n6.Display\n7.Back\n";
                cin>>sub;
                if(sub==7) break;
                switch(sub){
                    case 1: cin>>val; d.insertBeg(val); break;
                    case 2: cin>>val; d.insertEnd(val); break;
                    case 3: cin>>key>>val; d.insertAfter(key,val); break;
                    case 4: cin>>val; d.deleteVal(val); break;
                    case 5: cin>>val; d.search(val); break;
                    case 6: d.display(); break;
                }
            }
        }

        else if(ch==2){ // CIRCULAR MENU
            while(true){
                cout<<"\n--- CIRCULAR LINKED LIST MENU ---\n";
                cout<<"1.Insert at End\n2.Delete Value\n3.Search\n4.Display\n5.Back\n";
                cin>>sub;
                if(sub==5) break;
                switch(sub){
                    case 1: cin>>val; c.insertEnd(val); break;
                    case 2: cin>>val; c.deleteVal(val); break;
                    case 3: cin>>val; c.search(val); break;
                    case 4: c.display(); break;
                }
            }
        }
    }
    return 0;
}
