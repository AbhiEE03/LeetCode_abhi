class Solution {

private:
    bool dfs_prerequisite(int course, vector<int> adj[], vector<int> &visited, vector<int> &path_visited){
        visited[course] = 1;
        path_visited[course] = 1;

        for(auto &it : adj[course]){
            if(!visited[it]){
                if(dfs_prerequisite(it, adj, visited, path_visited)) return true;
            }else if(path_visited[it] == 1) return true;
        }

        path_visited[course] = 0; 
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, 0);
        vector<int> path_visited (numCourses, 0);

        // Creating an adjacency list
        vector<int> adj[numCourses];
        for(auto &it:prerequisites){
            int c = it[0];
            int p = it[1];

            adj[p].push_back(c);
        }

        for(int i=0; i<numCourses; i++){
            if (!visited[i]){
                if(dfs_prerequisite(i, adj, visited, path_visited)) return false;
            } 
        }
        return true;           
    }
};