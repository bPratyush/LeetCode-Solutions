class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int n=nums.size();
       int maxp=nums[0],minp=nums[0];
       int result=nums[0];
       for(int i=1;i<nums.size();i++){
        if(nums[i]<0) swap(maxp,minp);
        maxp=max(nums[i],maxp*nums[i]);
        minp=min(nums[i],minp*nums[i]);
        result=max(result,maxp);
       }
       return result;
    }
};