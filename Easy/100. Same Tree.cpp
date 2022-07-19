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
    
    // monke recursive solution
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if ((!p && q) || (p && !q)) {
            return false; // one null but not the other
        } else if (p == nullptr && q == nullptr) {
            return true;
        }
        
        if (p->val != q->val) {
            return false;
        } else {
            bool leftSame = isSameTree(p->left, q->left);
            bool rightSame = isSameTree(p->right, q->right);
            return leftSame && rightSame;
        }
    }
};