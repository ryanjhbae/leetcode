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
        return node && !node->left && !node->right;
    }
    
    // DFS approach
    // ignore the variable running times on LeetCode,
    //   this is just O(n) w.r.t. number of nodes
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        std::queue<std::pair<TreeNode *, int>> nodeQ;
        nodeQ.emplace(root, 0);
        
        do {
            
            TreeNode *node = nodeQ.front().first;
            int sumSoFar = nodeQ.front().second;
            nodeQ.pop();
            sumSoFar += node->val;

            
            if (sumSoFar == targetSum && isALeaf(node)) {
                return true;
            } else {
                if (node->left) {
                    nodeQ.emplace(node->left, sumSoFar);
                }
                if (node->right) {
                    nodeQ.emplace(node->right, sumSoFar);
                }
            }
            
        } while (!nodeQ.empty());
        
        return false;
    }
};