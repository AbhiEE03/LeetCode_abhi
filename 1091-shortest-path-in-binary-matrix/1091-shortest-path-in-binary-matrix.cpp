class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // int m = grid.size();
        int n = grid[0].size();

        // store dist, {r, c}
        queue<pair<int, pair<int, int>>> q;
        // store dist of each cell from the source
        vector<vector<int>> dist(n, vector<int>(n, 1e9));

        if (grid[0][0] == 0) {
            dist[0][0] = 1;
            q.push({1, {0, 0}});
        }else
            return -1;

        while (!q.empty()) {
            int d = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            q.pop();

            int dRow[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
            int dCol[8] = {0, 1, 1, 1, 0, -1, -1, -1};
            for (int i = 0; i < 8; i++) {

                int cRow = r + dRow[i];
                int cCol = c + dCol[i];
                if (cRow >= 0 && cRow < n && cCol >= 0 && cCol < n &&
                    grid[cRow][cCol] == 0 && dist[cRow][cCol] > d + 1) {
                    dist[cRow][cCol] = d + 1;
                    q.push({d + 1, {cRow, cCol}});
                }
            }
        }
        if (dist[n - 1][n - 1] == 1e9)
            return -1;
        else
            return dist[n - 1][n - 1];
    }
};