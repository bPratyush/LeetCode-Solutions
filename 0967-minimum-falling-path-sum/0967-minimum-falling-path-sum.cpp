class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for (int j = 0; j < m; j++) dp[0][j] = matrix[0][j];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int best = dp[i-1][j]; 
                if (j > 0) best = min(best, dp[i-1][j-1]); 
                if (j < m-1) best = min(best, dp[i-1][j+1]); 
                dp[i][j] = best + matrix[i][j];
            }
        }
        int minPathSum = dp[n-1][0];
        for (int j = 1; j < m; j++) minPathSum = min(minPathSum, dp[n-1][j]);
        return minPathSum;
    }
};