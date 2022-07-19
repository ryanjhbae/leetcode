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
// easy recursive solution
    #define RECURSIVE 0
    vector<int> nodes;
    #if RECURSIVE
    void inorderTraversalRecursive(TreeNode *root) {
        if (root->left) {
            inorderTraversalRecursive(root->left);
        }
        nodes.push_back(root->val);
        if (root->right) {
            inorderTraversalRecursive(root->right);
        }
    }

    vector<int> inorderTraversal(TreeNode* root) {
        if (root) inorderTraversalRecursive(root);
        return nodes;
        
    }
    #endif

// iterative solution
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return nodes;
        std::stack<TreeNode *> nodeStack;
        TreeNode *node = root;

        while (node) {
            nodeStack.push(node);
            node = node->left;
        }

        while (!nodeStack.empty()) {
            node = nodeStack.top();
            nodeStack.pop();
            nodes.push_back(node->val);
            
            if (node->right) {
                node = node->right;
                while (node) {
                    nodeStack.push(node);
                    node = node->left;
                }
            }
        }
        
        return nodes;
    }
};