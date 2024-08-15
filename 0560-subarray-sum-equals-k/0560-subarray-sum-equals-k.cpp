class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size()==1&&k==0) return 0;
       int l=0,r=0,n=nums.size(),sum=0,cnt=0;
       for(;r<n;r++){
        sum+=nums[r];
        while(sum>k){
            sum-=nums[l++];
        }
        if(sum==k) cnt++;
       } 
       return cnt;
    }
};