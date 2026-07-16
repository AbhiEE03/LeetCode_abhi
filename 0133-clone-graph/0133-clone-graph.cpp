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
private:
    // Our map: Key = Original Node, Value = Cloned Node
    unordered_map<Node*, Node*> visited;

    Node* dfs(Node* originalNode) {
        if (originalNode == NULL)
            return NULL;

        if (visited.find(originalNode) != visited.end()) {
            return visited[originalNode];
        }

        Node* cloneNode = new Node(originalNode->val);

        visited[originalNode] = cloneNode;

        // Loop through all neighbors of the original node
        for (Node* neighbor : originalNode->neighbors) {
            // Recursively clone the neighbor and attach it to our clone's
            // neighbor list
            cloneNode->neighbors.push_back(dfs(neighbor));
        }

        return cloneNode;
    }

public:
    Node* cloneGraph(Node* node) { return dfs(node); }
};
