class Solution {
public:
    bool subsetsum(vector<int>&nums,int target){
        int n=nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(target+1,false));
        for(int i=0;i<=n;i++) dp[i][0]=true;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                if(nums[i-1]<=j) dp[i][j]=dp[i-1][j]||dp[i-1][j-nums[i-1]];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n][target];
    }
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int num:nums) sum+=num;
        if(sum%2) return false;
        return subsetsum(nums,sum/2);
    }
};