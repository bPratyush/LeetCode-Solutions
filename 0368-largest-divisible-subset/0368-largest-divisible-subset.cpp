class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> dp(n, 1), previous(n, -1), res;
        int max_len = 0, max_index = -1;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    previous[i] = j;
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                max_index = i;
            }
        }
        
        while (max_index != -1) {
            res.push_back(nums[max_index]);
            max_index = previous[max_index];
        }
        if(nums.size()==1) {
            res.push_back(nums[0]);
            return res;
        };
        return res;
    }
};