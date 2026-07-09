/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;
        
        while (curr != NULL) {
            // If there is a left child, it needs to be merged into the right side
            if (curr->left != NULL) {
                
                // Find the absolute rightmost node in the left subtree
                TreeNode* rightmost = curr->left;
                while (rightmost->right != NULL) {
                    rightmost = rightmost->right;
                }
                
                //  Connect this rightmost node to our current right child
                rightmost->right = curr->right;
                
                // Shift the entire left subtree over to the right side
                curr->right = curr->left;
                curr->left = NULL;
            }
            
            // Move down the right pointer to keep flattening
            curr = curr->right;
        }
    }
};