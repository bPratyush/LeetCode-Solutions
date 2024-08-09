class Solution {
public:
    bool isvowel(char c){
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxVowels(string s, int k) {
       int l=0,r=0,n=s.size(),cnt=0,res=0;
       for(;r<n;r++){
        if(isvowel(s[r])) cnt++;
        while(r-l+1>k){
            if(isvowel(s[l])) cnt--;
                l++;
            }
        res=max(res,cnt);
       }
       return res;
    }
};
