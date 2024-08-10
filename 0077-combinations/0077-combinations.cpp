
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> current;

        combineHelper(result, current, 1, n, k);

        return result;
    }

private:
    void combineHelper(vector<vector<int>>& result, vector<int>& current, int start, int n, int k) {
        if (k == 0) {
            result.push_back(current);
            return;
        }

        for (int i = start; i <= n; ++i) {
            current.push_back(i);
            combineHelper(result, current, i + 1, n, k - 1);
            current.pop_back();
        }
    }
};