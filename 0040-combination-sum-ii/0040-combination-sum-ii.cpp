class Solution {
public:
    void findcomb(int ind, vector<int>& arr, int target, set<vector<int>>& unique_combinations, vector<int>& ds) {
        if (target == 0) {
            unique_combinations.insert(ds);
            return;
        }
        for (int i = ind; i < arr.size(); ++i) {
            if (i > ind && arr[i] == arr[i-1]) continue;
            if (arr[i] > target) break;
            ds.push_back(arr[i]);
            findcomb(i + 1, arr, target - arr[i], unique_combinations, ds);
            ds.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> unique_combinations;
        vector<int> ds;
        sort(candidates.begin(), candidates.end()); 
        findcomb(0, candidates, target, unique_combinations, ds);
        vector<std::vector<int>> ans(unique_combinations.begin(), unique_combinations.end());
        return ans;
    }
};
