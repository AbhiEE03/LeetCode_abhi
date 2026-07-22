class Solution {

// It's like finding the components not connected so any of bfs or dfs will do the work
private:
    void bfs(int r, int c, vector<vector<int>>& visited,
             vector<vector<char>>& grid) {

        visited[r][c] = 1;

        // store row, col
        queue<pair<int, int>> traverseQueue;
        traverseQueue.push({r, c});

        while (!traverseQueue.empty()) {
            int nrow = traverseQueue.front().first;
            int ncol = traverseQueue.front().second;
            traverseQueue.pop();

            // To traverse in horizontal and vertical direction
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int cRow = nrow + drow[i];
                int cCol = ncol + dcol[i];
                // As long as it's within the boundary && not visited && has '1
                if (cRow >= 0 && cRow < grid.size() && cCol >= 0 && cCol < grid[0].size() &&
                    !visited[cRow][cCol] && grid[cRow][cCol] == '1') {
                    visited[cRow][cCol] = 1;
                    traverseQueue.push({cRow, cCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        // get the rows and cols
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int cnt(0);
        // Loop through the grid
        for(int i = 0 ; i<n; i++){
            for (int j = 0; j < m; j++) {
                // call bfs only if it hasn't been visited and it has '1
                if (!visited[i][j] && grid[i][j] == '1') {
                    bfs(i, j, visited, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
