class Solution {
public:
    unordered_map<int, vector<char>> phone;
    Solution() {
        phone[1] = {};
        phone[2] = {'a', 'b', 'c'};
        phone[3] = {'d', 'e', 'f'};
        phone[4] = {'g', 'h', 'i'};
        phone[5] = {'j', 'k', 'l'};
        phone[6] = {'m', 'n', 'o'};
        phone[7] = {'p', 'q', 'r', 's'};
        phone[8] = {'t', 'u', 'v'};
        phone[9] = {'w', 'x', 'y', 'z'};
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        vector<string> ans;
        backtrack(ans, digits, "");
        return ans;
    }

    void backtrack(vector<string>& ans, string digits, string curr) {
        if (digits == "") {
            ans.push_back(curr);
            return;
        }
        char c = digits[0];
        if (c != '1') {
            for (char letter : phone[c - '0']) {
                curr += letter;
                backtrack(ans, digits.substr(1, digits.size()-1), curr);
                curr.pop_back();
            }
        }
        else backtrack(ans, digits.substr(1, digits.size()-1), curr);
    }
};