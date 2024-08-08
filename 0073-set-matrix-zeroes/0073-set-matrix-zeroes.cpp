class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> zerorow;
        unordered_set<int> zerocol;
        int n=matrix.size(), m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    zerorow.insert(i);
                    zerocol.insert(j);
                }
            }
        }
        for(int r:zerorow){
            for(int j=0;j<m;j++) matrix[r][j]=0;
        }
        for(int c:zerocol){
            for(int j=0;j<n;j++) matrix[j][c]=0;
        }
    }
};