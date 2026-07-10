class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target) return true;

            //All three are same then shrink the search space
            if(nums[l]==nums[mid] && nums[r]==nums[mid]){
                l=l+1;
                r-=1;
                continue;
            }

            //left sorted
            if(nums[l]<=nums[mid]){
                if(nums[l]<=target && nums[mid]>=target)
                    r=mid-1;
                else
                    l=mid+1;
            }else{ //right sorted
                if(nums[r]>=target && nums[mid]<=target)
                    l=mid+1;
                else
                    r=mid-1;
            }
        }
         return false;
    }
};