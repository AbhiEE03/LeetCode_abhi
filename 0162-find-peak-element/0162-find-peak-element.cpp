class Solution {
public:
    // int findPeakElement(vector<int>& nums) {
    //     long long l=0;
    //     long long ans=-1;
    //     for(long long i=0;i<nums.size();i++){
    //         if(nums[l]>=nums[l-1]||l==0){
    //             ans=nums[l];
    //             l+=1;
    //         }else 
    //             continue;
    //     }

    int findPeakElement(vector<int>& nums) {

        int l=0,r=nums.size()-1;

        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]< nums[mid+1]){
                l=mid+1;
            }else{
                r=mid;
            }
        }    
        return l;
    }
};