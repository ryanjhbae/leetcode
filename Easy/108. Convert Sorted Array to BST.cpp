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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        TreeNode *root = new TreeNode;

        // - first item is the starting index
        // - second item is the ending index (inclusive)
        // - third item is the root of the tree we want to construct
        std::queue<std::tuple<int, int, TreeNode *>> rangeQueue;
        rangeQueue.emplace(0, nums.size() - 1, root);
        int startIndex, endIndex, mid;
        do {
            startIndex = std::get<0>(rangeQueue.front());
            endIndex = std::get<1>(rangeQueue.front());
            TreeNode *node = std::get<2>(rangeQueue.front());
            rangeQueue.pop();
            mid = ( (endIndex + startIndex) / 2 );
            node->val = nums[mid];
            if (mid - 1 >= startIndex) {
                TreeNode *left = new TreeNode;
                node->left = left;
                rangeQueue.emplace(startIndex, mid - 1, left);
            }
            if (mid + 1 <= endIndex) {
                TreeNode *right = new TreeNode;
                node->right = right;
                rangeQueue.emplace(mid + 1, endIndex, right);
            }

        } while (!rangeQueue.empty());
        return root;
    }
};