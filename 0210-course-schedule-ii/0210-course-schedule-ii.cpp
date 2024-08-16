class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
    vector<vector<int>> adj(n,vector<int>(n, 0));
    vector<int> indeg(n, 0);
        for (auto it : preq) {
            int u = it[1], v = it[0];
            if (adj[u][v] == 0) {  // Ensure we don't count the same edge twice
                adj[u][v] = 1;
                indeg[v]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) q.push(i);
        }
        vector<int> res;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            res.push_back(u);
            for (int v = 0; v < n; ++v) {
                if (adj[u][v] == 1) {
                    indeg[v]--;
                    if (indeg[v] == 0) q.push(v);
                }
            }
        }
        if (res.size() != n) return {};
        return res;
    }
};