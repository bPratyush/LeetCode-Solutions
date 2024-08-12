class Solution {
public:
    string shortestCommonSupersequence(string text1, string text2) {
        //Longest Common Subsequence DP Top Down Approach
        int n=text1.length(), m=text2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0)); 
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
            if(text1[i-1]==text2[j-1]) dp[i][j]=max(dp[i][j],1+dp[i-1][j-1]);
            else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        //Printing LCS
        int i=n,j=m;
        string LCS="";
        while(i>0 && j>0){
            if(text1[i-1]==text2[j-1]){
                LCS+=text1[i-1];
                i--;
                j--;
            }
            else{
                if(dp[i-1][j]>dp[i][j-1]){
                    LCS+=text1[i-1];
                    i--;
                }
                else{
                    LCS+=text2[j-1];
                    j--;
                }
            }
        }
        //Taking remaining characters from str1 and str2
        while(i>0){
            LCS+=text1[i-1];
            i--;
        }
        while(j>0){
            LCS+=text2[j-1];
            j--;
        }
        //Reversal not mandatory here but used for printing LCS
        reverse(LCS.begin(),LCS.end());
        return LCS;
    }
};