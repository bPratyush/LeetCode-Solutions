class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }

private:
    int robRange(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if(n == 1) return nums[start];
        vector<int> dp(n, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for(int i = 2; i < n; i++) dp[i] = max(dp[i - 1], dp[i - 2] + nums[i + start]);
        return dp[n - 1];
    }
};