/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr && l2 == nullptr) {
            return nullptr;
        }
        ListNode *merged = new ListNode;
        ListNode *curnode = merged;

        while (curnode != nullptr) {
            if (l1 == nullptr) {
                curnode->val = l2->val;
                l2 = l2->next;
            } else if (l2 == nullptr) {
                curnode->val = l1->val;
                l1 = l1->next;
            } else if (l1->val <= l2->val) {
                curnode->val = l1->val;
                l1 = l1->next;
            } else {
                curnode->val = l2->val;
                l2 = l2->next;
            }
            
            if (!(l1 == nullptr && l2 == nullptr)) {
                curnode->next = new ListNode;
            }
            curnode = curnode->next;
        }
        return merged;
    }
};