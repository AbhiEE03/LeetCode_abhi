class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN, currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];

            sum = max(sum, currSum);

            if (currSum < 0)
                currSum = 0;
        }
        return sum;
    }
};