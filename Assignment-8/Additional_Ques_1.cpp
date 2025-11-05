#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

int sumOfLeftLeaves(TreeNode* root, bool isLeft = false) {
    if (root == nullptr) return 0;
    
    if (root->left == nullptr && root->right == nullptr && isLeft) {
        return root->val;
    }
    
    return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
}

int main() {
    // Create the tree: [3,9,20,null,null,15,7]
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    
    cout << "Sum of left leaves: " << sumOfLeftLeaves(root) << endl;
    
    return 0;
}