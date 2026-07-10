/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
       if (root == NULL) return NULL;
        
        // Track the start of each level
        Node* leftmost = root;
        
        // Loop Downward as long as there is a level below 
        while (leftmost->left != NULL) {
            
            // Traverse across the current level
            Node* curr = leftmost;
            
            while (curr != NULL) {
                // Left child to Right child (same parent)
                curr->left->next = curr->right;
                
                // Right child to Next parent's Left child (different parents)
                if (curr->next != NULL) {
                    curr->right->next = curr->next->left;
                }
                
                // Move Right across the current level
                curr = curr->next;
            }
            
            //  Move Down to the next level
            leftmost = leftmost->left;
        }
        
        // 8. Return
        return root; 
    }
};