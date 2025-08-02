class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double res=0;
        for(int i=0;i<k;i++) res+=nums[i];
        double sum=res;
        res/=k;
        int l=0,r=k;
        while(r<nums.size()){
            sum+=nums[r++];
            sum-=nums[l++];
            res=max(res,sum/k);
        }
        return res;
    }
};