
// //// USING BFS //// //

// We just need to see if the topological ordering is possible or not 
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Creating an anjacency matrix
        vector<int> adj[numCourses];
        for(auto &it : prerequisites){
            int c = it[0];
            int p = it[1];
            adj[p].push_back(c);
            // adj[it.first].push_back(it.second);
        }

        // Creating indegree vector
        vector<int> indegree(numCourses,0);
        for(int i=0; i<numCourses; i++){
            for(auto &it:adj[i])
                indegree[it]++;
        }

        // Storing the nodes having indegree==0 in the queue
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i]==0)
                q.push(i);
        }

        int count=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;

            for(auto &it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }   
        }

        if(count==numCourses) return true;
        return false;

    }
};


// //// USING DFS //// //
// class Solution {
// // vector<vector<int>> &adj
// private:
//     bool dfs_prerequisite(int course,vector<int> adj[] , vector<int> &visited, vector<int> &path_visited){
//         visited[course] = 1;
//         path_visited[course] = 1;

//         for(auto &it : adj[course]){
//             if(!visited[it]){
//                 if(dfs_prerequisite(it, adj, visited, path_visited)) return true;
//             }else if(path_visited[it] == 1) return true;
//         }

//         path_visited[course] = 0; 
//         return false;
//     }

// public:
//     bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
//         vector<int> visited(numCourses, 0);
//         vector<int> path_visited (numCourses, 0);

//         // Creating an adjacency list
//         vector<int> adj[numCourses]; //For CP but not standard C++ but good for memory
//         // vector<vector<int>> adj(numCourses);
//         for(auto &it:prerequisites){
//             int c = it[0];
//             int p = it[1];

//             adj[p].push_back(c);
//         }

//         for(int i=0; i<numCourses; i++){
//             if (!visited[i]){
//                 if(dfs_prerequisite(i, adj, visited, path_visited)) return false;
//             } 
//         }
//         return true;           
//     }
// };