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
    const int unbalanced = -1;
    // instead of throwing an exception you could just have some constant to represent the height of an unbalanced tree
    // easy recursive solution
    int getNodeHeight(TreeNode *root) {
        if (!root) {
            return 0;
        } else if (!root->left && !root->right) {
            return 1;
        } 
        
        int leftHeight = 0, rightHeight = 0;
        
        if (root->left) {
            leftHeight = getNodeHeight(root->left);
        }
        
        if (root->right) {
            rightHeight = getNodeHeight(root->right);
        }
        
        if (std::abs(rightHeight - leftHeight) > 1) {
            return unbalanced;
        } else if (rightHeight == unbalanced || leftHeight == unbalanced) {
            return unbalanced;
        } else {
            return std::max(rightHeight, leftHeight) + 1;
        }
    }
    
    bool isBalanced(TreeNode* root) {
        int height = getNodeHeight(root);
        if (height == unbalanced) {
            return false;
        } else {
            return true;
        }
    }
};