// Revision //
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // dp[k] = min no. of coins req to make a sum of k
        // transition: dp[k] = min(dp[k-ci(i belongs from 0 - n-1)]) + 1
        // dp[x] = final subproblem

        // To get zero sum u need 0 coins
        // For every amount initialise with very large val as if it's imp to
        // reach
        vector<int> dp(amount + 1, 1e9);

        // Base case = smallest subproblem that needs to be solved
        dp[0] = 0;

        // for(int i = 1; i<=amount; i++){
        //     for(int j = 0; j<n ; j++){
        for (int j = 0; j < n; j++) {
            for (int i = 1; i <= amount; i++) {
                if (coins[j] <= i)
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]);
            }
        }
        return dp[amount] == 1e9 ? -1 : dp[amount];
    }
};

/*
// //// Dynamic Programming //// //
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





// //// Greedy Approach //// //
// It fails because the larger coins can't always give the optimal answer

// class Solution {
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         sort(coins.begin(), coins.end());

//         int currVal = 0, count = 0, i = 0;
//         if(amount == 0 ) return count;

//         while(currVal < amount){
//             if(i < coins.size()){
//                 currVal += coins[i];
//                  count++;
//             }

//             if(currVal == amount) return count;
//             else if(currVal > amount){
//                 currVal -= coins[i];
//                 i++;
//                 count--;
//             }
//         }

//         return -1;
//     }
// };
*/