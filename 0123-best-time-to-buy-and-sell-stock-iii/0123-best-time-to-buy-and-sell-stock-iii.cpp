// // //// Dp w/o space optimisation //// //
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         // Initialisation
//         // If (cap==0 || index == n) return 0
//         // Base Case
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

//         for(int i=n-1; i>=0; i--){
//             for(int buy=0; buy<=1; buy++){
//                 for(int cap=1; cap<=2; cap++){
//                     // Capacity decrease only when we sell the stock
//                     if(buy){
//                         dp[i][buy][cap] = max(-prices[i] + dp[i+1][0][cap], 0 + dp[i+1][1][cap]);
//                     }else{
//                         dp[i][buy][cap] = max(prices[i] + dp[i+1][1][cap-1], 0 + dp[i+1][0][cap]);
//                     }
//                 }
//             }
//         }
//         // return the last state where elements=0, buy=1,
//         return dp[0][1][2];
//     }
// };



// //// Dp with space optimisation //// //
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>next_state(2, vector<int>(3, 0));
        vector<vector<int>>curr_state(2, vector<int>(3, 0));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                for(int cap = 1; cap <= 2; cap++){
                    if(buy){
                        curr_state[buy][cap] = max(-prices[i] + next_state[0][cap],
                        next_state[1][cap]);
                    }else{
                        curr_state[buy][cap] = max(prices[i] + next_state[1][cap-1], 
                        next_state[0][cap]);
                    }
                }
            }
            next_state = curr_state;
        }

        return next_state[1][2];
    }
};