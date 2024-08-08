class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}, {1,1}, {-1,-1}, {1,-1}, {-1,1}};
        vector<vector<int>> copyBoard = board;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int neigh = 0;
                for(auto dir : dirs){
                    int ni = i + dir[0];
                    int nj = j + dir[1];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && copyBoard[ni][nj]==1)
                    neigh++;
                }
                if(board[i][j]==1 && (neigh<2 || neigh>3)) board[i][j]=0;
                else if(board[i][j]==0 && neigh==3) board[i][j] = 1;
            }
        }
    }
};