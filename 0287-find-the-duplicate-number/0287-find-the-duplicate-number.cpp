class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mpp;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            if(mpp[nums[i]] == 0)
                mpp[nums[i]]++;
            else
                ans = nums[i];
        }
        return ans;
    }
};


// // SORTING //
// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int ans;
//         for(int i=1; i<nums.size(); i++){
//             if(nums[i] == nums[i-1]){
//                 ans = nums[i];
//                 break;
//             }
//         }
//         return ans;
//     }
// };