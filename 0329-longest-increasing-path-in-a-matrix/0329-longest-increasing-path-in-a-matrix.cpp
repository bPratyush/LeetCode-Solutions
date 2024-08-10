class Solution {
public:
    vector<vector<int>> dp;
    int m, n;
    int fun(int i, int j, vector<vector<int>>& matrix){
        if(dp[i][j]!=-1) return dp[i][j];
        int cnt = 1;
        if(i>0 && matrix[i-1][j]<matrix[i][j])  cnt = max(cnt, 1+fun(i-1, j, matrix));
        if(j>0 && matrix[i][j-1]<matrix[i][j])  cnt = max(cnt, 1+fun(i, j-1, matrix));
        if((i+1)<m && matrix[i+1][j]<matrix[i][j]) cnt = max(cnt, 1+fun(i+1, j, matrix));
        if((j+1)<n && matrix[i][j+1]<matrix[i][j]) cnt = max(cnt, 1+fun(i, j+1, matrix));
        return dp[i][j] = cnt;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size(), n = matrix[0].size();
        dp.resize(m, vector<int>(n, -1));
        int ans = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans = max(ans, fun(i, j, matrix));
            }
        }
        return ans;
    }
};


