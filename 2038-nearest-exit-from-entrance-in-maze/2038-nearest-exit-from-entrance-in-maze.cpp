class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size(),m=maze[0].size();
        vector<pair<int,int>>dr={{-1,0},{0,1},{0,-1},{1,0}};
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                if((row!=entrance[0]||col!=entrance[1])&&(row==0||row==n-1||col==0||col==m-1)) return steps;
                for(int i=0;i<4;i++){
                    int nr=row+dr[i].first;
                    int nc=col+dr[i].second;
                    if(nr>=0&&nr<n&&nc>=0&&nc<m&&maze[nr][nc]=='.'){
                        q.push({nr,nc});
                        maze[nr][nc]='+';
                    }
                }
            }
            ++steps;
        }
        return -1;
    }
};