/*
 -Keep track of shortest distances of each node from others in a distance array
and keep pushing dist, node in pq everytime u hit a node for the first time or
reach a node in lesser time than previous

 -There is a catch in counting if u keep counting the node leading to final node
as '1' then u will miss the other paths that might be leadinf to that node.
 - So, update the ways as the number of ways that can lead to the previous node
+ current

 - Apply dijkstra with PQ and maintain a distance vector initialised to 1e9 and
ways vector initialised with 0
*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        using ll = long long;
        // Adjacency List
        vector<vector<pair<ll, ll>>> adj(n);

        for (auto &it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Store {dist, node}
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>,
                       greater<pair<ll, ll>>> pq;

        vector<ll> dist(n, 1e18), ways(n, 0);
        // dist of src-src is '0'
        dist[0] = 0;
        // 1 way to reach src
        ways[0] = 1;
        pq.push({0, 0});
        int mod = 1e9+7;

        while(!pq.empty()){
            // Improves readability
            auto it = pq.top();
            ll d = it.first;
            ll node = it.second;
            pq.pop();

            for(auto &it: adj[node]){
                ll adjNode = it.first;
                ll edgeWeight = it.second;

                // If u get any lesser dist then update the dist array, push it in the pq
                // The ways will be assigned the ways to reach the prev node
                // If u get the same dist again then add the ways to reach prev node and curr ways
                if(d + edgeWeight < dist[adjNode]){
                    dist[adjNode] = d + edgeWeight;
                    pq.push({d + edgeWeight, adjNode});
                    ways[adjNode] = ways[node];

                }else if(d + edgeWeight == dist[adjNode]){
                    ways[adjNode] =(ways[adjNode] + ways[node]) % mod;
                }
            }
        }  
        return ways[n-1];         
    }
};