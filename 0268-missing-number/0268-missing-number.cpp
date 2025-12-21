class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum=0;
        int n=nums.size();
        for(auto& it: nums) sum+=it;
        long long actualSum= n*(n+1)/2;
        return actualSum-sum;
    }
};