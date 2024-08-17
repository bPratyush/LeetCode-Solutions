class Solution {
private:
    vector<int> stack;
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if (n == k) return "0";
        for (int i = 0; i < n; ++i) {
            while (k > 0 && !stack.empty() && num[i] < num[stack.back()]) {
                stack.pop_back();
                k--;
            }
            stack.push_back(i);
        }
        while (k > 0) {
            stack.pop_back();
            k--;
        }
        string result = "";
        for (int i : stack) {
            if (!(result.empty() && num[i] == '0'))
                result += num[i];
        }
        return result.empty() ? "0" : result;
    }
};
