class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int i = 0, j = 0, sum = 0, ans = 0, N = s.size();
        for (; j < N; ++j) {
            sum += abs(s[j] - t[j]);

            while (sum > maxCost) { 
                sum -= abs(s[i] - t[i]);
                ++i;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};
