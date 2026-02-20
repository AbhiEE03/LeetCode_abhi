class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        //  Reversing directly won't help because reverse doesn't return anything 
        // So store s in a new string s1 and reverse it 
        // The apply LCS(s, s1)
        string s1 = s;
        reverse(s1.begin(), s1.end());

        // Initialisation
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

        //  Code for LCS(ab to yaad ho gya)
        for( int i=1; i<n+1; i++){
             for( int j =1; j<n+1; j++){
                if(s[i-1] == s1[j-1])
                    dp[i][j] =  1+dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
             }
        }

        // Min No. of insertions = Min No. of deletions = s.length - LCS
        return n - dp[n][n];
    }
};