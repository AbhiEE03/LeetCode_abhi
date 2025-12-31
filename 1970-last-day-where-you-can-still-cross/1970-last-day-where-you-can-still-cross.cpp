// // //// USING BFS //// //
// class Solution {
// public:
//     int ROW, COL;
//     vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

//     bool canCross(int mid, vector<vector<int>>& cells) {
//         vector<vector<int>> grid(ROW, vector<int>(COL, 0));

//         for (int i = 0; i <= mid; i++) {
//             grid[cells[i][0]-1][cells[i][1]-1] = 1;
//         }

//         queue<pair<int,int>> q;
//         vector<vector<int>> vis(ROW, vector<int>(COL, 0));

//         for (int j = 0; j < COL; j++) {
//             if (grid[0][j] == 0) {
//                 q.push({0, j});
//                 vis[0][j] = 1;
//             }
//         }

//         while (!q.empty()) {
//             auto [x, y] = q.front();
//             q.pop();

//             if (x == ROW - 1) return true;

//             for (auto &d : directions) {
//                 int nx = x + d[0], ny = y + d[1];
//                 if (nx >= 0 && nx < ROW && ny >= 0 && ny < COL &&
//                     !vis[nx][ny] && grid[nx][ny] == 0) {
//                     vis[nx][ny] = 1;
//                     q.push({nx, ny});
//                 }
//             }
//         }

//         return false;
//     }

//     int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
//         ROW = row;
//         COL = col;

//         int l = 0, r = cells.size() - 1, ans = 0;
//         while (l <= r) {
//             int mid = l + (r - l) / 2;
//             if (canCross(mid, cells)) {
//                 ans = mid + 1;
//                 l = mid + 1;
//             } else {
//                 r = mid - 1;
//             }
//         }
//         return ans;
//     }
// };

// //// USING DFS//// //
class Solution {
public:
    int ROW, COL;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};

    bool canCross(int mid, vector<vector<int>>& cells) {
        vector<vector<int>> grid(ROW, vector<int>(COL, 0));

        for (int i = 0; i <= mid; i++) {
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        queue<pair<int,int>> q;
        vector<vector<int>> vis(ROW, vector<int>(COL, 0));

        for (int j = 0; j < COL; j++) {
            if (grid[0][j] == 0) {
                q.push({0, j});
                vis[0][j] = 1;
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            if (x == ROW - 1) return true;

            for (auto &d : directions) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && nx < ROW && ny >= 0 && ny < COL &&
                    !vis[nx][ny] && grid[nx][ny] == 0) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        ROW = row;
        COL = col;

        int l = 0, r = cells.size() - 1, ans = 0;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (canCross(mid, cells)) {
                ans = mid + 1;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};
