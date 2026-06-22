// // //// QUESTION //// //

// Given an integer M and an undirected graph with N vertices (zero indexed) and E edges. The goal is to determine whether the graph can be coloured with a maximum of M colors so that no two of its adjacent vertices have the same colour applied to them.

// In this context, colouring a graph refers to giving each vertex a different colour. If the colouring of vertices is possible then return true, otherwise return false.

// Example 1

// Input : N = 4 , M = 3 , E = 5 , Edges = [ (0, 1) , (1, 2) , (2, 3) , (3, 0) , (0, 2) ]

// Output : true

// Explanation : Consider the three colors to be red, green, blue.

// We can color the vertex 0 with red, vertex 1 with blue, vertex 2 with green, vertex 3 with blue.

// In this way we can color graph using 3 colors at most.

// Example 2

// Input : N = 3 , M = 2 , E = 3 , Edges = [ (0, 1) , (1, 2) , (0, 2) ]

// Output : false

// Explanation : Consider the two colors to be red, green.

// We can color the vertex 0 with red, vertex 1 with green.

// As the vertex 2 is adjacent to both vertex 1 and 0 , so we cannot color with red and green.

// Hence as we could not color all vertex of graph we return false.

// Input : N = 5 , M = 3 , E = 6 , Edges = [ (0, 1) , (1, 2) , (0, 2) , (2,3) , (2,4) , (3,4) ]

// Output:
// Constraints

// 1 <= N <= 20
// 1 <= E <= (N*(N-1)/2)
// 1 <= M <= N

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  bool isSafe(int node, int col,
              vector<int> &color,
              vector<vector<int>> &adj)
  {

    for (int it : adj[node])
    {
      if (color[it] == col)
        return false;
    }

    return true;
  }

  bool solve(int node, int m, int n,
             vector<int> &color,
             vector<vector<int>> &adj)
  {

    if (node == n)
      return true;

    for (int col = 1; col <= m; col++)
    {

      if (isSafe(node, col, color, adj))
      {

        color[node] = col;

        if (solve(node + 1, m, n, color, adj))
          return true;

        color[node] = 0;
      }
    }

    return false;
  }

  bool graphColoring(vector<vector<int>> &edges, int m, int n)
  {

    vector<vector<int>> adj(n);

    for (auto &e : edges)
    {
      int u = e[0];
      int v = e[1];

      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    vector<int> color(n, 0);

    return solve(0, m, n, color, adj);
  }
};