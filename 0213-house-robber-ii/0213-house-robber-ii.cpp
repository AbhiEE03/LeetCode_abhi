class Solution {
public:

    int rob_Circle(vector<int>& nums, int start, int end) {
        int prev2 = 0, prev = 0;

        for(int i=start; i<end+1; i++){
            int curr = max((prev2 + nums[i]), (prev));
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];

        return max(rob_Circle(nums, 1, n-1), rob_Circle(nums, 0, n-2));
    }

};

    