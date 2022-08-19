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
// Linear to the number of nodes
// Uses O(n) space 
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        if (!root) return nodes;
        
        queue<pair<TreeNode *, int>> nodeQueue;
        nodeQueue.emplace(root, 0);
        int currentLevel = -1;

        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front().first;
            int level = nodeQueue.front().second;
            nodeQueue.pop();
            if (level > currentLevel) {
                currentLevel++;
                nodes.emplace_back(initializer_list<int>{node->val});
            } else {
                nodes[currentLevel].push_back(node->val);
            }
            
            if (node->left) {
                nodeQueue.emplace(node->left, level + 1);
            }
            if (node->right) {
                nodeQueue.emplace(node->right, level + 1);
            }
        }
        return nodes;
    }
};