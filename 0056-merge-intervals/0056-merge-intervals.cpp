class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // You will sort it so that thw comparison becomes easier 
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++){
            // if the ans is empty or the starting of the intervals element is greater than the ending of last pushed element in ans then push the current element in intervals
            if(ans.empty() || intervals[i][0] > ans.back()[1])
                ans.push_back(intervals[i]);
            // else kepp the ending of ans element as the max of currAnsEnding and currIntervals Ending
            else
                ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
        return ans;

    }
};