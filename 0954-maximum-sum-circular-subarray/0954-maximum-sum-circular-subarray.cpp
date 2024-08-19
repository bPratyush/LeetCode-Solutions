class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int curMax = 0, curMin = 0;
        int maxSum = nums[0], minSum = nums[0];
        int totalSum = 0;
        
        for (int num: nums) {
            curMax = max(curMax+num, num);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin+num, num);
            minSum = min(minSum, curMin);
            totalSum += num;  
        }
        if (totalSum == minSum) return maxSum;
        return max(maxSum, totalSum - minSum);
    }
};