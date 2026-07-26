class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // create the adjacency list
        vector<vector<pair<int, int>>> adj(n + 1); // 1-based indexing
            for (auto& it : times) {
            adj[it[0]].push_back({it[2], it[1]});
        }

        vector<int> time(n + 1, 1e9); // 1-based indexing
        // src - src takes nothing
        time[k] = 0;


        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            int t = it.first;
            int node = it.second;

            for(auto &it: adj[node]){
                int currTime = it.first;
                int currNode = it.second;

                if(t + currTime < time[currNode]){
                    time[currNode] = t + currTime;
                    pq.push({currTime + t, currNode});
                }
            }
        }


        // return max of all the times u stored as the signals are sent simultaneously
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (time[i] == 1e9)
                return -1;
            maxTime = max(maxTime, time[i]);
        }
        return maxTime;
    }
};