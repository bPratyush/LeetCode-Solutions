class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int cnt = 0;
        for (int i = n - 1; i >= 0; --i) { 
            for (int j = i; j < n; ++j) { 
                if (i == j) dp[i][j] = 1;
                else if (i + 1 == j && s[i] == s[j]) dp[i][j] = 1;
                else if (s[i] == s[j] && dp[i + 1][j - 1]) dp[i][j] = 1;
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};