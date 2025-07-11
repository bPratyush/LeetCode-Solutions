class Solution {
public:
    void bfs(vector<vector<int>>&image,vector<vector<int>>&vis,int r, int c, int clr){
        queue<pair<int,int>>q;
        q.push({r,c});
        vis[r][c]=1;
        vector<pair<int,int>>dr={{-1,0},{0,1},{1,0},{0,-1}};
        int origclr=image[r][c];
        if(clr==origclr) return;
        vis[r][c]=1;
        image[r][c]=clr;
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nr=r+dr[i].first;
                int nc=c+dr[i].second;
                if(nr>=0&&nr<image.size()&&nc>=0&&nc<image[0].size()&&!vis[nr][nc]&&image[nr][nc]==origclr){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                    image[nr][nc]=clr;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size(), m=image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        bfs(image,vis,sr,sc,color);
        return image;
    }
};