class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int n = word1.length(), m = word2.length();

        // Initialisation
        vector<vector< int>> dp(n+1, vector<int>(m+1, 0));

        //  Code for LCS
        for(int i=1; i<n+1; i++){
            for( int j=1; j<m+1; j++){ 
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }

        //  Total no. of insertions+ deletions
         return (n+m) - 2*dp[n][m];
    }
};