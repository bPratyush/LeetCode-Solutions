class disjointset {
public:
    vector<int> rank, parent;
    disjointset(int V) {
        rank.resize(V + 1, 0);
        parent.resize(V + 1, 0);
        for (int i = 0; i <= V; i++) parent[i] = i;
        for (int i = 0; i <= V; i++) rank[i] = 1;
    }
    int findparent(int u) {
        if (u == parent[u]) return u;
        return parent[u] = findparent(parent[u]); //parent[u]=.. for Path Compression
    }
    void unionbyRank(int u, int v) {
        int ulp = findparent(u);
        int ulv = findparent(v);
        if (ulp == ulv) return;
        if (rank[ulp] < rank[ulv]) parent[ulp] = ulv;
        else if (rank[ulv] < rank[ulp]) parent[ulv] = ulp;
        else {
            parent[ulp] = ulv;
            rank[ulv]++;
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        disjointset ds(V);
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j])
                    ds.unionbyRank(i, j);
            }
        }
        int cnt = 0;
        for (int i = 0; i < V; i++) {
            if (ds.findparent(i) == i) cnt++;
        }
        return cnt;
    }
};

