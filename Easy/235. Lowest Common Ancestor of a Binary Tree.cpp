/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // use the bst property to your advantage
        // monke approach: use a set to store each ancestor node of both p and q
        //                 and take the one furthest down in the tree
        
        // better approach:
        TreeNode *node = root;
        int max = p->val;
        int min = q->val;
        if (p->val < q->val) {
            max = q->val;
            min = p->val;
        }
        while (node) {
            if (node->val == min || node->val == max) return node;
            if (node->val < min) {
                node = node->right;
            } else if (node->val > max) {
                node = node->left;
            } else { // min < node->val < max
                return node;
            }
        }
        return node;
    }
};