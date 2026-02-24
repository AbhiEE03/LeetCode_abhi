class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long long>>dp(m, vector<long long>(n, 1));
    
        if(obstacleGrid[m-1][n-1] == 1) 
            dp[m-1][n-1] = 0;
        else
            dp[m-1][n-1] = 1;
        
        // When we are in the last row : We can go only rightwards(1 way)
        // When we are in the last col : We can go only downwards(1 way)
        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                // Change the dp state only when we move out of last row and last col
                if(i == m-1 && j == n-1) 
                    continue;
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else{
                    long long ans1 = i<m-1 ? dp[i+1][j] : 0;
                    long long ans2 = j<n-1 ? dp[i][j+1] : 0;
                    dp[i][j] = (ans1 + ans2);
                    // We can either go right or left at each step

                }
            }
        }
        // The total no. of ways to go from 0,0 to m-1,n-1
        return dp[0][0];
    }
};