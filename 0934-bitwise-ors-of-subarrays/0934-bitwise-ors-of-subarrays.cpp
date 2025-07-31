class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> cur;
        for (int x : arr) {
            unordered_set<int> cur2;
            cur2.insert(x);
            for (int y : cur) cur2.insert(x | y);
            cur = cur2;
            for (int val : cur) ans.insert(val);
        }
        return ans.size();
    }
};