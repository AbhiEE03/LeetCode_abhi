class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n = s.length();

        // Taking the second string for LCS
        // Directly reversing won't be helpful
        string s1 = s;
        reverse(s1.begin(), s1.end());

        // Initialisation
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));

        // Code for LCS
        for(int i=1; i<n+1; i++){
            for(int j=1; j<n+1; j++){
                if(s[i-1] == s1[j-1])
                    dp[i][j] = 1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        
        // LPS(s) = LCS(s, reverse(S))
        return dp[n][n];
    }
};