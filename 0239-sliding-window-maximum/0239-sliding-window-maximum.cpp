class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            // Indices <= i-k are out of window so pop them
            if (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            // Smaller elements will never contribute to the answer so keep large ones only
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);

            // This means the window is complete so the front element will be the answer
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};