class Solution {
public:
    void solve(int ind, vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& op) {
    // Base case: if target is 0, add the current combination to the result
    if (target == 0) {
        res.push_back(op);
        return;
    }

    // Explore each candidate starting from index `ind`
    for (int i = ind; i < candidates.size(); ++i) {
        if (candidates[i] <= target) {
            // Include the current candidate and move forward
            op.push_back(candidates[i]);
            solve(i, candidates, target - candidates[i], res, op);
            // Backtrack to explore other combinations
            op.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> op;
    solve(0, candidates, target, res, op);
    return res;
}
};