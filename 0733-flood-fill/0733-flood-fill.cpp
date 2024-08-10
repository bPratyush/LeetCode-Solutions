class Solution {
public:
    void bfs(int n,int m,vector<vector<int>>&image,vector<vector<int>>&vis,int sr,int sc,int col){
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vector<pair<int,int>> deldir = {{-1,0},{0,1},{0,-1},{1,0}};
        int origcol=image[sr][sc];
        if(col==origcol) return;
        vis[sr][sc]=1;
        image[sr][sc]=col;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+deldir[i].first;
                int nc=c+deldir[i].second;
                if(nr>=0&&nr<n&&nc>=0&&nc<m&&!vis[nr][nc]&&image[nr][nc]==origcol){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                    image[nr][nc]=col;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(), m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
       bfs(n,m,image,vis,sr,sc,color);
       return image;
    }
};