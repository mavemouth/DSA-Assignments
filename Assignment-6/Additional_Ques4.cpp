// Clone Linked List with Random Pointer.

#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* random;
    Node(int x){
        data = x;
        next = NULL;
        random = NULL;
    }
};

// Function to clone the list
Node* cloneList(Node* head){
    if(!head) return NULL;

    unordered_map<Node*, Node*> mp; // map original → clone

    Node* curr = head;
    while(curr){
        mp[curr] = new Node(curr->data); // create copy of every node
        curr = curr->next;
    }

    curr = head;
    while(curr){
        mp[curr]->next = mp[curr->next];       // link next pointers
        mp[curr]->random = mp[curr->random];   // link random pointers
        curr = curr->next;
    }

    return mp[head]; // cloned head
}

// Display function to show data and random pointer values
void display(Node* head){
    while(head){
        cout << "Node: " << head->data;
        if(head->random)
            cout << " | Random: " << head->random->data;
        else
            cout << " | Random: NULL";
        cout << endl;
        head = head->next;
    }
}

int main(){
    // Creating original list manually:
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Assign random pointers
    head->random = head->next->next;       // 1 → 3
    head->next->random = head;             // 2 → 1
    head->next->next->random = head->next; // 3 → 2

    cout << "Original List:\n";
    display(head);

    // Clone the list
    Node* cloned = cloneList(head);

    cout << "\nCloned List:\n";
    display(cloned);

    return 0;
}
