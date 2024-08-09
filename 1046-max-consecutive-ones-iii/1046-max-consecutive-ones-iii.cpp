class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int lft=0,maxlen=0,rgt=0,zerocnt=0;
        for(int rgt=0;rgt<nums.size();rgt++){
                if(nums[rgt]==0) zerocnt++;
            while(zerocnt>k){
                if(nums[lft]==0) zerocnt--;
                lft++;
            }
            maxlen=max(maxlen,rgt-lft+1);
        }
        return maxlen;
    }
};
