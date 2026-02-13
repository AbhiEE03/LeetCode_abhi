class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int> (amount+1, 0));

        // You can never have amount+1 no. of coins for a valid amount
        //  because the minimum value of coin is 1
        for(int j=1; j<amount+1; j++)
            dp[0][j] = amount+1;

        for(int i=1; i<n+1; i++){
            for(int j=1; j<amount+1; j++){
            
            // The coin giving valid ans can be taken again
            if(coins[i-1] <= j)
                dp[i][j] = min(dp[i][j-coins[i-1]] + 1, dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
            }
        }

        // If it has >= amount+1 coins then return -1
        return dp[n][amount] >= amount+1 ? -1 : dp[n][amount];
    }
};