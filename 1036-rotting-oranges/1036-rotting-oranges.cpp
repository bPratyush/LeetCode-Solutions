class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(), t=0;
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>>dr={{-1,0},{0,1},{1,0},{0,-1}};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int tm=q.front().second;
            q.pop();
            t=max(t,tm);
            for(int i=0;i<4;i++){
                int nr=r+dr[i][0];
                int nc=c+dr[i][1];
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&vis[nr][nc]!=2&&grid[nr][nc]==1){
                    q.push({{nr,nc},tm+1});
                    vis[nr][nc]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2&&grid[i][j]==1) return -1;
            }
        }
        return t;
    }
};