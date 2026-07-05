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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        
        long long maxWidth = 0;
        queue<pair<TreeNode*, long long>> q;
        
        // Start the root at index 0
        q.push({root, 0});
        
        while (!q.empty()) {
            int size = q.size();
            
            // The minimum index on the current level (always the first node)
            long long minIndex = q.front().second; 
            long long first = 0, last = 0;
            
            for (int i = 0; i < size; i++) {
                // Normalize the current index to prevent overflow
                long long curIndex = q.front().second - minIndex;
                TreeNode* node = q.front().first;
                q.pop();
                
                // Track the first and last normalized indices of this level
                if (i == 0) first = curIndex;
                if (i == size - 1) last = curIndex;
                
                // Push children with their new calculated indices
                if (node->left) {
                    q.push({node->left, curIndex * 2 + 1});
                }
                if (node->right) {
                    q.push({node->right, curIndex * 2 + 2});
                }
            }
            
            // Calculate max width across all levels
            maxWidth = max(maxWidth, last - first + 1);
        }
        
        return maxWidth;
    }
};