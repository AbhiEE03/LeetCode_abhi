class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();

        int l=0;

        for(int r=l+1; r<n;r++){
            if(nums[l]==nums[r]){
                continue;
            }else {
                // swap(nums[l+1],nums[r]);
                l++;
                nums[l]=nums[r];
                continue;
            }
        }
        return l+1;
    }
};