class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int idx=-1;
        int l=0,r=nums.size()-1;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[l]<=nums[mid]){
                ans=min(nums[l],ans);
                l=mid+1; 
            }else{
                ans=min(nums[mid],ans);
                r=mid-1;
            }
        }
    return ans;
    }
};