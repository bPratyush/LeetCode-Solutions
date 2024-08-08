class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,sum=0,res=INT_MAX,n=nums.size();
        for(;r<n;r++){
            sum+=nums[r];
            while(sum>=target){
                res=min(res,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return (res!=INT_MAX)?res:0;
    }
};