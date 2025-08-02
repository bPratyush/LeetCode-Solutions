class Solution {
public:
    bool isvow(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||c=='A'||c=='E'||c=='I'||c=='O'||c=='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int l=0,r=s.size()-1;
        while(l<r){
            while(l<r&&!isvow(s[l]))l++;
            while(l<r&&!isvow(s[r]))r--;
            if(isvow(s[l])&&isvow(s[r])){
                swap(s[l],s[r]);
                l++; r--;
            }
            else break;
        }
        return s;
    }
};