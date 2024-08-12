class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long, long long>> adj[n];
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<long long> dist(n, 1e18), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        const long long MOD = (int)(1e9 + 7);
        
        pq.push({0, 0});
        
        while(!pq.empty()) {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            
            if (dis > dist[node]) continue; 
            
            for(auto it : adj[node]) {
                long long adjnode = it.first;
                long long edw = it.second;
                
                if (dis + edw < dist[adjnode]) {
                    dist[adjnode] = dis + edw;
                    pq.push({dist[adjnode], adjnode});
                    ways[adjnode] = ways[node];
                } else if (dis + edw == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }
        return ways[n - 1];
    }
};
