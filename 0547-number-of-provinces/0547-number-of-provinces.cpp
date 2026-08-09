
/*
// //// Using BFS //// //
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
*/

// //// Using Disjoint Set //// //
class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        // Initially the rank of each node is 0 as they are at the same level
        rank.resize(n + 1, 0);
        // the parent of each node is itself.
        parent.resize(n + 1);
        size.resize(n+1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    // Finds the ultimate parent of a node
    int findUPar(int node) {
        // Base case: if the node is its own parent, return the node
        if (node == parent[node]) {
            return node;
        }
        // path compression
        return parent[node] = findUPar(parent[node]);
    }

    // Union by rank
    void unionByRank(int u, int v) {
        // Find the ultimate parents of u and v
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // If they are already in the same set, do nothing
        if (ulp_u == ulp_v)
            return;
        // Union by rank: attach the smaller tree under the larger tree
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        } else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        } else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    // Union by size
    void unionBySize(int u, int v) {
        // Find the ultimate parents of u and v
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // If they are already in the same set, do nothing
        if (ulp_u == ulp_v)
            return;
        // Union by size: attach the smaller tree under the larger tree
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet dsu(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    dsu.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i <n; i++) {
            if (dsu.parent[i] == i)
                cnt++;
        }
        return cnt;
    }
};
