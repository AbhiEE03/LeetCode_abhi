#include <bits/stdc++.h>
using namespace std;

// Using BFS/Kahn's algo //
class Solution
{

public:
  bool isCyclic(int N, vector<int> adj[])
  {
    vector<int> indegree(N, 0);

    for (int i = 0; i < N; i++)
    {
      for (auto &it : adj[i])
        indegree[it]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
    {
      if (indegree[i] == 0)
        q.push(i);
    }

    int count = 0;
    while (!q.empty())
    {
      int node = q.front();
      q.pop();
      count++;

      for (auto &it : adj[node])
      {
        indegree[it]--;
        if (indegree[it] == 0)
          q.push(it);
      }
    }

    if (count == N)
      return false;
    return true;
  }
};

// // Using DFS //

// class Solution{

// private:
//     bool dfs_cycle_check(int node, vector<int> adj[], vector<int> &visited, vector<int> &path_visited){
//         visited[node] =1;
//         path_visited[node]=1;

//         for(auto &it : adj[node]){
//             // if the node is unvisited
//             if(!visited[it]){
//                 if(dfs_cycle_check(it, adj, visited, path_visited)) return true;
//             }
//             // If it has been visited and it lies on the same path
//             else if(path_visited[it] == 1) return true;
//         }

//         path_visited[node] = 0;
//         return false;
//     }

// public:
//     bool isCyclic(int N, vector<int> adj[]) {
//         vector<int> visited(N,0);
//         vector<int> path_visited(N,0);

//         for(int i=0; i<N; i++){
//             if(!visited[i]){
//                 if(dfs_cycle_check(i, adj, visited, path_visited)) return true;
//             }
//         }
//         return false;
//     }
// };
