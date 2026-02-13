class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int sum = 0, n = nums.size();
        for(int i=0; i<n; i++)
            sum += nums[i];

        if(abs(target) > sum || (target + sum)%2 !=0 )
            return 0;

        int S1 = (target + sum)/2;

        vector<vector<int>> dp(n+1, vector<int>(S1+1, 0));

        // Base Case
        dp[0][0] = 1;

        for(int i=1; i<n+1; i++){
            for(int j=0; j<S1+1; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else 
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][S1];
    }
};