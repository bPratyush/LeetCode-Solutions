class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n,INT_MAX);
        dist[k-1]=0;
        for(int i=1;i<n;i++){
            for(auto it:times){
            int u=it[0],v=it[1],w=it[2];
            if(dist[u-1]==INT_MAX) continue;
            dist[v-1]=min(dist[v-1],dist[u-1]+w);
            }
        }
    int maxdel=*max_element(dist.begin(),dist.end());
    return (maxdel==INT_MAX)?-1:maxdel;
    }
};