class Solution {
    int timer = 0; // Initialize timer to 0
    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[], int low[], vector<vector<int>>& bridges) {
        vis[node] = 1; 
        tin[node] = low[node] = ++timer; // Initialize discovery time and low value for the current node
        for (auto it : adj[node]) {
            if (it == parent) continue; // Skip if the adjacent node is the parent
            if (!vis[it]) { 
                dfs(it, node, vis, adj, tin, low, bridges); 
                low[node] = min(low[node], low[it]); // Update the low value of the current node based on the adjacent node
                if (low[it] > tin[node]) bridges.push_back({it, node}); // Add the edge (node, it) to the list of bridges
            } 
            else low[node] = min(low[node], tin[it]); // Update the low value of the current node based on the discovery time of the adjacent node
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& g) {
        vector<int> adj[n]; 
        for (auto it : g) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        int tin[n]; 
        int low[n];
        vector<vector<int>> bridges;  
        for (int i = 0; i < n; ++i) { 
            if (!vis[i]) dfs(i, -1, vis, adj, tin, low, bridges);
        }
        return bridges; 
    }
};


