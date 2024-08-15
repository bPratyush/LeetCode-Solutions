class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        // dp array to store the maximum sums for remainders 0, 1, and 2
        vector<int> dp(3, 0);
        for (int num : nums) {
            // Create a temporary copy of the current state of dp
            vector<int> temp(dp);
            for (int sum : temp) {
                // Calculate the new sum and its remainder when divided by 3
                int newSum = sum + num;
                int remainder = newSum % 3;
                // Update the dp array for the new remainder
                dp[remainder] = max(dp[remainder], newSum);
            }
        }
        // The result is the maximum sum that is divisible by 3
        return dp[0];
    }
};