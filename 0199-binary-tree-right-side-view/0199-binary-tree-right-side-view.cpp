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
    // Helper function for DFS
    void recursion(TreeNode* root, int level, vector<int>& res) {
        if (root == NULL) return;
        
        // If the array size matches the level, we are visiting this level for the first time!
        if (res.size() == level) {
            res.push_back(root->val);
        }
        
        // Traverse RIGHT side FIRST
        recursion(root->right, level + 1, res);
        
        // Then traverse LEFT side
        recursion(root->left, level + 1, res);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        recursion(root, 0, res);
        return res;
    }
};