class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<vector<int>> adj(n,vector<int>(n,0));
        vector<int> indeg(n,0);
        for(auto it:preq) adj[it[0]][it[1]]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(adj[i][j]==1) indeg[j]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(!indeg[i]) q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            cnt++;
            for(int i=0;i<n;i++){
                if(adj[u][i]==1){
                    indeg[i]--;
                    if(!indeg[i]) q.push(i);
                }
            }
        }
        return cnt==n;
    }
};