class Solution {
public:
    bool ispal(string s,int l,int r){
        while(l<=r){
        if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.length();
        if(!n) return "";
        int maxlen=0,start=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(ispal(s,i,j)&&(j-i+1)>maxlen){
                    maxlen=j-i+1;
                    start=i;
                }
            }
        }
        return s.substr(start,maxlen);
    }
};