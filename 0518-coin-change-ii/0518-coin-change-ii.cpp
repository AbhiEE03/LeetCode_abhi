class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        // Initialisation
        vector<vector<unsigned int>> dp(n+1, vector<unsigned int> (amount+1, 0));
        for(int i=0; i<n+1; i++)
            dp[i][0] = 1;

        // Add all possible cases
        for(int i=1; i<n+1; i++){
             for( int j=1; j<amount+1; j++){

                if(coins[i-1]<=j)
                    dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
             }
        }

        return dp[n][amount];
        
    }
};