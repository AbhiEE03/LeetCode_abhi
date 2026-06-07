class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        // Step 1: Insert all numbers into a hash set
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;

        // Step 2: Iterate through the elements to find sequences
        for (int num : st) {
            // Check if 'num' is the start of a sequence
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int currentStreak = 1;

                // Step 3: Extend the sequence backwards/forwards
                while (st.find(currentNum + 1) != st.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longest = max(longest, currentStreak);
            }
        }

        return longest;
    }
};