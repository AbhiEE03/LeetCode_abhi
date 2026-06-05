// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n= nums.size();
//         int ans=0;
//         int freq=0;
//         for(int i=0;i<n;i++){
//             if(freq==0) ans=nums[i];

//             if(ans==nums[i]) freq++;
//             else freq--;

//         }

//         return ans;
        
//     }
// };

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int freq = 1, n = nums.size(), ans = nums[0];
        for(int i = 1; i < n; i++){
            if(nums[i] == nums[i-1])
                freq++;
            else
                freq = 1;
            
            if(freq > (n/2))
                ans = nums[i];
        }

        return ans;
    }
};