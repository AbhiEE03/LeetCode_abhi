#include <bits/stdc++.h>
using namespace std;

// Using BFS //
class Solution
{

public:
  vector<int> topoSort(int V, vector<int> adj[])
  {
    vector<int> indegree(V, 0);

    // Forming the indegree Vector
    for (int i = 0; i < V; i++)
    {
      for (auto &it : adj[i])
      {
        indegree[it]++;
      }
    }

    // Push the nodes with indegree==0 in the queue
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }

    vector<int> topological_order;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      topological_order.push_back(node);

      // Decrease the indegree of adjacent nodes of node because
      // it has been moved to topological_order vector

      for (auto &it : adj[node])
      {
        indegree[it]--;
        if (indegree[it] == 0)
          q.push(it);
      }
    }

    return topological_order;

    // SC : O(3n) & TC : O(V+E)
  }
};
