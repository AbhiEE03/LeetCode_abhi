// Floyd's Tortoise and Hare (Cycle Detection) algorithm
class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int fast = nums[0], slow = nums[0];

        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        fast = nums[0];

        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};


// // //// Hashing //// //

// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         unordered_map<int, int> mpp;
//         int ans = 0;
//         for(int i = 0; i < nums.size(); i++){
//             if(mpp[nums[i]] == 0)
//                 mpp[nums[i]]++;
//             else
//                 ans = nums[i];
//         }
//         return ans;
//     }
// };


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