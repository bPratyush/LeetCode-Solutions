class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
      int n=matrix.size(), m=matrix[0].size(), maxlen=0;
      vector<vector<int>>dp(n+1,vector<int>(m+1,0));
      for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(matrix[i-1][j-1]=='1'){
                dp[i][j]=min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]})+1;
                maxlen=max(maxlen,dp[i][j]);
            }
        }
    }
    return maxlen*maxlen;
    }
};