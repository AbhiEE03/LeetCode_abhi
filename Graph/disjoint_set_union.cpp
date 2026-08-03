#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
  vector<int> rank, parent, size;

public:
  DisjointSet(int n)
  {
    // Initially the rank of each node is 0 as they are at the same level
    rank.resize(n + 1, 0);
    // the parent of each node is itself.
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
      size[i] = 1;
    }
  }

  // Finds the ultimate parent of a node
  int findUPar(int node)
  {
    // Base case: if the node is its own parent, return the node
    if (node == parent[node])
    {
      return node;
    }
    // path compression
    return parent[node] = findUPar(parent[node]);
  }

  // Union by rank
  void unionByRank(int u, int v)
  {
    // Find the ultimate parents of u and v
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    // If they are already in the same set, do nothing
    if (ulp_u == ulp_v)
      return;
    // Union by rank: attach the smaller tree under the larger tree
    if (rank[ulp_u] < rank[ulp_v])
    {
      parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u])
    {
      parent[ulp_v] = ulp_u;
    }
    else
    {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }

  // Union by size
  void unionBySize(int u, int v)
  {
    // Find the ultimate parents of u and v
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    // If they are already in the same set, do nothing
    if (ulp_u == ulp_v)
      return;
    // Union by size: attach the smaller tree under the larger tree
    if (size[ulp_u] < size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_u] += size[ulp_v];
    }
  }
};

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  DisjointSet ds(7);
  ds.unionBySize(1, 2);
  ds.unionBySize(2, 3);
  ds.unionBySize(4, 5);
  ds.unionBySize(6, 7);
  ds.unionBySize(5, 6);

  // Find if 3 and 7 are same or not
  if (ds.findUPar(3) == ds.findUPar(7))
  {
    cout << "Same\n";
  }
  else
  {
    cout << "Not Same\n";
  }

  ds.unionByRank(3, 7);
  // Find if 3 and 7 are same or not
  if (ds.findUPar(3) == ds.findUPar(7))
  {
    cout << "Same\n";
  }
  else
  {
    cout << "Not Same\n";
  }
  return 0;
}
