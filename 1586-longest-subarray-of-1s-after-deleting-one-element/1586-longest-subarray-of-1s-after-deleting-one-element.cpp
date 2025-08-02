class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int zerocnt=0,maxlen=0,l=0,r=0;
       for(;r<nums.size();r++){
        if(nums[r]==0) zerocnt++;
        while(zerocnt>1){
            if(nums[l]==0) zerocnt--;
            l++;
        }
        maxlen=max(maxlen,r-l);
       } 
       return maxlen;
    }
};