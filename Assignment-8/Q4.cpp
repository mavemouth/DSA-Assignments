#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isBSTUtil(TreeNode* root, int minVal, int maxVal) {
    if (root == nullptr) return true;
    
    if (root->data <= minVal || root->data >= maxVal)
        return false;
    
    return isBSTUtil(root->left, minVal, root->data) && 
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(TreeNode* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int main() {
    // Test case 1: BST
    TreeNode* root1 = new TreeNode(4);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(3);
    
    cout << "Tree 1 is BST: " << (isBST(root1) ? "Yes" : "No") << endl;
    
    // Test case 2: Not BST
    TreeNode* root2 = new TreeNode(3);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(5);
    root2->left->left = new TreeNode(1);
    root2->left->right = new TreeNode(4); // This violates BST property
    
    cout << "Tree 2 is BST: " << (isBST(root2) ? "Yes" : "No") << endl;
    
    return 0;
}