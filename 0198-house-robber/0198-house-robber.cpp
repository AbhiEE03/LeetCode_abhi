class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);

        // If there is only 1 house then return the value it has
        if(n==1) return nums[0];
        // Base case
        dp[0] = nums[0]; // 1 house means 1 option
        dp[1] = max(nums[0], nums[1]); // 2 house means u have to choose the max among them

        for(int i=2; i<n; i++){
            // For the rest house, you can either rob it or skip
            // If robbed: money = nums[i] + the money u had when u robbed (i-2)th house
            // If not robbed then u must have robbed the previous house
            dp[i] =  max(dp[i-2] + nums[i], dp[i-1]);
        }
        return dp[n-1];
    }
};