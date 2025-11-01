class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> repeated;
        sort(nums.begin(), nums.end());
        
        for(int i=1; i<n; i++){
            if(nums[i-1]!=nums[i]) continue;
            else repeated.push_back(nums[i]);
        }
        return repeated;
    }
};