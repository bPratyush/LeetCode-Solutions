class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(),
        [](const vector<int>& a, const vector<int>& b) { return a[1] < b[1];});
        int currentEnd = INT_MIN;
        int longestChain = 0;
        for (const auto& pair : pairs) {
            if (currentEnd < pair[0]) {
                currentEnd = pair[1];
                longestChain++;
            }
        }
        return longestChain;
    }
};