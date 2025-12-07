class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {

        vector<vector<int>> grid(m, vector<int>(n, 0));

        // Mark walls
        for (auto i : walls) {
            grid[i[0]][i[1]] = 1;
        }

        // Mark guards
        for (auto i : guards) {
            grid[i[0]][i[1]] = 1;
        }

        // Mark guarded cells
        for (auto i : guards) {
            int x, y;

            // left
            x = i[0];
            y = i[1] - 1;
            while (y >= 0 && grid[x][y] != 1) {
                grid[x][y] = 2;
                y--;
            }

            // right
            x = i[0];
            y = i[1] + 1;
            while (y < n && grid[x][y] != 1) {
                grid[x][y] = 2;
                y++;
            }

            // up
            x = i[0] - 1;
            y = i[1];
            while (x >= 0 && grid[x][y] != 1) {
                grid[x][y] = 2;
                x--;
            }

            // down
            x = i[0] + 1;
            y = i[1];
            while (x < m && grid[x][y] != 1) {
                grid[x][y] = 2;
                x++;
            }
        }

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!grid[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};
