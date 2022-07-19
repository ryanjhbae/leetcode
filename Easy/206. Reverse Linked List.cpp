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
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        ListNode *last = head;
        ListNode *curnode = head;
        ListNode *nextnode = head->next;
        ListNode *nextnextnode;
        while (nextnode) {
            nextnextnode = nextnode->next;
            nextnode->next = curnode;
            curnode = nextnode;
            nextnode = nextnextnode;
        }
        
        last->next = nullptr;
        return curnode;
    }
};