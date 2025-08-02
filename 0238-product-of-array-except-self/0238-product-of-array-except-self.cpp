class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n,1);
        int lp=1,rp=1;
        for(int i=0;i<n;i++){
            res[i]*=lp;
            lp*=nums[i];
        }
        for(int i=n-1;i>=0;i--){
            res[i]*=rp;
            rp*=nums[i];
        }
        return res;
    }
};