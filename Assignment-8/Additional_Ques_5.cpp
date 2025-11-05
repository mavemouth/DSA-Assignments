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

TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd,
                         vector<int>& inorder, int inStart, int inEnd,
                         unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;
    
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inRoot = inMap[root->val];
    int numsLeft = inRoot - inStart;
    
    root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft,
                                inorder, inStart, inRoot - 1, inMap);
    root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd,
                                 inorder, inRoot + 1, inEnd, inMap);
    
    return root;
}

TreeNode* buildTreeFromPreIn(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> inMap;
    for (int i = 0; i < inorder.size(); i++) {
        inMap[inorder[i]] = i;
    }
    
    return buildTreeHelper(preorder, 0, preorder.size() - 1,
                          inorder, 0, inorder.size() - 1, inMap);
}

void postOrder(TreeNode* root) {
    if (root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}

int main() {
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};
    
    TreeNode* root = buildTreeFromPreIn(preorder, inorder);
    
    cout << "Post-order traversal of constructed tree: ";
    postOrder(root);
    cout << endl;
    
    return 0;
}