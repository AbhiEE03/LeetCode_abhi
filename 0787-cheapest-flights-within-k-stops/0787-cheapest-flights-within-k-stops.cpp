/* -- Standard dijkstra won't work because proceeding based on dist will not always give the
      the cheapest flights and sometimes it will even stop us from reaching the destination 
      because of exceeding the number of stops so try storing  "STOPS" first

  -- also if u r storing based on STOPS then pq is unnecessary as the data will be 
     sorted already based on 0,1..,2...,....k

  -- use queue as it will save that extra logV time as well

*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // int m = flights.size();
        // int n = flights[0].size();

        // Create the adjacency list
        vector<vector<pair<int,int>>> adj(n);
        for(auto &it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        // store {stops, {node, dist}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        // Initialise the distances with 1e9 
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost  = it.second.second;

            for(auto &it : adj[node]){
                int currNode = it.first;
                int currCost = it.second;

                // no point of moving forward in the path if u have exceeded the num of stops
                if(stops > k) continue;

                // if u get a cost lesser than the previously stored for that node
                // and u haven't exhausted the stops count
                if(cost + currCost < dist[currNode] && stops <= k){
                    dist[currNode] = cost + currCost;
                    q.push({stops+1, {currNode, currCost + cost}});
                }
            }
        }

        if(dist[dst] == 1e9)
            return -1;
        else
            return dist[dst];
    }
};