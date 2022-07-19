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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rsv;
        if (!root) return rsv;
        
        // the tricky part is that you can't just only look at the right nodes
        //   you have to look at the rightmost node at each level
        std::queue<std::pair<TreeNode *, int>> nodeQueue; // the int is the level
        nodeQueue.emplace(root, 0);
        
        // if we do a breadth first search from right to left, we can guarantee
        //   that the rightmost node at each level is looked at first
        // so essentially, do this, and only add the first node we encounter at
        //   a given level to the vector. The other nodes in that level
        //   serve only to give us access to their children
        
        while (!nodeQueue.empty()) {
            auto front = nodeQueue.front();
            TreeNode *node = front.first;
            int level = front.second;
            nodeQueue.pop();
            if (level == rsv.size()) {
                rsv.push_back(node->val);
            }
            if (node->right) {
                nodeQueue.emplace(node->right, level + 1);
            }
            if (node->left) {
                nodeQueue.emplace(node->left, level + 1);
            }
        }
        return rsv;
    }
};