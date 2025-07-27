class DSU{
    public:
    vector<int>rank,par;
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
        int ulp=findpar(u);
        int ulv=findpar(v);
        if(ulp==ulv) return;
        if(rank[ulp]<rank[ulv]) par[ulp]=ulv;
        else if(rank[ulv]<rank[ulp]) par[ulv]=ulp;
        else{
            par[ulp]=ulv;
            rank[ulv]++;
        }
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DSU dsu(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]) dsu.unite(i,j);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(dsu.findpar(i)==i) cnt++;
        }
        return cnt;
    }
};