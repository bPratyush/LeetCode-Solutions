class Solution {
void bfs(vector<vector<int>>&image,vector<vector<int>>&vis,int color,int newrow,int newcol){
    int origcolor=image[newrow][newcol];
    if(origcolor==color) return;
    queue<pair<int,int>>q;
    q.push({newrow,newcol});
    vis[newrow][newcol]=1;
    image[newrow][newcol]=color;
    int delrow[]={-1,0,1,0};
    int delcol[]={0,1,0,-1};
    while(!q.empty()){
        auto[r,c]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nrow=r+delrow[i];
            int ncol=c+delcol[i];
            if(nrow>=0&&nrow<image.size()&&ncol>=0&&ncol<image[0].size()&&!vis[nrow][ncol]&&image[nrow][ncol]==origcolor){
                q.push({nrow,ncol});
                vis[nrow][ncol]=1;
                image[nrow][ncol]=color;
            }
        }
    }
}
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       vector<vector<int>>vis(image.size(),vector<int>(image[0].size(),0));
       bfs(image,vis,color,sr,sc);
       return image;
    }
};

