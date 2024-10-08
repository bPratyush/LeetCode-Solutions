class Solution {
public:
    int minInsertions(string str) {
        int n=str.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(str[i-1]==str[n-j]) dp[i][j]=1+dp[i-1][j-1];
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return n-dp[n][n];
    }
};