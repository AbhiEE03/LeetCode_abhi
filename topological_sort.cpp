#include <bits/stdc++.h>
using namespace std;

// Using Plain DFS //
class Solution
{
private:
  void dfs_topo(int node, vector<int> adj[], vector<int> &visited, vector<int> &topological_order)
  {
    visited[node] = 1;
    // path_visited[node]=1;

    for (auto &it : adj[node])
    {
      if (!visited[it])
      {
        dfs_topo(it, adj, visited, topological_order);
      }
    }

    topological_order.push_back(node);

    // path_visited[node] = 0;
  }

public:
  vector<int> topoSort(int V, vector<int> adj[])
  {
    vector<int> visited(V, 0);
    // vector<int> path_visited(V, 0);
    vector<int> topological_order;

    for (int i = 0; i < V; i++)
    {
      if (!visited[i])
      {
        dfs_topo(i, adj, visited, topological_order);
      }
    }

    reverse(topological_order.begin(), topological_order.end());
    return topological_order;
  }
};

//  Using Path Visited //
// class Solution
// {
// private:
//   bool dfs_topo(int node, vector<int> adj[], vector<int> &visited, vector<int> &path_visited, vector<int> &topological_order)
//   {
//     visited[node] = 1;
//     path_visited[node] = 1;

//     for (auto &it : adj[node])
//     {
//       if (!visited[it])
//       {
//         if (dfs_topo(it, adj, visited, path_visited, topological_order))
//           return true;
//       }
//       else if (path_visited[it] == 1)
//         return true;
//     }

//     topological_order.push_back(node);

//     path_visited[node] = 0;
//     return false;
//   }

// public:
//   vector<int> topoSort(int V, vector<int> adj[])
//   {
//     vector<int> visited(V, 0);
//     vector<int> path_visited(V, 0);
//     vector<int> topological_order;

//     for (int i = 0; i < V; i++)
//     {
//       if (!visited[i])
//       {
//         if (dfs_topo(i, adj, visited, path_visited, topological_order))
//           return {};
//       }
//     }

//     reverse(topological_order.begin(), topological_order.end());
//     return topological_order;
//   }
// };
