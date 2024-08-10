class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        for (int i = 0; i <= k; ++i) {
            vector<int> tempDist = dist;
            for (auto e : flights) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] == INT_MAX) continue;
                tempDist[v] = min(tempDist[v], dist[u] + w);
            }
            dist = tempDist;
        }
        if (dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};