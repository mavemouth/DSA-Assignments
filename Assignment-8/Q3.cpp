#include <iostream>
#include <algorithm>
using namespace std;

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
    BSTNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// (a) Insert element
BSTNode* insert(BSTNode* root, int val) {
    if (root == nullptr) return new BSTNode(val);
    
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    
    return root;
}

// (b) Delete element
BSTNode* deleteNode(BSTNode* root, int key) {
    if (root == nullptr) return root;
    
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            BSTNode* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BSTNode* temp = root->left;
            delete root;
            return temp;
        }
        
        // Node with two children
        BSTNode* temp = root->right;
        while (temp->left != nullptr)
            temp = temp->left;
        
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// (c) Maximum depth
int maxDepth(BSTNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// (d) Minimum depth
int minDepth(BSTNode* root) {
    if (root == nullptr) return 0;
    
    // If left subtree is NULL, recur for right subtree
    if (root->left == nullptr)
        return 1 + minDepth(root->right);
    
    // If right subtree is NULL, recur for left subtree
    if (root->right == nullptr)
        return 1 + minDepth(root->left);
    
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

void inOrder(BSTNode* root) {
    if (root == nullptr) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main() {
    BSTNode* root = nullptr;
    
    // Insert elements
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);
    
    cout << "In-order traversal after insertion: ";
    inOrder(root);
    cout << endl;
    
    cout << "Max depth: " << maxDepth(root) << endl;
    cout << "Min depth: " << minDepth(root) << endl;
    
    // Delete node
    root = deleteNode(root, 30);
    cout << "In-order traversal after deleting 30: ";
    inOrder(root);
    cout << endl;
    
    cout << "Max depth after deletion: " << maxDepth(root) << endl;
    cout << "Min depth after deletion: " << minDepth(root) << endl;
    
    return 0;
}