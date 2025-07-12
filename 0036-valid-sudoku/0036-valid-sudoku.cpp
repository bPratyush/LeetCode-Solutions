class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int> box,row,col;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.') row[board[i][j]]++;
                if(board[j][i]!='.') col[board[j][i]]++;
                if(row[board[i][j]]>1 || col[board[j][i]]>1) return false;
            }
            row.clear(); col.clear();
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                box.clear();
                for(int x=i;x<i+3;x++){
                    for(int y=j;y<j+3;y++){
                        if(board[x][y]!='.') box[board[x][y]]++;
                        if(box[board[x][y]]>1) return false;
                    }
                }
            }
        }  
        return true;
    }
};