class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=nums[0],mx=nums[0];
        for(int i=1;i<nums.size();i++){
            cursum=max(nums[i],cursum+nums[i]);
            mx=max(mx,cursum);
        }
        return mx;
    }
};