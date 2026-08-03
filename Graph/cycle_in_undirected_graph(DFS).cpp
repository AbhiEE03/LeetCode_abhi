#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  bool dfs(int node, int parent, vector<int> adj[], vector<int> &visited)
  {
    visited[node] = 1;

    for (auto &it : adj[node])
    {
      if (!visited[it])
      {
        if (dfs(it, node, adj, visited))
          return true;
      }
      else if (it != parent)
        return true;
    }
    return false;
  }

public:
  bool isCycle(int V, vector<int> adj[])
  {
    vector<int> visited(V, 0);
    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        if (dfs(i, -1, adj, visited))
          return true;
      }
    }
    return false;
  }
};

/* ///QUESTION///
Given an undirected graph with V vertices labeled from 0 to V-1. The graph is represented using an adjacency list where adj[i] lists all nodes connected to node. Determine if the graph contains any cycles.

Note: The graph does not contain any self-edges (edges where a vertex is connected to itself).

Example 1

Input: V = 6, adj= [[1, 3], [0, 2, 4], [1, 5], [0, 4], [1, 3, 5], [2, 4]]

Output: True

Explanation: The graph contains a cycle: 0 ->1 -> 2 -> 5 -> 4 -> 1.

Example 2

Input: V = 4, adj= [[1, 2], [0], [0, 3], [2]]

Output: False

Explanation: The graph does not contain any cycles.

Constraints

E=number of edges
1 ≤ V, E ≤ 104
*/