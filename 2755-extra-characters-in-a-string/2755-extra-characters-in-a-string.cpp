class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) {
        int n=s.length();
        unordered_set<string> st(dict.begin(),dict.end());
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            dp[i]=dp[i+1]+1;
            for(int j=i;j<n;j++){
                string c=s.substr(i,j-i+1);
                if(st.count(c)) dp[i]=min(dp[i],dp[j+1]);
            }
        }
        return dp[0];
    }
};