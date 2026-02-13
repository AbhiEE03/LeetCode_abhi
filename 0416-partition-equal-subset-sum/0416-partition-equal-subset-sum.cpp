class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // S1 - S2 == 0 is possible only when S1==S2
        // This means We need to look for the subset having sum = total_sum/2
        // It's possible only when the total_sum is even, return false if odd

        int n = nums.size(), sum=0;
        // Finding the total element sum
        for(int i=0; i<n; i++){
            sum += nums[i];
        }

        if(sum % 2 != 0) return false;

        int S1 = sum/2;
        vector<vector<bool>> dp(n + 1, vector<bool>(S1 + 1, false));

        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for(int i=1; i<n+1; i++){
            for( int j=1; j<S1+1; j++){

                if(nums[i-1]<=j)
                    dp[i][j] = (dp[i-1][j-nums[i-1]] || dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][S1];
    }
};