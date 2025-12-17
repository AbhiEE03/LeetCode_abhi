class Solution {

private:
    bool dfs_topological(int course, vector<int> adj[], vector<int> &visited, vector<int> &path_visited, vector<int> &topological_order){
        visited[course] = 1;
        path_visited[course] = 1;

        for(auto &it : adj[course]){
            if(!visited[it]){
                if(dfs_topological(it, adj, visited, path_visited, topological_order)) return true;
            }else if(path_visited[it] == 1) return true;
        }

        topological_order.push_back(course);

        // Reset the visited path as we are returning
        path_visited[course] = 0;
        return false;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited (numCourses, 0);
        vector<int> path_visited(numCourses, 0);
        vector<int>topological_order;

        // Creating an adjacency List
        vector<int> adj[numCourses];

        for(auto &it : prerequisites){
            int c = it[0];
            int p = it[1];

            adj[p].push_back(c);
        }

        // For all the vertices so that we don't miss the componenets which are not connected
        for(int i=0; i<numCourses; i++){
            if(!visited[i]){
                if(dfs_topological(i, adj, visited, path_visited, topological_order)) return {};
            }
        }

        reverse(topological_order.begin(), topological_order.end());
        return topological_order;
    }
};