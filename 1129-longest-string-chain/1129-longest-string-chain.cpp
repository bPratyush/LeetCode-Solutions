class Solution {
public:
    bool static compareBySize(const std::string& a, const std::string& b) {
        return a.size() < b.size();
    }
    bool isValid(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        int i = n-1, j = m-1;
        while(i >= 0){
            if(j >= 0 && s1.at(i) == s2.at(j)){
                i--;
                j--;
            }
            else i--;
        }
        if(i == -1 && j == -1) return true;
        else return false;
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), compareBySize);
        vector<int> dp(n, 1);
        int ans = INT_MIN;
        for(int i = 0; i < n; i++){
            for(int prev = 0; prev < i; prev++){
                if(words[i].size() == words[prev].size() + 1 && isValid(words[i], words[prev]) && 1 + dp[prev] > dp[i]) dp[i] = 1 + dp[prev];
            }
            ans = max(dp[i], ans);
        }
        return ans;
    }
};