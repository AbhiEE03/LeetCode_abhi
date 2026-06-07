class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Store the num and its index in map
        unordered_map<int,int> m; 
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            int first=nums[i];
            int sec=target-first; //What else do we need

            // Look for the req num in the num if its there in then just push the indixes else keep repeating the prev steps
            if(m.find(sec)!=m.end()){
                ans.push_back(i);
                ans.push_back(m[sec]);
                return ans;
            }
            m[first]=i;
        }
        return {-1, -1};
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int l = 0, r = nums.size()-1;
//         sort(nums.begin(), nums.end());
//         while(l < r){
//             int sum = nums[l] + nums[r];
//             if(sum == target) return {l, r};
//             else if(sum > target) r--;
//             else l++;
//         }
//         return {l, r};
//     }
// };