class Solution {
private:
    int n;
    vector<vector<int>> dp;

    int binary_search(vector<vector<int>>& events, int endTime) {
        int l = 0, r = n - 1, result = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (events[mid][0] > endTime) {
                result = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return result;
    }

    int solve(int cnt, int i, vector<vector<int>>& events) {
        if (cnt == 2 || i >= n) return 0;
        if (dp[cnt][i] != -1) return dp[cnt][i];

        int nextValid = binary_search(events, events[i][1]);
        int take = events[i][2] + solve(cnt + 1, nextValid, events);
        int notTake = solve(cnt, i + 1, events);

        return dp[cnt][i] = max(take, notTake);
    }

public:
    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();
        sort(events.begin(), events.end());

        dp.assign(3, vector<int>(n, -1));
        return solve(0, 0, events);
    }
};
