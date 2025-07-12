class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int>freq;
        int oddf=0;
        for(char c:s){
            freq[c]++;
            if(freq[c]%2) oddf++;
            else oddf--;
        }
        if(oddf) return s.length()-oddf+1;
        else return s.length();
    }
};