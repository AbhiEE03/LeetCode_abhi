class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int  count = 0, preSum = 0;
        unordered_map<int, int> mpp;
        mpp[0] = 1; // TO ensure that we increase the count when preSum == k

        for(int i = 0; i < nums.size(); i++){
            preSum += nums[i];
            int remove = preSum - k; //Calculate what needs to be subtracted from preSum to get k
            count += mpp[remove];
            mpp[preSum]++;

        }
        return count;
        
    }
};