// Shortest path in DAG

// Given a Directed Acyclic Graph of N vertices from 0 to N-1 and M edges and
// a 2D Integer array edges, where there is a directed edge from
// vertex edge[i][0] to vertex edge[i][1] with a distance of edge[i][2] for all i.

// Find the shortest path from source vertex to all the vertices and
//  if it is impossible to reach any vertex, then return -1 for that vertex.
//  The source vertex is assumed to be 0.

// Example 1
// Input: N = 4, M = 2 edge = [[0,1,2],[0,2,1]]
// Output: 0 2 1 -1

// Explanation:
// Shortest path from 0 to 1 is 0->1 with edge weight 2.
// Shortest path from 0 to 2 is 0->2 with edge weight 1.
// There is no way we can reach 3, so it's -1 for 3.

// Example 2
// Input: N = 6, M = 7 edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
// Output: 0 2 3 6 1 5

// Explanation:
// Shortest path from 0 to 1 is 0->1 with edge weight 2.
// Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
// Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
// Shortest path from 0 to 4 is 0->4 with edge weight 1.
// Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.

// Now your turn!

// Input: N = 3, M = 3 edge = [[0, 1, 4], [0, 2, 2], [1, 2, 5]]
// Output:

// Pick your answer
// 4 4 2

// 0 4 4

// 0 2 2

// 0 4 2
// Constraints

// 1 ≤ N,M ≤ 5*104
// 0 ≤ edge[i][0],edge[i][1] < N-1
// 1 ≤ edge[i][2] < 104

#include <bits/stdc++.h>
using namespace std;
class Solution
{

private:
  // Pass everything by reference to avoid overusing memory
  void dfsTopo(int node, vector<vector<pair<int, int>>> &adj,
               vector<int> &visited, stack<int> &st)
  {
    visited[node] = 1;

    for (auto &it : adj[node])
    {
      int n = it.first;
      if (!visited[n])
        dfsTopo(n, adj, visited, st);
    }

    st.push(node);
  }

public:
  vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
  {

    // Create the adjacency list
    vector<vector<pair<int, int>>> adj(N); // IMP
    // we traverse the edges
    for (int i = 0; i < M; i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      int w = edges[i][2];
      adj[u].push_back({v, w});
    }

    // TC: O(N+M) V+E
    vector<int> visited(N, 0);
    stack<int> st;
    // For components that aren't connected
    for (int i = 0; i < N; i++)
    {
      if (!visited[i])
        dfsTopo(i, adj, visited, st);
    }

    // Fill the distance array with 1e9 then compare
    vector<int> dist(N, 1e9);
    // source to source distance is 0
    dist[0] = 0;
    // TC: O(N+M) V+E
    while (!st.empty())
    {
      int node = st.top();
      st.pop();

      for (auto &it : adj[node])
      {
        int n = it.first;
        int wt = it.second;
        if (dist[node] + wt < dist[n])
          dist[n] = dist[node] + wt;
      }
    }

    for (int i = 0; i < N; i++)
    {
      if (dist[i] == (int)1e9)
        dist[i] = -1;
    }
    return dist;
  }
};
