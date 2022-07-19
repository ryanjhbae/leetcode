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

    int kthSmallest(TreeNode* root, int k) {
        // Initial approach:
        // you can get O(nlogn + k) running time
        // since a heap has logarithmic insert, to insert all elements we would need nlogn time
        //   then pop k elements to get the kth smallest element
        if (!root) return 0;
        std::priority_queue<int, std::vector<int>, std::greater<int>> heap; // need a minHeap
        std::queue<TreeNode *> nodeQueue;

        // use BFS to priority-sort all elements, then take the kth 
        //   smallest element from the final heap
        
        TreeNode *node;
        nodeQueue.push(root);
        do {
            node = nodeQueue.front();
            nodeQueue.pop();

            if (node->left) {
                nodeQueue.push(node->left);
            }
            if (node->right) {
                nodeQueue.push(node->right);
            }
            heap.push(node->val);
            
        } while (!nodeQueue.empty());

        for (int i = 0; i < k - 1; ++i) {
            heap.pop();
        }
        return heap.top();

        // Better solution (looked at the solution page):
        // - Use the fact that the kth smallest element should be
        //   the kth leftmost element.

        // Java solution
        /*
        class Solution {
            public int kthSmallest(TreeNode root, int k) {
                LinkedList<TreeNode> stack = new LinkedList<>();

                while (true) {
                    while (root != null) {
                        stack.push(root);
                        root = root.left;
                    }
                    root = stack.pop();
                    if (--k == 0) return root.val;
                    root = root.right;
                }
            }
        }
        */
    }
};