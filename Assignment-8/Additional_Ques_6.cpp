#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                         vector<int>& postorder, int postStart, int postEnd,
                         unordered_map<int, int>& inMap) {
    if (inStart > inEnd || postStart > postEnd) return nullptr;
    
    TreeNode* root = new TreeNode(postorder[postEnd]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    
    root->left = buildTreeHelper(inorder, inStart, inRoot - 1,
                                postorder, postStart, postStart + numsLeft - 1, inMap);
    root->right = buildTreeHelper(inorder, inRoot + 1, inEnd,
                                 postorder, postStart + numsLeft, postEnd - 1, inMap);
    
    return root;
}

TreeNode* buildTreeFromInPost(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    return buildTreeHelper(inorder, 0, inorder.size() - 1,
                          postorder, 0, postorder.size() - 1, inMap);
}

void preOrder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> postorder = {9, 15, 7, 20, 3};
    
    TreeNode* root = buildTreeFromInPost(inorder, postorder);
    
    cout << "Pre-order traversal of constructed tree: ";
    preOrder(root);
    cout << endl;
    
    return 0;
}