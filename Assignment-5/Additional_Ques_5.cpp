#include <iostream>
using namespace std;

struct Node{
    int coeff, pow;
    Node* next;
    Node(int c, int p){ coeff=c; pow=p; next=NULL; }
};

Node* add(Node* p1, Node* p2){
    Node* res = NULL, *tail=NULL;
    while(p1 && p2){
        Node* temp;
        if(p1->pow == p2->pow){
            temp = new Node(p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next; p2 = p2->next;
        }
        else if(p1->pow > p2->pow){
            temp = new Node(p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else {
            temp = new Node(p2->coeff, p2->pow);
            p2 = p2->next;
        }

        if(!res) res = tail = temp;
        else { tail->next = temp; tail = temp; }
    }

    while(p1){ tail->next = new Node(p1->coeff, p1->pow); tail=tail->next; p1=p1->next; }
    while(p2){ tail->next = new Node(p2->coeff, p2->pow); tail=tail->next; p2=p2->next; }

    return res;
}

void print(Node* head){
    while(head){
        cout<<head->coeff<<"x^"<<head->pow<<" ";
        head=head->next;
    }
}

int main(){
    Node* p1=new Node(5,2);
    p1->next=new Node(4,1);
    p1->next->next=new Node(2,0);

    Node* p2=new Node(5,1);
    p2->next=new Node(5,0);

    Node* sum = add(p1, p2);

    print(sum);
}
