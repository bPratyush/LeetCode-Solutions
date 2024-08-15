class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty()) return 0;
        int maxVal = *max_element(nums.begin(), nums.end());
        unordered_map<int,int> freq;
        for(int num : nums) freq[num]++;
        vector<int> dp(maxVal + 1, 0);
        dp[1] = freq[1];
        if(maxVal == 1) return dp[1]; 
        dp[2] = max(freq[1], freq[2] * 2);
        for(int i = 3; i <= maxVal; i++) dp[i] = max(dp[i - 1], dp[i - 2] + i * freq[i]);
        return dp[maxVal];
    }
};

