class Solution {
public:
    bool bfs(int x,int y,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        queue<pair<int,int>>q;
        q.push({x,y});
        vis[x][y]=true;
        bool isclose=true;
        vector<pair<int,int>>dr={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            x=q.front().first;
            y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=x+dr[i].first;
                int nc=y+dr[i].second;
                if(nr<0||nr>=grid.size()||nc<0||nc>=grid[0].size()) isclose=false;
                else if(grid[nr][nc]==0 && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc]=true;
                }
            }
        }
        return isclose;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !vis[i][j] &&bfs(i,j,grid,vis)) cnt++;
            }
        }
        return cnt;
    }
};