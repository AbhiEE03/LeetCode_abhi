class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, 1));

        // When we are in the last row : We can go only rightwards(1 way)
        // When we are in the last col : We can go only downwards(1 way)
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                // Change the dp state only when we move out of last row and last col
                if(i<m-1 && j<n-1)
                    dp[i][j] = dp[i+1][j] + dp[i][j+1];
                    // We can either go right or left at each step
            }
        }
        // The total no. of ways to go from 0,0 to m-1,n-1
        return dp[0][0];
    }
};