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
    
    bool isALeaf(TreeNode* node) {
        if (!node) {
            return false;
        }
        else {
            return !node->left && !node->right;
        }
    }
    
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        } else if (isALeaf(root)) {
            return 1;
        }
        // simple DFS approach
        std::queue<std::pair<TreeNode *, int>> searchQ;
        int max = 1;
        int curDepth = 1;
        
        searchQ.emplace(root, 1);
        TreeNode *node;
        
        do {
            node = searchQ.front().first;
            curDepth = searchQ.front().second;
            searchQ.pop();
            
            if (isALeaf(node)) {
                if (curDepth > max) {
                    max = curDepth;
                }
                else {
                    continue;
                }
            }
            
            if (node->left) {
                searchQ.emplace(node->left, curDepth + 1);    
            }
            
            if (node->right) {
                searchQ.emplace(node->right, curDepth + 1);
            }
            
        } while (!searchQ.empty());     
        
        return max;
    }
};