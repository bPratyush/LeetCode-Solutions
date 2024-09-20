class Solution {
public:
    string shortestPalindrome(string s) {
        int len=s.length();
        if(!len) return s;
        int l=0,r=len-1;
        for(;r>=0;r--){
            if(s[r]==s[l]) l++;
        }
        if(l==len) return s;
        string suf=s.substr(l);
        string rev=string(suf.rbegin(),suf.rend());
        return rev+shortestPalindrome(s.substr(0,l))+suf;
    }
};