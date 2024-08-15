class Solution {
public:
    bool ispal(string s){
        int l=0,r=s.size()-1;
        while(l<=r){
            if(s[l++]!=s[r--]) return false;
        }
        return true;
    }
    bool isPalindrome(int x) {
        string s=to_string(x);
        return ispal(s);
    }
};