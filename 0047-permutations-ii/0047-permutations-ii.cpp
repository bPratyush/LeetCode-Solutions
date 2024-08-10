class Solution {
public:
    void bt(int index, vector<vector<int>>& ans, vector<int>& nums, unordered_set<int>& used_indices) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        unordered_set<int> used;
        for (int i = index; i < nums.size(); i++) {
            if (used.find(nums[i]) != used.end()) continue;
            used.insert(nums[i]);
            swap(nums[index], nums[i]);
            bt(index + 1, ans, nums, used_indices);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_set<int> used_indices;
        sort(nums.begin(), nums.end());
        bt(0, ans, nums, used_indices);
        return ans;
    }
};