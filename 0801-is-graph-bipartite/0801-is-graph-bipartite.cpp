class Solution {
public:
    bool isBipartite(vector<vector<int>>& G) {
        int n=G.size();
        vector<int> vis(G.size(),0);
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!vis[i]) q.push(i);
            vis[i]=1;
            while(!q.empty()){
                int u=q.front();
                q.pop();
                for(int neigh:G[u]){
                    if(vis[neigh]){
                        if(vis[neigh]==vis[u]) return false;
                    }
                    else{
                        vis[neigh]=-vis[u];
                        q.push(neigh);
                    }
                }
            }
        }
        return true;
    }
};