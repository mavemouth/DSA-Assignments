#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

void BSTToSortedDLL(TreeNode* root, ListNode*& head, ListNode*& prev) {
    if (root == nullptr) return;
    
    BSTToSortedDLL(root->left, head, prev);
    
    ListNode* newNode = new ListNode(root->val);
    if (prev == nullptr) {
        head = newNode;
    } else {
        prev->next = newNode;
        newNode->prev = prev;
    }
    prev = newNode;
    
    BSTToSortedDLL(root->right, head, prev);
}

ListNode* mergeSortedDLL(ListNode* head1, ListNode* head2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* tail = dummy;
    
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val <= head2->val) {
            tail->next = head1;
            head1->prev = tail;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2->prev = tail;
            head2 = head2->next;
        }
        tail = tail->next;
    }
    
    if (head1 != nullptr) {
        tail->next = head1;
        head1->prev = tail;
    } else {
        tail->next = head2;
        if (head2 != nullptr) head2->prev = tail;
    }
    
    ListNode* result = dummy->next;
    if (result != nullptr) result->prev = nullptr;
    delete dummy;
    return result;
}

void printDLL(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val;
        if (current->next != nullptr) cout << " <--> ";
        current = current->next;
    }
    cout << " <--> null" << endl;
}

int main() {
    // Create first BST
    TreeNode* root1 = new TreeNode(20);
    root1->left = new TreeNode(10);
    root1->right = new TreeNode(30);
    root1->right->left = new TreeNode(25);
    root1->right->right = new TreeNode(100);
    
    // Create second BST
    TreeNode* root2 = new TreeNode(50);
    root2->left = new TreeNode(5);
    root2->right = new TreeNode(70);
    
    // Convert BSTs to sorted DLLs
    ListNode* head1 = nullptr, *prev1 = nullptr;
    ListNode* head2 = nullptr, *prev2 = nullptr;
    
    BSTToSortedDLL(root1, head1, prev1);
    BSTToSortedDLL(root2, head2, prev2);
    
    // Merge the two sorted DLLs
    ListNode* mergedHead = mergeSortedDLL(head1, head2);
    
    cout << "Merged sorted doubly linked list: ";
    printDLL(mergedHead);
    
    return 0;
}