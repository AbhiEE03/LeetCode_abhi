// // //// QUESTION //// //
// Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. Find the order of characters in the alien language.

// There may be multiple valid orders for a particular test case, thus you may return any valid order as a string. The output will be True if the order returned by the function is correct, else False denoting an incorrect order. If the given arrangement of words is inconsistent with any possible letter ordering, return an empty string "".

// Example 1

// Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]

// Output: b d a c

// Explanation:

// We will analyze every consecutive pair to find out the order of the characters.

// The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.

// The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.

// The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.

// The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.

// So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.

// Example 2

// Input: N = 3, K = 3, dict = ["caa","aaa","aab"]

// Output: c a b

// Explanation: Similarly, if we analyze the consecutive pair

// for this example, we will figure out [‘c’, ‘a’, ‘b’] is

// a valid ordering.

//  CODE //
#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
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

public:
  string findOrder(string dict[], int N, int K)
  {
    vector<int> adj[K];

    for (int i = 0; i < N - 1; i++)
    {
      string s1 = dict[i];
      string s2 = dict[i + 1];
      int len = min(s1.size(), s2.size());
      for (int ptr = 0; ptr < len; ptr++)
      {
        if (s1[ptr] != s2[ptr])
        {
          adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
          break;
        }
      }
    }

    vector<int> topological_order = topoSort(K, adj);
    string ans = "";
    for (auto &it : topological_order)
    {
      ans = ans + char(it + 'a');
    }
    return ans;
  }
};
