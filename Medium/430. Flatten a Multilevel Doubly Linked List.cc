/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

#include <stack>
using std::stack;

class Solution {
public:
    Node* flatten(Node* head) {
        if (head == nullptr) return nullptr;
        Node *curnode = head;
        stack<Node *> *queue = new stack<Node *>{};
        while (true) {
            if (curnode->child != nullptr) {
                if (curnode->next != nullptr) {
                    curnode->next->prev = nullptr;
                    queue->push(curnode->next);
                }
                curnode->next = curnode->child;
                curnode->child->prev = curnode;
                curnode->child = nullptr;
            } else if (curnode->next == nullptr) {
                if (queue->empty()) {
                    break; // no more elements to add
                } else {
                    curnode->next = queue->top();
                    queue->pop();
                    curnode->next->prev = curnode;
                }
            }
            curnode = curnode->next;
        }
        delete queue;
        return head;
    }
};