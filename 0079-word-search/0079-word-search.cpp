class Solution {
public:
    bool helper(vector<vector<char>>& board, string word,int i,int j,int n,int m, int k){
        if(k>=word.size()) return 1;
        if(i<0||i>=n||j<0||j>=m||board[i][j]=='.'||word[k]!=board[i][j]){
            return 0;
        }
        if(word.size()==1 && word[k]==board[i][j]) return 1;
        board[i][j]='.';
        int dr[4]={0,0,-1,1};
        int dc[4]={-1,1,0,0};
        bool tmp=0;
        for(int idx=0;idx<4;idx++) {
        tmp=tmp||helper(board, word, i+dr[idx], j+dc[idx], n, m, k+1);
        }
        board[i][j]=word[k];
        return tmp;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        if(!n) return 0;
        int m = board[0].size();
        if(!m) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    if(helper(board,word,i,j,n,m,0))
                        return 1;
                }
            }
        }
        return 0;
    }
};