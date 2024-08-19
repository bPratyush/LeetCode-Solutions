class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int l=0,r=0,maxLen = 0, maxCount = 0;
        for (;r<s.size();r++) {
            mpp[s[r]]++;
            maxCount = max(maxCount, mpp[s[r]]);
            if (r-l+1-maxCount>k) mpp[s[l++]]--;
            maxLen = max(maxLen,r-l+1);
        }
        return maxLen;
    }
};