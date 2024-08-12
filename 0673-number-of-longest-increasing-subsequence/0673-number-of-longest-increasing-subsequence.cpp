class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), ans = 0, maxi = 1;
        vector<int> dp(n, 1), cnt(n, 1);
        for(int i = 0 ; i < n ; i++){
            for(int prev = 0 ; prev < i ; prev++){
                if(nums[i] > nums[prev]){
                    if(dp[prev] + 1 > dp[i]){
                        cnt[i] = cnt[prev];
                        dp[i] = dp[prev] + 1;
                    }
                    else if(dp[prev] + 1 == dp[i]) cnt[i] += cnt[prev];
                }
            }
            if(dp[i] > maxi){
                maxi = dp[i];
                ans = cnt[i];
            }
            else if(dp[i] == maxi) ans += cnt[i];
        }
        return ans;
    }
};