// Revision via SDESheetChallenge

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int minBuyingPrice = prices[0];

        for(int i = 1; i < prices.size(); i++){
            int currProfit = prices[i] - minBuyingPrice;
            profit = max(currProfit, profit);

            minBuyingPrice = min(minBuyingPrice, prices[i]);
        }
        return profit;
    }
};


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int mini = prices[0]; 
//         int n = prices.size();

//         int profit = 0;
//         for(int i=1; i<n; i++){
//             // Profit after selling the stock on ith day
//             int curr_val = prices[i] - mini;
//             // Track the max profit
//             profit = max(profit, curr_val);
//             // Keep track of the min value where u can buy the stock
//             mini = min(mini, prices[i]);
//         }

//         return profit;
//     }
// };