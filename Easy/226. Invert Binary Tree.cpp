/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    #define RECURSIVE 0
    // easy recursive solution
    #if RECURSIVE
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        root->left = invertTree(right);
        root->right = invertTree(left);
        return root;
    }
    #endif
    // iterative solution
    #if !RECURSIVE
    
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return root;
        std::stack<TreeNode *> nodeStack;
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            TreeNode *node = nodeStack.top();
            nodeStack.pop();
            TreeNode *left = nullptr;
            TreeNode *right = nullptr;
            if (node->left) {
                left = node->left;
                nodeStack.push(left);
            }
            if (node->right) {
                right = node->right;
                nodeStack.push(right);
            }
            node->left = right;
            node->right = left;
        }
        return root;
    }
    #endif
};