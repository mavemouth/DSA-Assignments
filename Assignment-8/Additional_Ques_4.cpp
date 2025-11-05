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

vector<int> rightView(TreeNode* root) {
    vector<int> result;
    if (root == nullptr) return result;
    
    queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();
            
            // Last node in current level
            if (i == levelSize - 1) {
                result.push_back(current->val);
            }
            
            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
    }
    
    return result;
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {1, 2, -1, 4, -1, 5, 6},
        {6, -1, 4},
        {8, -1, 9, -1, 10, 11, 12},
        {28, 14, 11, -1, 48},
        {6},
        {3, -1, 2, 1, 5, -1, 6}
    };
    
    for (int i = 0; i < testCases.size(); i++) {
        TreeNode* root = buildTree(testCases[i]);
        vector<int> result = rightView(root);
        
        cout << "Test case " << i + 1 << " - Right view: ";
        for (int val : result) cout << val << " ";
        cout << endl;
    }
    
    return 0;
}