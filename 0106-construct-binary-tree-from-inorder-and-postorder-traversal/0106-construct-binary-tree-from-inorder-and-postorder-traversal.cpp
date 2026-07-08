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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap;
        
        // Map the values to their indices for O(1) lookup
        for(int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }
        
        return build(postorder, 0, postorder.size() - 1,
                     inorder, 0, inorder.size() - 1, inMap);
    }
    
private:
    TreeNode* build(vector<int>& postorder, int postStart, int postEnd,
                    vector<int>& inorder, int inStart, int inEnd, 
                    unordered_map<int, int>& inMap) {
                        
        // Base case: if the pointers cross, there are no nodes left to build
        if(postStart > postEnd || inStart > inEnd) return nullptr;
        
        // 1. In Postorder, the root is always at the END of the segment
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        // 2. Find where this root sits in the Inorder array
        int inRoot = inMap[root->val];
        
        // 3. Count how many nodes are purely in the left subtree
        int numsLeft = inRoot - inStart;
        
        // 4. Build Left Subtree
        root->left = build(postorder, postStart, postStart + numsLeft - 1,
                           inorder, inStart, inRoot - 1, inMap);
                           
        // 5. Build Right Subtree
        root->right = build(postorder, postStart + numsLeft, postEnd - 1,
                            inorder, inRoot + 1, inEnd, inMap);
                            
        return root;
    }
};