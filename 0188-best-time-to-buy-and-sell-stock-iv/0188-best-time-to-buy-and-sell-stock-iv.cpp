class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        vector<vector<int>>next_state(2, vector<int>(k+1, 0));
        vector<vector<int>>curr_state(2, vector<int>(k+1, 0));

        for(int i = n-1; i >= 0; i--){
            for(int buy = 0; buy <= 1; buy++){
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