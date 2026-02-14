class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {

        // Initialisation
        // LCS=0, when there is no string
        int n = text1.length(), m = text2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        // Loop through the dp[1][1] to dp[n][m]
        // Keep filling the LCS values for different string lengths
        for(int i=1; i<n+1; i++){
            for(int j=1; j<m+1; j++){

                // When the last element is equal, then add 1 to LCS and
                // loop over the remaining string lengths(n-1 and m-1)
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
                    // If the last element is unequal then we have 2 cases (Take max)
            }
        }
        // Last grid will contain the answer
        return dp[n][m];
    }
};