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
    bool isSymmetric(TreeNode* root) {
        
        if (!root) {
            return true;
        } else if (!root->left && root->right) {
            return false;
        } else if (!root->right && root->left) {
            return false;
        } else if (!root->left && !root->right) {
            return true;
        }
        
        std::stack<TreeNode *> leftNodeStack;
        std::stack<TreeNode *> rightNodeStack;
        
        leftNodeStack.push(root->left);
        rightNodeStack.push(root->right);
        
        do {
            TreeNode *leftNode = leftNodeStack.top();
            TreeNode *rightNode = rightNodeStack.top();
            leftNodeStack.pop();
            rightNodeStack.pop();
            
            if (leftNode->val != rightNode->val) {
                return false;
            } else if (leftNode->left && !rightNode->right) {
                return false;
            } else if (!leftNode->left && rightNode->right) {
                return false;
            } else if (leftNode->right && !rightNode->left) {
                return false;
            } else if (!leftNode->right && rightNode->left) {
                return false;
            } else {
                if (leftNode->left) {
                    leftNodeStack.push(leftNode->left);
                    rightNodeStack.push(rightNode->right);
                }
                if (leftNode->right) {
                    leftNodeStack.push(leftNode->right);
                    rightNodeStack.push(rightNode->left);
                }
            }
            
        } while (!leftNodeStack.empty());
        
        return true;
    }
};