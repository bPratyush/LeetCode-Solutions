class Solution {
public:
    int myAtoi(string s) {
        vector<int> res;
        bool isNegative = false;
        bool foundDigit = false;
        for (char c : s) {
            if (c == ' ' && !foundDigit) continue;
            if ((c == '+' || c == '-') && !foundDigit) {
                isNegative = (c == '-');
                foundDigit = true;
                continue;
            }
            if (isdigit(c)) {
                foundDigit = true;
                res.push_back(c - '0');
            } else break;
        }
        if (res.empty()) return 0;
        int result = 0;
        for (auto d : res) {
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && d > INT_MAX % 10)) {
                return isNegative ? INT_MIN : INT_MAX;
            }
            result = result * 10 + d;
        }
        return isNegative ? -result : result;
    }
};
