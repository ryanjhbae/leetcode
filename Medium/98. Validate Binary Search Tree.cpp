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

    // a better way would be to just pass the bounding nodes directly instead of the values
    bool isValidBSTRecursive(TreeNode *node, int min, int max, bool left_bounded, bool                                            right_bounded) {
        
        if (!node) return true;
        if (left_bounded && node->val <= min) {
            return false;
        }
        if (right_bounded && node->val >= max) {
            return false;
        }
        
        bool leftValid = true;
        bool rightValid = true;
        
        if (node->left) {
            leftValid = isValidBSTRecursive(node->left, min, std::min(max, node->val), left_bounded,                            true);
        }
        if (node->right) {
            rightValid = isValidBSTRecursive(node->right, std::max(min, node->val), max, true,                                                    right_bounded);
        }
        return leftValid && rightValid;
    }
    
    bool isValidBST(TreeNode* root) {
        // tricky part is ensuring that the subtrees beyond just the 
        //   immediate children actually follow the rules
        return isValidBSTRecursive(root, INT_MIN, INT_MAX, false, false);
    }
};