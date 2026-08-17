// similar to LCS just take max each time and store zero as u encounter a diff element
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
		
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
		int res = 0;
		for (int i = 1; i < n + 1; i++) {
			for (int j = 1; j < m + 1; j++) {
				if (nums2[i - 1] == nums1[j - 1]){
					dp[i][j] = 1 + dp[i - 1][j - 1];
				    res = max(res, dp[i][j]);
				}
				else
					dp[i][j] = 0;
			}
		}
		return res;
    }
};