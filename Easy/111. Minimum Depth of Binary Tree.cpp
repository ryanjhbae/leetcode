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


#ifndef REDO
// this isn't REAL BFS 
// nah it is
class Solution {
public:

    bool isALeaf(TreeNode *node) {
        return node->left == nullptr && node->right == nullptr;
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        std::queue<std::pair<TreeNode *, int>> queue;
        int depth = 1;
        queue.emplace(root, depth);
        
        do {
            auto p = queue.front();
            queue.pop();
            root = p.first;
            depth = p.second;
            
            if (isALeaf(root)) return depth;
            depth++;
            
            if (root->left) {
                queue.emplace(root->left, depth);
            } 
            
            if (root->right) {
                queue.emplace(root->right, depth);
            }
            
        } while (!queue.empty());
        
        return depth;
    }
};

#endif