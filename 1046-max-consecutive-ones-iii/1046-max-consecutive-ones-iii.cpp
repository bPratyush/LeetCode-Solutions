class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size(),l=0,r=0,maxlen=0,zerocnt=0;
        for(;r<n;r++){
            if(nums[r]==0) zerocnt++;
            while(zerocnt>k){
                if(nums[l]==0) zerocnt--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};