// // A graph is bipartite if there is no cycle
// // A graph with the cycle containing even number of elements is also bipartite but if the
// // number of elements in the cycle is odd, it's not bipartite

// // Using BFS //
// class Solution
// {

// private:
//   bool check(int start, int n, vector<vector<int>> &graph, vector<int> &color)
//   {
//     queue<int> q;
//     q.push(start);
//     color[start] = 0;

//     while (!q.empty())
//     {
//       int node = q.front();
//       q.pop();

//       for (auto &it : graph[node])
//       {
//         // if the graph is not yet colored,then
//         // color it with the opposite color as of adjacent node

//         if (color[it] == -1)
//         {
//           (color[it] = !color[node]);
//           q.push(it);
//         }
//         else if (color[it] == color[node])
//           return false;
//       }
//     }   
//     return true;
//   }

// public:
//   bool isBipartite(vector<vector<int>> &graph)
//   {
//     int n = graph.size();
//     vector<int> color(n, -1);

//     for (int i = 0; i < n; i++)
//     {
//       if (color[i] == -1)
//       {
//         if (check(i, n, graph, color) == false)
//           return false;
//       }
//     }
//     return true;
//   }
// };

// Using DFS //
class Solution{
private:
    bool dfs(int start, int col, vector<vector<int>> &graph, vector<int> &color){
        color[start] = col;
        for(auto &it : graph[start]){
            if(color[it] == -1){
                if(dfs(it, !col, graph, color) == false) return false;
            }else if(color[it] == col) 
                return false;
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>> &graph){
        int n = graph.size();
        vector<int> color(n, -1);

        for(int i=0; i<n; i++){
            if(color[i] == -1){
                if(dfs(i, 0, graph, color) == false) return false;
            }
        }
        return true;

    }

};