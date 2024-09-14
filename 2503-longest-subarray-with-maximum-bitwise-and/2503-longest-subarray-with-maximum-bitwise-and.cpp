class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxval=0,ans=0,curr=0;
        for(int num:nums){
            if(maxval<num){
                maxval=num;
                ans=0; curr=0;
            }
            if(maxval==num) curr++;
            else curr=0;
            ans=max(ans,curr);
        }
        return ans;
    }
};