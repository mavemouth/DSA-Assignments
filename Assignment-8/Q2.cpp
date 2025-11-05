#include <iostream>
#include <stack>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// (a) Search - Recursive
BSTNode* searchRecursive(BSTNode* root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    
    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// (a) Search - Non-Recursive
BSTNode* searchNonRecursive(BSTNode* root, int key) {
    while (root != nullptr && root->data != key) {
        if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return root;
}

// (b) Maximum element
BSTNode* findMax(BSTNode* root) {
    if (root == nullptr) return nullptr;
    while (root->right != nullptr)
        root = root->right;
    return root;
}

// (c) Minimum element
BSTNode* findMin(BSTNode* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr)
        root = root->left;
    return root;
}

// (d) In-order successor
BSTNode* inOrderSuccessor(BSTNode* root, BSTNode* node) {
    if (node->right != nullptr)
        return findMin(node->right);
    
    BSTNode* successor = nullptr;
    while (root != nullptr) {
        if (node->data < root->data) {
            successor = root;
            root = root->left;
        } else if (node->data > root->data) {
            root = root->right;
        } else {
            break;
        }
    }
    return successor;
}

// (e) In-order predecessor
BSTNode* inOrderPredecessor(BSTNode* root, BSTNode* node) {
    if (node->left != nullptr)
        return findMax(node->left);
    
    BSTNode* predecessor = nullptr;
    while (root != nullptr) {
        if (node->data > root->data) {
            predecessor = root;
            root = root->right;
        } else if (node->data < root->data) {
            root = root->left;
        } else {
            break;
        }
    }
    return predecessor;
}

// Helper function to insert nodes
BSTNode* insert(BSTNode* root, int val) {
    if (root == nullptr) return new BSTNode(val);
    
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    
    return root;
}

int main() {
    BSTNode* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    // Test search functions
    BSTNode* found = searchRecursive(root, 40);
    cout << "Search 40 (recursive): " << (found ? "Found" : "Not found") << endl;
    
    found = searchNonRecursive(root, 40);
    cout << "Search 40 (non-recursive): " << (found ? "Found" : "Not found") << endl;
    
    // Test max and min
    BSTNode* maxNode = findMax(root);
    BSTNode* minNode = findMin(root);
    cout << "Max element: " << (maxNode ? maxNode->data : -1) << endl;
    cout << "Min element: " << (minNode ? minNode->data : -1) << endl;
    
    // Test successor and predecessor
    BSTNode* node40 = searchRecursive(root, 40);
    BSTNode* succ = inOrderSuccessor(root, node40);
    BSTNode* pred = inOrderPredecessor(root, node40);
    cout << "In-order successor of 40: " << (succ ? succ->data : -1) << endl;
    cout << "In-order predecessor of 40: " << (pred ? pred->data : -1) << endl;
    
    return 0;
}