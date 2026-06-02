class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0,sum=INT_MIN;
        for(auto it:nums){
            currSum+=it;
            sum=max(sum,currSum);

            if(currSum<0) currSum=0;
        }
        return sum;
    }
};