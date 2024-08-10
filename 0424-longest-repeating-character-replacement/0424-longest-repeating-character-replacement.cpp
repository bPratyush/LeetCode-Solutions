class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mpp;
        int maxLen = 0, maxCount = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            mpp[s[right]]++;
            maxCount = max(maxCount, mpp[s[right]]);
            if (right - left + 1 - maxCount > k) {
                mpp[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};