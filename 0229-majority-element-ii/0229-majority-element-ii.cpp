class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        unordered_map<int ,int> mpp;

        // Element is appearing atleast (n/3 + 1) times
        int mn=(n/3)+1;

        for(int i=0;i<n;i++){
           mpp[nums[i]]++;

            // Add it to the ans array as the count reaches (n/3 + 1)
           if(mpp[nums[i]]==mn)
                ans.push_back(nums[i]);

            // We can have atmost 2 elements
            if(ans.size() == 2)
                break;

        }
        return ans;
    }
};



