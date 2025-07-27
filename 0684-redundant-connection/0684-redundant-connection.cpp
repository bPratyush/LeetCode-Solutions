class DSU{
    public:
    vector<int>par,rank;
    DSU(int n){
        rank.resize(n+1,1);
        par.resize(n+1,0);
        for(int i=0;i<=n;i++) par[i]=i;
    }
    int findpar(int u){
        if(u==par[u]) return u;
        return par[u]=findpar(par[u]);
    }
    void unite(int u,int v){
        int ulp=par[u];
        int ulv=par[v];
        if(ulp==ulv) return;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DSU ds(n);
        vector<vector<int>>res;
        for(auto it:edges){
            if(ds.findpar(it[0])==ds.findpar(it[1])) res.push_back(it);
            ds.unite(it[0],it[1]);
        }
        return res.back();
    }
};