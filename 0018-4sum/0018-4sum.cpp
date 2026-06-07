class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            int a=i;

            for(int j=i+1; j<n;j++){
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int b=j,l=j+1,r=n-1;

                while(l<r){
                    long long sum = 1LL * nums[i] + nums[j] + nums[l] + nums[r];

                    if(sum==target){
                        ans.push_back({nums[a],nums[b],nums[l],nums[r]});
                        r--,l++;
                        while(l<r && nums[l]==nums[l-1]) l++;
                        while(r>l && nums[r]==nums[r+1]) r--;
                    }
                    else if (sum < target) {
                        l++;
                    }
                    else {
                        r--;
                    }
                }
            }
        }
        return ans;    
    }
};