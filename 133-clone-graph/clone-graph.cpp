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
    unordered_map<int, Node*> cloned; 
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr; 
        }
        return clone(node); 
    }
    Node* clone(Node* node) {
        if (cloned.contains(node->val)) {
            return cloned[node->val]; 
        }
        Node* clonedNode = new Node(node->val);
        cloned[node->val] = clonedNode; 

        vector<Node*> newNeighbours; 
        for (Node* neigh : node->neighbors) {
            newNeighbours.push_back(clone(neigh)); 
        }
        clonedNode->neighbors = newNeighbours; 
        return clonedNode; 
    }
};