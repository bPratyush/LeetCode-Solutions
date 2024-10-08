class Solution {
public:
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int row,int col){
        vector<pair<int,int>> del={{-1,0},{0,1},{1,0},{0,-1}};
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nr=row+del[i].first;
            int nc=col+del[i].second;
            if(nr>=0&&nr<grid.size()&&nc>=0&&nc<grid[0].size()&&!vis[nr][nc]&&grid[nr][nc]=='1'){
                    dfs(grid,vis,nr,nc);
                    vis[nr][nc]=1;
                }
        }
    }
    void bfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int row,int col){
        int cnt=0;
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        vector<pair<int,int>> del={{-1,0},{0,1},{1,0},{0,-1}};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+del[i].first;
                int nc=c+del[i].second;
                if(nr>=0&&nr<grid.size()&&nc>=0&&nc<grid[0].size()&&!vis[nr][nc]&&grid[nr][nc]=='1'){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
int n=grid.size(), m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'&&!vis[i][j]){
                    bfs(grid,vis,i,j);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};