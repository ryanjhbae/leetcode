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
    // there are k lists
    // N total nodes

    // alternative approach #1 : use merge2lists and merge in pairs 
    //   time complexity: O(logk) pairs, O(N) per pair merging => O(Nlogk) runtime
    //   space: can be done using constant space

    // alternative approach #2 : (i thought of this as well but was too lazy
    //   to implement it) 
    // compare all k lists at once every time to find the smallest value
    // time complexity: O(kN) since we do O(k) comparisons O(N) times for 
    //   O(N) nodes
    // space complexity: can be done using constant space

    // alternative approach #3 : best approach imo
    // use a priority queue to ASSIST with comparing k lists
    //   first, put all heads of the list into the pq along with pointers to 
    //   the node they come from (so node->val is the priority and the pointer is
    //   the value)
    //   while the pq is not empty, take the top value and pop it. take the list
    //   this value came from and insert the next value in that list into the pq.
    // O(Nlogk) time, O(N) space

    // monke approach: add every element to a single priority queue, and then
    //   pop from this pq in order to create your list
    // time complexity: O(logN) insertion into pq, O(1) removal from pq, O(N)
    //   inserts => O(NlogN) runtime
    // space: O(N) space
    // in theory this has the same complexity as just collecting everything, sorting it,
    // then putting it back into a linked list, but in practice this should be faster
    //   since we are essentially sorting it as we go

    #define MONKE 0

    #if MONKE
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        // use a priority queue?
        // O(k log(k)) running time (which is not better than just using
        //   unsorted linked lists, suggesting that we can do 
        //   much better)
        // start with that: just add all the linked lists to a pq and
        //   create the new list from that
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        
        for (auto &list : lists) {
            ListNode *node = list;
            while (node) {
                pq.push(node->val);
                node = node->next;
            }
        }
        
        if (pq.empty()) return nullptr;
        ListNode *root = new ListNode;
        ListNode *node = root;
        while (!pq.empty()) {
            
            node->val = pq.top();
            pq.pop();
            if (!pq.empty()) {
                node->next = new ListNode;
                node = node->next;
            }
        }
        return root;
    }
    #endif
};