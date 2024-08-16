class DSU{
public:
    vector<int>parent,rank;
    DSU(int n){
        parent.resize(n);
        rank.resize(n,1);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findparent(int u){
        if(u==parent[u]) return u;
        return parent[u]=findparent(parent[u]);
    }
    void unite(int u,int v){
        int ulp=findparent(u);
        int ulv=findparent(v);
        if(rank[ulp]<rank[ulv]) parent[ulp]=ulv;
        else if(rank[ulv]<rank[ulp]) parent[ulv]=ulp;
        else{
            parent[ulp]=ulv;
            rank[ulv]++;
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                edges.push_back({dist,{i,j}});
            }
        }
        int cost=0;
        DSU dsu(n);
        sort(edges.begin(),edges.end());
        for(auto it:edges){
            int dist=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(dsu.findparent(u)!=dsu.findparent(v)){
                cost+=dist;
                dsu.unite(u,v);
            }
        }
        return cost;
    }
};