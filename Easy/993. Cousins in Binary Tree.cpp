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
    
    bool isCousins(TreeNode* root, int x, int y) {
        std::queue<std::tuple<TreeNode *, int, TreeNode *>> nodeQ;
        nodeQ.emplace(root, 0, nullptr);
        int xDepth = -1, yDepth = -1;
        bool xFound = false, yFound = false;
        TreeNode *xParent = nullptr; TreeNode* yParent = nullptr;
        do {
            TreeNode *node = std::get<0>(nodeQ.front());
            int depth = std::get<1>(nodeQ.front());
            TreeNode *parent = std::get<2>(nodeQ.front());
            nodeQ.pop();
            if (node->val == x) {
                xFound = true;
                xDepth = depth;
                xParent = parent;
            } else if (node->val == y) {
                yFound = true;
                yDepth = depth;
                yParent = parent;
            } else {
                if (node->left) {
                    nodeQ.emplace(node->left, depth + 1, node);
                }
                if (node->right) {
                    nodeQ.emplace(node->right, depth + 1, node);
                }
            }
        } while (!(xFound && yFound) && !nodeQ.empty());
        
        if (xFound && yFound) {
            return xDepth == yDepth && xParent != yParent;
        } else {
            return false;
        }
    }
};