class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> st;
        for(auto &str: wordDict) st.insert(str);
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                int len = i - j + 1;
                string str = s.substr(j - 1, len);
                if(st.find(str) != st.end()) dp[i] = (dp[i] || dp[j-1]);
            }
        }
        return dp[n];
    }
};