class disjointset{
public:
    vector<int> parent,rank;
    disjointset(int V){
        parent.resize(V+1,0);
        rank.resize(V+1,0);
        for(int i=0;i<=V;i++){
            parent[i]=i;
            rank[i]=1;
        } 
    }
    int findparent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findparent(parent[u]);
    }
    void unionbyrank(int u,int v){
        int ulp=findparent(u);
        int ulv=findparent(v);
        if(rank[ulp]<rank[ulv]) parent[ulp]=ulv;
        else if(rank[ulv]<rank[ulp]) parent[ulv]=ulp;
        else{
            parent[ulv]=ulp;
            rank[ulp]++;
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& arr) {
       int cntextra=0;
       disjointset ds(n);
       for(auto it:arr){
        int u=it[0];
        int v=it[1];
        if(ds.findparent(u)==ds.findparent(v)) cntextra++;
        else ds.unionbyrank(u,v);
       }
       int cntC=0; //Number of Connected Components
       for(int i=0;i<n;i++){
        if(ds.findparent(i)==i) cntC++;
       }
        int ans=cntC-1;
        if(cntextra>=ans) return ans;
        return -1;
    }
};
