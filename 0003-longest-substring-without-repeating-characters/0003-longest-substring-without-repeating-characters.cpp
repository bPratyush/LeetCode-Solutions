class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       unordered_map<char,int> freq;
       int l=0,r=0,res=0;
       for(;r<s.length();r++){
        freq[s[r]]++;
        while(freq[s[r]]>1) freq[s[l++]]--;
        res=max(res,r-l+1);
       }
       return res;
    }
};
