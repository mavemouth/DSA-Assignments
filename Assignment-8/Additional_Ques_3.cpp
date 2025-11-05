#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const vector<int>& nodes) {
    if (nodes.empty() || nodes[0] == -1) return nullptr;
    
    TreeNode* root = new TreeNode(nodes[0]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = 1;
    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();
        
        if (i < nodes.size() && nodes[i] != -1) {
            current->left = new TreeNode(nodes[i]);
            q.push(current->left);
        }
        i++;
        
        if (i < nodes.size() && nodes[i] != -1) {
            current->right = new TreeNode(nodes[i]);
            q.push(current->right);
        }
        i++;
    }
    
    return root;
}

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {1, 2, 3, 4, 5, 6, -1, -1, -1, 7, -1, 8},
        {1, 2, -1, 4, -1, 5, 6},
        {8, -1, 9, -1, 10, 11, 12},
        {28, 14, 11, -1, 48},
        {6}
    };
    
    for (int i = 0; i < testCases.size(); i++) {
        TreeNode* root = buildTree(testCases[i]);
        cout << "Test case " << i + 1 << " - Maximum depth: " << maxDepth(root) << endl;
    }
    
    return 0;
}