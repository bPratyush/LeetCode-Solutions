class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        for (int i = 1; i < n; ++i) {
            for (auto e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u - 1] == INT_MAX) continue;
                dist[v - 1] = min(dist[v - 1], dist[u - 1] + w);
            }
        }
        int maxDelay = *max_element(dist.begin(), dist.end());
        return (maxDelay == INT_MAX) ? -1 : maxDelay;
    }
};
