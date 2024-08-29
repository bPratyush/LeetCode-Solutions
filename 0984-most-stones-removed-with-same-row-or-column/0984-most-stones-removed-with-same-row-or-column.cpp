class disjointset {
public:
    vector<int> parent, rank;
    disjointset(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }
    int findparent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findparent(parent[u]);
    }
    void unionbyrank(int u, int v) {
        int up = findparent(u);
        int vp = findparent(v);
        if (up != vp) {
            if (rank[up] < rank[vp]) parent[up] = vp;
            else if (rank[vp] < rank[up]) parent[vp] = up;
            else {
                parent[vp] = up;
                rank[up]++;
            }
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxrow = 0, maxcol = 0;

        // Find the maximum row and column indices
        for (auto it : stones) {
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }

        // Initialize the disjoint set with size large enough to handle both row and column indices
        disjointset ds(maxrow + maxcol + 1);

        // Map to track unique nodes (both rows and columns)
        unordered_map<int, int> mpp;

        // Union the row and column indices for each stone
        for (auto it : stones) {
            int u = it[0];
            int v = it[1] + maxrow + 1; // Offset column index to avoid overlap with row indices
            ds.unionbyrank(u, v);
            mpp[u] = 1; // Mark the row index
            mpp[v] = 1; // Mark the column index
        }

        int cnt = 0;
        // Count the number of unique root parents
        for (auto it : mpp) {
            if (ds.findparent(it.first) == it.first) cnt++;
        }

        // The number of stones that can be removed is total stones minus the number of unique components
        return n - cnt;
    }
};

