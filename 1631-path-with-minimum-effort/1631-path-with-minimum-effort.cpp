class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        // store {diff, {r, c}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;

        // store the min effort
        vector<vector<int>> diff(m, vector<int>(n, 1e9));

        // source to source takes '0'
        diff[0][0] = 0;
        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // if u have reached the last cell(destination) with some effort
            // then it's impossible to reach with something lesser as the pq
            // will give something bigger next time (Do Dry Run for better
            // understanding)
            if (r == m - 1 && c == n - 1)
                return diff[m - 1][n - 1];

            // To traverse in 4 directions
            int dRow[4] = {-1, 0, 1, 0};
            int dCol[4] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int cRow = r + dRow[i];
                int cCol = c + dCol[i];

                // until u r within the boundary
                if (cRow >= 0 && cRow < m && cCol >= 0 && cCol < n) {

                    // Take the max of diffs always
                    int newDiff =
                        max(abs(heights[r][c] - heights[cRow][cCol]), d);

                    // If previously taken effort is greater than current then
                    // update and push
                    if (newDiff < diff[cRow][cCol]) {
                        diff[cRow][cCol] = newDiff;
                        pq.push({newDiff, {cRow, cCol}});
                    }
                }
            }
        }
        return 0;
    }
};