// //// Tabulation w/o space optimisation //// //
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         // Initialisation
//         // size[n+12][2] with 0 profit bec we are accesing i+2 after selling
//         vector<vector<int>> dp(n + 2, vector<int>(2, 0));

//         // Base Case
//         // After reaching the end, we can't buy or sell anything
//         // dp[n][0] = dp[n][1] = 0; (NOt required bec we are initialising with 0)

//         for (int i = n - 1; i >= 0; i--) {

//             // buying curr + selling next, didn't buy curr + buying the next
//             dp[i][1] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);

//             // selling curr + buying next, didn't sell curr + selling the next
//             dp[i][0] = max(prices[i] + dp[i + 2][1], 0 + dp[i + 1][0]);
//         }
//         // return the last dpp state
//         return dp[0][1];
//     }
// };



//// Space Optimized //// //
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Initialisation
        // 2 vectors for storing the next_state and temp_state
        vector<int> next_state(2, 0), n_next_state(2, 0), curr_state(2, 0);

        // No stocks = No profit
        // next_state[0] = next_state[1] = 0; (Not required)

        for (int i=n - 1; i >= 0; i--) {

            // profit = buy curr + sell next, buy next
            curr_state[1] = max(-prices[i] + next_state[0], next_state[1]);

            // profit = sell curr + buy next, sell next
            curr_state[0] = max(prices[i] + n_next_state[1], next_state[0]);
        // store the temp as next state for coming iteration
        n_next_state = next_state;
        next_state = curr_state;
        }
    
    // Return the last state
    return next_state[1];
    }
};
