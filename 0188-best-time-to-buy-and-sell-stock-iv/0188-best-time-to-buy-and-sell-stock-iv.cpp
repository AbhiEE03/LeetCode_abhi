class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // Since the max transactions allowed is k so we need to initialise by k+1
        vector<vector<int>>next_state(2, vector<int>(k+1, 0));
        vector<vector<int>>curr_state(2, vector<int>(k+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
                // Cap = k
                for(int cap = 1; cap <= k; cap++){
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

        return next_state[1][k];
    }
};