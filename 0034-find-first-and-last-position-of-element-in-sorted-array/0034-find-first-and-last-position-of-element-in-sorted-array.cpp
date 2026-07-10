class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        // If the nums is empty or don't contain the target then it will return [-1,-1]
        vector<int>ans(2,-1);
        long long l=0,r=nums.size()-1;

        if(nums.size()==0) return ans;

        // First Occurrence
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans[0]=mid;
                r=mid-1;
            }else if(nums[mid]>target) 
                r=mid-1;
            else
                l=mid+1;
        }  


        // Second Occurrence
        l=0,r=nums.size()-1;

        while(l<=r){
            long long mid=l+(r-l)/2;
            if(nums[mid]==target){
                ans[1]=mid;
                l=mid+1;
            }else if(nums[mid]>target) 
                r=mid-1;
            else
                l=mid+1;
        }  
    return ans;
    }
};

/* if(target==nums[mid]){
                if(nums[mid-1]<target){
                    ans[0]=mid;
                    l=mid+1;
                }else if(nums[mid-1]==target){
                    r=mid-1;
                }
                
                
                if(nums[mid+1]>target){
                    ans[1]=mid;
                    r=mid-1;
                }else if(nums[mid+1]==target){
                    l=mid+1;
                }
            }

            // In case target is not equal keep changing the search space
            if(nums[mid]<target){
                l=mid+1;
            }else if(nums[mid]>target){
                r=mid-1;
            }
*/