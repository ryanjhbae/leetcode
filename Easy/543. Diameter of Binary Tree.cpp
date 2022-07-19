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
    
    int longestDiameter = 0;
    
    // here, define height as the longest path between the node and any
    //   leaf node in the subtree with the node as the root
    // the length of a path is defined as the number of nodes in it
    int getHeight(TreeNode *root) {
        int leftHeight = 0;
        int rightHeight = 0;
        if (root->left) {
            leftHeight = getHeight(root->left);
        }
        if (root->right) {
            rightHeight = getHeight(root->right);
        }
        
        int diameter = leftHeight + rightHeight;
        if (diameter > longestDiameter) {
            longestDiameter = diameter;
        }
        return std::max(leftHeight, rightHeight) + 1;
    }
    
    // Intuition: suppose we have the two nodes connected
    //   by the longest path in the tree. These must both be leaf nodes
    //   (simple proof by contradiction). 
    
    // These leaf nodes must share a common parent somewhere, and this 
    //   parent must be part of the path (since a tree is a connected graph with a 
    //   unique path between any two nodes).
    
    // Thus at each node we consider the heights of the left and right subtrees.
    //   If leftHeight + rightHeight > longestDiameter, then we have found a new
    //   longest path between two nodes (the one which uses the current node to connect
    //   the two leaf nodes defining the height for each subtree).
    
    // O(n) time
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        getHeight(root);
        return longestDiameter;
    }
    
};