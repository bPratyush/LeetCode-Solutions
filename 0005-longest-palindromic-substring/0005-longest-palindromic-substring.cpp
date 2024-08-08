class Solution {
public:
bool isPalindrome(const std::string& str, int l, int r) {
    while (l < r) {
        if (str[l++] != str[r--]) return false;
    }
    return true;
}
    string longestPalindrome(string s) {
        int n = s.length();
        if (n == 0) return "";
        int maxLength = 0, start = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j) && (j - i + 1) > maxLength) {
                    maxLength = j - i + 1;
                    start = i;
            }
        }
    }
    return s.substr(start, maxLength);
    }
};