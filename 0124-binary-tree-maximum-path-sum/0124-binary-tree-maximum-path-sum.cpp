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

    int maxPathSum (TreeNode* root){
        int maxi=INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }


    int maxPathDown(TreeNode* root, int &maxi) {
        if(root==NULL) return 0;

        int left_Sum= max(0, maxPathDown(root->left, maxi));
        int right_Sum= max(0, maxPathDown(root->right, maxi));

        maxi = max(maxi, left_Sum + right_Sum + root->val);

        return root->val + max(left_Sum, right_Sum);
    }
};