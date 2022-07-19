/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    #define RECURSIVE 0
    
    #if !RECURSIVE
    // trying an iterative approach
    std::unordered_map<Node *, Node *> bijection;
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        Node *newRoot = new Node(node->val);
        
        // first one should be the node we want to clone from, and the second
        //  should be the node we want to clone TO
        std::stack<std::pair<Node *, Node *>> nodeStack;
        nodeStack.emplace(node, newRoot);
        bijection[node] = newRoot;
        
        while (!nodeStack.empty()) {
            
            Node *source = nodeStack.top().first;
            Node *dest = nodeStack.top().second;
            nodeStack.pop();
            
            for (int i = 0; i < source->neighbors.size(); ++i) {
                Node *neighbor = source->neighbors[i];
                auto lookupResult = bijection.find(neighbor);
                if (lookupResult != bijection.end()) {
                    dest->neighbors.push_back(lookupResult->second);
                } else {
                    Node *newNeighbor = new Node(neighbor->val);
                    nodeStack.emplace(neighbor, newNeighbor);
                    bijection[neighbor] = newNeighbor;
                    dest->neighbors.push_back(newNeighbor);
                }
            }
        }
        return newRoot;
    }
    
    #endif
    
    #if RECURSIVE
    // simple, intuitive recursive solution (DFS)
    std::unordered_map<Node *, Node *> bijection;
    
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        auto lookupResult = bijection.find(node);
        if (lookupResult != bijection.end()) return lookupResult->second;
        
        Node *clone = new Node(node->val);
        bijection[node] = clone;
        
        clone->neighbors.resize(node->neighbors.size());
        
        for (int i = 0; i < clone->neighbors.size(); ++i) {
            clone->neighbors[i] = cloneGraph(node->neighbors[i]);
        }
        
        return clone;
    }
    #endif
};