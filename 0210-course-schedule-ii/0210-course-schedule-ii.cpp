class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& preq) {
        vector<vector<int>> adj(n,vector<int>(n,0));
        vector<int> indeg(n,0);
        for(auto it:preq) adj[it[0]][it[1]]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1) indeg[j]++;
            }
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!indeg[i]) q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            res.push_back(u);
            for(int v=0;v<n;v++){
                if(adj[u][v]==1){
                    indeg[v]--;
                    if(!indeg[v]) q.push(v);
                }
            }
        }
        if(res.size()==n) {
            reverse(res.begin(),res.end());
            return res;
        }
        return {};
    }
};