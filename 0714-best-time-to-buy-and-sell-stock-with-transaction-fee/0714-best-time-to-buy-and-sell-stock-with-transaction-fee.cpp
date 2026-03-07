//// Tabulation w/o space optimisation //// //
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // Initialisation
        // size[n+1][2] with 0 profit bec we are accesing i+1 after selling
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base Case
        // After reaching the end, we can't buy or sell anything
        // dp[n][0] = dp[n][1] = 0; (NOt required bec we are initialising with 0)

        for (int i = n - 1; i >= 0; i--) {

            // buying curr + selling next, didn't buy curr + buying the next
            dp[i][1] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);

            // selling curr + buying next, didn't sell curr + selling the next
            dp[i][0] = max(prices[i] + dp[i + 1][1] - fee, 0 + dp[i + 1][0]);
        }
        // return the last dpp state
        return dp[0][1];
    }
};

