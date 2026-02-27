class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int j=0; j<n; j++)
            dp[m-1][j] = triangle[m-1][j];
        
        for(int i=m-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                dp[i][j] = min((triangle[i][j] + dp[i+1][j]), (triangle[i][j] + dp[i+1][j+1]));
            }
        }
        return dp[0][0];
    }
};