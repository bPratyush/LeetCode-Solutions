class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> dis(n,vector<int>(m,0));
        vector<pair<int,int>> del={{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int step=q.front().second;
            q.pop();
            dis[r][c]=step;
            for(int i=0;i<4;i++){
                int nrow=r+del[i].first;
                int ncol=c+del[i].second;
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&mat[nrow][ncol]==1&&!vis[nrow][ncol]){
                    q.push({{nrow,ncol},step+1});
                    vis[nrow][ncol]=1;
                }
            }
        }
        return dis; 
    }
};