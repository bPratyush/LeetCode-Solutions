class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int i=0, j=0, N = nums.size(), ans=0, prod=1;
        if(k==0) return 0;
        for(;j<N;j++){
            prod*=nums[j];
            while(prod>=k && i<=j) prod/=nums[i++];
            ans+=j-i+1;
        }
        return ans;
    }
};