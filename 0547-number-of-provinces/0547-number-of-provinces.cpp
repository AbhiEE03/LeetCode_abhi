
// TC: O(n) + O(n+ 2n) ~ O(n)
// SC: O(n) + O(n)
class Solution {
private:
// Bfs will work as well 
    void dfs(int node, vector<vector<int>> & adjList, vector<int>& visited) {
        visited[node] = 1;
        for (auto it : adjList[node]) {
            if (!visited[it])
                dfs(it, adjList, visited);
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        // Convert the adjacency matrix to adjacency list
        vector<vector<int>> adjList(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                    adjList[j].push_back(i);
                }
            }
        }

        // Now check if they ae connected or not
        vector<int> visited(n, 0);
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, adjList, visited);
            }
        }
        return cnt;
    }
};