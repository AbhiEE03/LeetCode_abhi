class Solution {
public:
// //// Revision Infosys //// //
    // You have to divide the arr in 2 subsets such that 
    // S1 - S2 = sum(diff) and S1 + S2 = sum_arr
    // S1 = (target + sum)/2
    // If target + Sum is odd then it's impossible to find S1 so return 0
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(auto &it : nums)
            sum += it;

        if(abs(target) > sum || (target+sum)%2 != 0)
            return 0;

        int n = nums.size();
        int S1 = (target+sum)/2;
        vector<vector<int>> dp(n+1, vector<int>(S1 + 1, 0));

        // You can't make all the 1st col zero cause the element itself can be zero
        // for(int i = 0; i<n+1; i++)
        //     dp[i][0] = 1;

        // Base Case
        dp[0][0] = 1;

        for(int i = 1; i < n+1; i++){
            for(int j = 0; j < S1 + 1; j++){
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][S1];
    }
};

/*
// //// 1ST Attempt //// //
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
*/