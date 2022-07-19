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

// initial approach: use a hashset to just keep track of 
//   every visited address (dumb but works)
// O(m + n) time, O(m) space
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode *> visitedA; 
        // nodes in list starting at headA

        while (headA) {
            // you are guaranteed that there are no cycles
            visitedA.insert(headA);
            headA = headA->next;
        }
        
        while (headB) {
            if (visitedA.find(headB) != visitedA.end()) {
                return headB;
            } else {
                headB = headB->next;
            }
        }
        return nullptr;
    }

    
};