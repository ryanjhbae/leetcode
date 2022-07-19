/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    
    // initial approach: set storing visited nodes
    // seems quite inefficient
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode *> visited;
        ListNode *node = head;
        while (node) {
            if (visited.find(node) != visited.end()) {
                return true;
            } else {
                visited.insert(node);
            }
            node = node->next;
        }
        return false;
    }

    // need to use some sort of cycle detection algorithm
    // e.g., floyd's tortoise and hare
};