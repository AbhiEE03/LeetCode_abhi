class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // Initialisation
        // 2 vectors for storing the next_state and temp_state
        vector<int> next_state(2, 0), curr(2,0);

        // No stocks = No profit
        next_state[0] = next_state[1] = 0;

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                int profit = 0;
                if(buy){
                    // profit = buy curr + sell next, buy next
                    profit = max(-prices[i] + next_state[0], next_state[1]);
                }else{
                    // profit = sell curr + buy next, sell next
                    profit = max(prices[i] + next_state[1], next_state[0]);
                }
                // Assign profit in the temp var
                curr[buy] = profit;
            }
            // store the temp as next state for coming iteration
            next_state = curr;
        }

    // Return the last state
    return next_state[1];
    }
};


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
//         dp[n][0] = dp[n][1] = 0; 

//         for(int i = n-1; i>=0; i--){
//             for(int buy=0; buy<=1; buy++){
//                 int profit = 0;
//                 if(buy){
//                     // buying curr + sold prev, didn't buy curr + bought the prev
//                     profit = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);
//                 }else{
//                     // selling curr + bought prev, didn't sell curr + sold the prev
//                     profit = max(prices[i] + dp[i+1][1], 0 + dp[i+1][0]);
//                 }
//                 // Assign the profit to the current dp state
//                 dp[i][buy] = profit;
//             }
//         }
//         // return the last dpp state
//         return dp[0][1];
//     }
// };