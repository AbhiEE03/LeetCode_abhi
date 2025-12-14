class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size(); //Size of the first []

        queue<pair<pair<int,int>, int>> q;

        int visited[n][m]; //Visited Array
        int countFresh=0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                    visited[i][j] = 2; // Mark 2 for all rotten oranges
                }else{
                    visited[i][j] = 0; // Mark 0 for all others 
                }

                // Keep a count of number of fresh oranges
                if(grid[i][j] == 1)countFresh++;
            }
        }

        int tm=0; // Curent time
        // To iterate over all the adjacent blocks
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        int count=0; //Current Count

        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            tm = max(tm,t);
            q.pop();
            
            // Iterating over 4 adjacent blocks
            for(int i=0; i<4; i++){
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && visited[nrow][ncol]==0 && grid[nrow][ncol]==1 ){
                    q.push({{nrow, ncol}, t+1});
                    visited[nrow][ncol]=2;
                    count++;
                }
            }
        }
        if(countFresh != count) return -1;
        return tm;
    }
};