class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // Initislising by zero has no real significance, it's just a placeholder because 
        // it's getting overwritten anyways
        vector<vector<int>>dp(m, vector<int>(n, 0));

        // Base Case
        dp[m-1][n-1] = grid[m-1][n-1];
        // When we are in the last row : We can go only rightwards(1 way)
        // When we are in the last col : We can go only downwards(1 way)
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                if(i == m-1 && j == n-1) continue;
                // We will have the contribution of down in last col
                // right in last row
                // down + right in all other cells
                int down  = (i < m-1) ? dp[i+1][j] : INT_MAX;
                int right = (j < n-1) ? dp[i][j+1] : INT_MAX;

                dp[i][j] = grid[i][j] + min(down, right);
            }
        }
        // Min Path sum to go from 0,0 to m-1,n-1
        return dp[0][0];
    }
};
// If they had asked for max path sum then we just needed to change 23rd line:
// dp[i][j] = grid[i][j] + max(down, right);
