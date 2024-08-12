class Solution {
public:
    bool isBipartite(vector<vector<int>>& G) {
        vector<int> vis(G.size(),0);
        queue<int>q;
        for(int i=0;i<G.size();i++){
            if(!vis[i]) q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int v=q.front();
                q.pop();
                for(int u:G[v]){
                    if(vis[u]){
                        if(vis[u]!=-vis[v]) return false;
                    }
                    else{
                        vis[u]=-vis[v];
                        q.push(u);
                    }
                }
            }
        }
        return true;
    }
};