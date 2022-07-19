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
    bool isALeaf(TreeNode *node) {
        if (!node) {
            return false;
        } else {
            return !(node->left || node->right);
        }
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        
        if (!root || isALeaf(root)) return 0;
        
        std::queue<std::pair<TreeNode *, bool>> nodeQueue;
        
        // bool is true iff the node in the pair is a left child of some other node
        
        nodeQueue.emplace(root, false);
        
        int sum = 0;
        
        do {
            TreeNode *node = nodeQueue.front().first;
            bool isALeftChild = nodeQueue.front().second;
            nodeQueue.pop();
            
            if (isALeftChild && isALeaf(node)) {
                sum += node->val;
            }
            
            if (node->left) {
                nodeQueue.emplace(node->left, true);
            }
            
            if (node->right) {
                nodeQueue.emplace(node->right, false);
            }
            
        } while (!nodeQueue.empty());
        
        return sum;
    }
};