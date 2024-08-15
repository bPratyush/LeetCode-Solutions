class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d + 1, vector<int>(target + 1, 0));
        int mod = 1e9 + 7;
        dp[0][0] = 1;
        for (int i = 1; i <= d; i++) {
            for (int j = i; j <= target; j++) {
                for (int k = 1; k <= f && k <= j; k++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
                }
            }
        }
        return dp[d][target];
    }
};