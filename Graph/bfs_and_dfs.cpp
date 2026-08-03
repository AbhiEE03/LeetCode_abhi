#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
  void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &dfs_elements)
  {
    vis[node] = 1;
    dfs_elements.push_back(node);

    for (auto it : adj[node])
    {
      if (!vis[it])
      {
        dfs(it, adj, vis, dfs_elements);
      }
    }
  }

public:
  vector<int> dfsOfGraph(int V, vector<int> adj[])
  {
    vector<int> vis(V, 0);
    vector<int> dfs_elements;
    dfs(0, adj, vis, dfs_elements);
    return dfs_elements;
  }

  vector<int> bfsOfGraph(int V, vector<int> adj[])
  {
    vector<int> vis(V, 0);
    queue<int> q;
    vector<int> bfs;

    vis[0] = 1;
    q.push(0);

    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      bfs.push_back(node);

      for (auto it : adj[node])
      {
        if (!vis[it])
        {
          vis[it] = 1;
          q.push(it);
        }
      }
    }
    return bfs;
  }
};
