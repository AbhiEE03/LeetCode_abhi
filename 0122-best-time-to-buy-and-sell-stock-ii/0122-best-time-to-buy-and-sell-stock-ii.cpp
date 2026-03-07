


// //// Tabulation w/o space optimisation //// //
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         // Initialisation
//         // size[n+1][2] with 0 profit
//         vector<vector<int>> dp(n+1, vector<int>(2, 0));

//         // Base Case
//         // After reaching the end, we can't buy or sell anything
//         // dp[n][0] = dp[n][1] = 0; (Not required)

//         for(int i = n-1; i>=0; i--){
//             // buying curr + selling next, didn't buy curr + buying the next
//             dp[i][1] = max(-prices[i] + dp[i + 1][0], 0 + dp[i + 1][1]);

//             // selling curr + buying next, didn't sell curr + selling the next
//             dp[i][0] = max(prices[i] + dp[i + 1][1], 0 + dp[i + 1][0]);
//         }
//         // return the last dp state
//         return dp[0][1];
//     }
// };




// //// Space Optimized //// //
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         // Initialisation
//         // 2 vectors for storing the next_state and temp_state
//         vector<int> next_state(2, 0), curr_state(2,0);

//         // No stocks = No profit
//         // next_state[0] = next_state[1] = 0; (Not required)

//         for(int i = n-1; i >= 0; i--){
//             // buying curr + selling next, didn't buy curr + buying the next
//             curr_state[1] = max(-prices[i] + next_state[0], 0 + next_state[1]);

//             // selling curr + buying next, didn't sell curr + selling the next
//             curr_state[0] = max(prices[i] + next_state[1], 0 + next_state[0]);
//             // store the temp as next state for coming iteration
//             next_state = curr_state;
//         }

//     // Return the last state
//     return next_state[1];
//     }
// };



// //// Using 4 variables //// //
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // Initialise the variables
        int curr_buy, curr_sell, next_buy, next_sell;

        next_buy = next_sell = 0;

        for(int i = n-1; i >= 0; i--){
                
            curr_buy = max(-prices[i] + next_sell, next_buy);
            curr_sell = max(prices[i] + next_buy, next_sell);
                
            next_buy = curr_buy;
            next_sell = curr_sell;
        }

        return next_buy;
    }
};