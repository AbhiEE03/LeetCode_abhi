class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefixProd(n);
        vector<int> suffixProd(n);
        vector<int> ans(n);

        int curr = 1;

        for (int i = 0; i < n; i++) {
            curr *= nums[i];
            prefixProd[i] = curr;
        }

        curr = 1;
        for (int i = n - 1; i >= 0; i--) {
            curr *= nums[i];
            suffixProd[i] = curr;
        }

        for (int i = 0; i < n; i++) {
            if (i == 0)
                ans[i] = suffixProd[i + 1];
            else if (i == n - 1)
                ans[i] = prefixProd[i - 1];
            else
                ans[i] = (prefixProd[i - 1] * suffixProd[i + 1]);
        }

        return ans;
    }
};