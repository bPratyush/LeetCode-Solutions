class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> deg(n,0);
        vector<vector<int>> adj(n);
        for(auto e:edges){
            int v=e[0],w=e[1];
            adj[v].push_back(w);
            adj[w].push_back(v);
            deg[v]++; deg[w]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(deg[i]==1) q.push(i);
        }
        vector<int> ans;
        int lft=n;
        while(!q.empty()){
            int qz=q.size();
            lft-=qz;
            for(int i=0;i<qz;i++){
                int v=q.front();
                q.pop();
                if(lft==0) ans.push_back(v);
                for(int w:adj[v]){
                    if(--deg[w]==1) q.push(w);
                }
            }
        }
        return ans;
    }
};