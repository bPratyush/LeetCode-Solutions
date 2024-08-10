class Solution {
public:
    int subarray(vector<int>&nums, int k){
        int l=0,r=0, cnt=0, res=0;
       for(;r<nums.size();r++){
        if(nums[r]%2!=0) cnt++;
        while(cnt>k){
            if(nums[l]%2!=0) cnt--;
            l++;
        }
        res+=r-l+1;
       } 
       return res;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
       return subarray(nums,k)-subarray(nums,k-1);
    }
};