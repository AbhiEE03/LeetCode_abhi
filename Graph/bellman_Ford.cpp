/*
Bellman ford algorithm

Given a weighted and directed graph of V vertices and E edges.
 An edge is represented as [ai, bi, wi], meaning there is a directed edge
 from ai to bi having weight wi. Find the shortest distance of all the vertices
  from the source vertex S. If a vertex can't be reached from the S
   then mark the distance as 109.


If the graph contains a negative cycle then return -1 in a list.


Example 1
Input : V = 6, Edges = [[3, 2, 6], [5, 3, 1], [0, 1, 5], [1, 5, -3], [1, 2, -2], [3, 4, -2], [2, 4, 3]], S = 0
Output: 0 5 3 3 1 2

Explanation:
For node 1, shortest path is 0->1 (distance=5).
For node 2, shortest path is 0->1->2 (distance=3)
For node 3, shortest path is 0->1->5->3 (distance=3)
For node 4, shortest path is 0->1->5->3->4 (distance=1)
For node 5, shortest path is 0->1->5 (distance=2)

Example 2
Input : V = 2, Edges = [[0,1,9]], S = 0
Output: 0 9

Explanation: For node 1, the shortest path is 0->1 (distance=9)

Now your turn!
Input: V=3, Edges = [[0,1,5],[1,0,3],[1,2,-1],[2,0,1]], S = 2
Output:

Pick your answer
1 6 0
0 6 1
1 5 0
1 1 0
Constraints

1 ≤ V ≤ 500
1 ≤ E ≤ V*(V-1)
-1000 ≤ edges[i][3] ≤ 1000
0 ≤ S < V
*/

// Used to find shortest path in graphs having negative edge weights or
//  to detect Negative Cycle
// Negative Cycle: Cycles having negative path weights
// Used for detecting negative cycles and
// If the distance array gets updated(reduced) after (n-1)th iteration
// then it has -ve cycle
// finding shortest path in graphs having negative edge weights
// N-1 iterations: In worst case, u will take N-1 edges to reach from first to last

// TC: O(V*E) where V = number of vertices, E = number of edges
// SC: O(V) for distance array
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
  {

    // // Create adjacency list
    // vector<vector<pair<int, int>>> adj(V);
    // int E = edges.size();
    // for (int i = 0; i < E; i++)
    // {
    //   for (auto &it : edges)
    //   {
    //     int u = it[0];
    //     int v = it[1];
    //     int w = it[2];
    //     adj[u].push_back({v, w});
    //   }
    // }

    vector<int> dist(V, 1e9);
    dist[S] = 0;

    for (int i = 0; i < V - 1; i++)
    {
      for (auto &it : edges)
      {
        int u = it[0];
        int v = it[1];
        int w = it[2];

        if (dist[u] != 1e9 && dist[u] + w < dist[v])
          dist[v] = dist[u] + w;
      }
    }

    // Nth iteration to check for negative cycle
    for (auto &it : edges)
    {
      int u = it[0];
      int v = it[1];
      int w = it[2];

      if (dist[u] != 1e9 && dist[u] + w < dist[v])
        return {-1};
    }
    return dist;
  }
};
