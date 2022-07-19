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

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // you are given that the lists are non-empty, and that the numbers
        //   represented are nonnegative
        int carry = 0;
        int digitSum = 0;

        ListNode *node1 = l1;
        ListNode *node2 = l2;

        // store result in l1
        while (node1 || node2) {
            if (!node2) {
                digitSum = node1->val + carry;
            } else {
                digitSum = node1->val + node2->val + carry;
            }
            
            if (digitSum > 9) {
                carry = 1;
                digitSum -= 10;
            } else {
                carry = 0;
            }

            node1->val = digitSum;

            if (!node1->next) {
                if (node2 && node2->next || carry != 0) {
                    node1->next = new ListNode;
                }
            }
            
            node1 = node1->next;
            if (node2) {
                node2 = node2->next;
            }
        }

        return l1;
    }
}