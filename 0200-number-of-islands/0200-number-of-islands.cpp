class DSU{
    public:
    vector<int>par;
    vector<int> rank;
    DSU(int n){
        par.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=1;
        }
    }
    int find(int u){
        if(u==par[u]) return u;
        return par[u]=find(par[u]);
    }
    void unite(int u,int v){
        int ulp=find(u);
        int ulv=find(v);
        if(rank[ulp]<rank[ulv]) par[ulp]=ulv;
        else if(rank[ulv]<rank[ulp]) par[ulv]=ulp;
        else{
            par[ulv]=ulp;
            rank[ulp]++;
        }
    }
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        DSU dsu(n * m);
        auto index = [&](int x, int y) {return x * m + y;};
        vector<pair<int, int>> dir={{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    for (auto [dx, dy] : dir) {
                        int ni = i + dx;
                        int nj = j + dy;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid[ni][nj] == '1') dsu.unite(index(i, j), index(ni, nj));
                    }
                }
            }
        }
        unordered_set<int> distinctIslands;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    distinctIslands.insert(dsu.find(index(i, j)));
                }
            }
        }
        return distinctIslands.size();
    }
};