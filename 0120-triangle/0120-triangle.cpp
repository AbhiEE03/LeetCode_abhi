class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        int n = triangle[m-1].size();

        vector<vector<int>> dp(m, vector<int> (n, 0));
        for(int j=0; j<n; j++)
            dp[m-1][j] = triangle[m-1][j];
            // All the cell will have sum equal to the value in it
        
        // for row = i, col = 0,1,,....,i
        for(int i=m-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                // We can choose the path giving min sum
                // Among going down and right
                dp[i][j] = min((triangle[i][j] + dp[i+1][j]), (triangle[i][j] + dp[i+1][j+1]));
            }
        }
        return dp[0][0];
    }
};
// We can further optimise it using 2 1-D vectors, front(by last row) and curr
// each time after storing the value in current, assign it into front as
//  you finish the for loop of j 
// front[0] will have the answer