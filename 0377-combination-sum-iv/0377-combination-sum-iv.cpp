class Solution {
public:
    int dp(vector<int>&nums,int target,vector<int>&dip){
        if(!target) return 1;
        if(target<0) return 0;
        if(dip[target]!=-1) return dip[target];
        int res=0;
        for(int i=0;i<nums.size();i++) res+=dp(nums,target-nums[i],dip);
        return dip[target]=res;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dip(target+1,-1);
        return dp(nums,target,dip);
    }
};