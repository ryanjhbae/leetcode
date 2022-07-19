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
    ListNode* middleNode(ListNode* head) {
        // use two pointers, one moving through the list twice as fast
        // intuition: by the time hare reaches the end, tortoise should be halfway
        // inspired by floyd's tortoise-and-hare cycle detection algorithm
        // but i came up with this without looking at the solution!
        ListNode *tortoise = head;
        ListNode *hare = head;
        while (hare) {
            if (hare->next) {
                hare = hare->next->next;
            } else {
                break;
            }
            tortoise = tortoise->next;
        }
        return tortoise;
    }
};