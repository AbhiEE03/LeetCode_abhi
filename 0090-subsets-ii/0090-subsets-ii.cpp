class Solution {
private:
    void findSubsets(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans) {
        ans.push_back(ds);
        for(int i = ind; i < nums.size(); i++) {
            if(i != ind && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubsets(i+1, nums, ds, ans);
            ds.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        findSubsets(0, nums, ds, ans);
        return ans;
    }
};


// //// I don't know when did I solve by this method //// //

// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        set<vector<int>> ans;
//         int n= nums.size();
//         int subset=(1<<n);
        
//         for(int num=0; num<subset; num++){
//             vector<int> sub;
//             for(int i=0;i<n;i++){
//                 if(num&(1<<i)) sub.push_back(nums[i]);
//             }
//             sort(sub.begin(), sub.end());
//             ans.insert({sub});

//         }
//         return vector<vector<int>>(ans.begin(), ans.end());
//     }
// };