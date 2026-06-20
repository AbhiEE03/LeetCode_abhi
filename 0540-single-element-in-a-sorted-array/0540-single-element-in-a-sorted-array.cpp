class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n= nums.size();
        if(n==1) return nums[0];
        // Reducing the search space
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];


        int l=1,r=n-2;
        while(l<=r){
            int mid=l+(r-l)/2;

            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]) return nums[mid];

            // The single element will always be at even index
            if((mid%2==0 && nums[mid]==nums[mid-1]) || (mid%2!=0 && nums[mid]==nums[mid+1]))
                r=mid-1;
            else
                l=mid+1;
        }
    return -1;

    }
};


// class Solution {
// public:
//     int singleNonDuplicate(vector<int>& nums) {
//         // int ans=0;
//         // for(int i=0;i<nums.size();i++){
//         //     ans^=nums[i];
//         // }
//     return ans;

//     }
// };