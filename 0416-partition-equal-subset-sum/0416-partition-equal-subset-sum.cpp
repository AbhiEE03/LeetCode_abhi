// 2nd Attempt (Infosys)//
class Solution {
private:
    bool subset(vector<int>& nums, int val){
        int n = nums.size();
        vector<vector<bool>> dp(n+1, vector<bool> (val+1, false));

        // If reqSum == 0 then it's always possible
        for(int i =0; i<n+1; i++){
            if(i == 0)
                dp[i][0] = true;
        }

        for(int i = 1; i < n+1; i++){
            for(int j = 1; j < val+1; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = (dp[i-1][j - nums[i-1]] || dp[i-1][j]);
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][val];

    }

public:
    bool canPartition(vector<int>& nums) {

        // It's possible only when the reqSum is even 
        int sum = 0;
        for(auto &it: nums){
            sum += it;
        }
        int reqSum = sum/2;
        if(sum % 2 != 0)
            return false;
        else
            return subset(nums, reqSum);
    }
};                                              

/*
// //// Fist Attempt //// // 
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
        // Better than declaring a fixed matrix
        vector<vector<bool>> dp(n + 1, vector<bool>(S1 + 1, false));

        // 1st col is always TRUE
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        // Subset Sum Problem
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
*/