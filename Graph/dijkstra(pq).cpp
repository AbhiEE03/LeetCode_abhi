// Dijkstra's algorithm
// Given a weighted, undirected graph of V vertices, numbered from 0 to V-1,
// and an 2D vector/array which represents the edges:

// Each entry in edges[i] is of the form [u, v, weight], where:
// u, v → represents the vertex having undirected edge between them
// weight → the weight of the edge between u and v

// Given a source node S. Find the shortest distance of all the vertex from
// the source vertex S. Return a list of integers denoting shortest distance
// between each node and source vertex S. If a vertex is not reachable from source
// then its distance will be 1e9.

// Example 1
// Input: V = 2, edges = [[0,1,9]] , S=0
// Output: [0, 9]

// Explanation:
// The shortest distance from node 0(source) to node 0 is 0 and the shortest distance from node 0 to node 1 is 9.

// Example 2
// Input: V = 3, edges = [[0, 1, 1], [0, 2, 6], [1, 2, 3]] , S=2
// Output: [4, 3, 0]

// Explanation:

// For node 0, the shortest path is 2->1->0 (distance=4)
// For node 1, the shortest path is 2->1 (distance=3)

// Now your turn!
// Input: V=4, edges = [[0,1,1],[0,3,2],[1,2,4],[2,3,3]] , S=0
// Output:

// Pick your answer

// [1, 5, 2, 0]

// [0, 5, 1, 2]

// [0, 1, 5, 2]

// [0, 1, 1, 5]
// Constraints

// 1 ≤ V ≤ 10000
// 0 ≤ edges[i][j] ≤ 10000
// 1 ≤ edges.size() ≤ [ (V*(V - 1)) / 2 ]
// 0 ≤ S < V

// Dijkstra is good for undirected/directed graph with cycle with positive edge weights
// Use a PQ (min-heap) to store {dist, node}
// Apply Bfs with these and keep storing the smaller distances in dist array and
// {dist, node} in the pq

// TC = O(E log V) where E = number of edges, V = number of vertices
// Derivation is in the notes
// You will get TLE if there are negative edge weights, use Bellman-Ford for that

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  vector<int> dijkstra(int V, vector<vector<int>> edges, int S)
  {

    // Create the adjacency list
    vector<vector<pair<int, int>>> adj(V);
    int E = edges.size();
    for (int i = 0; i < E; i++)
    {
      int u = edges[i][0];
      int v = edges[i][1];
      int w = edges[i][2];

      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

    vector<int> dist(V, 1e9);
    // Source to source is ZERO
    dist[S] = 0;
    // Push {dist, node} for source
    minHeap.push({0, S});

    while (!minHeap.empty())
    {
      // smallest will be on top {dist, node}
      int d = minHeap.top().first;
      int node = minHeap.top().second;
      minHeap.pop();

      // Compare the distance for the adjacent nodes from the current node
      for (auto &it : adj[node])
      {
        // {V, weight}
        int adjNode = it.first;
        int edgeWeight = it.second;

        // If the previously stored distance is greater than the current
        // then assign the current in dist and push the {dist, node} in minHeap
        if (dist[adjNode] > d + edgeWeight)
        {
          dist[adjNode] = d + edgeWeight;
          minHeap.push({dist[adjNode], adjNode});
        }
      }
    }
    return dist;
  }
};