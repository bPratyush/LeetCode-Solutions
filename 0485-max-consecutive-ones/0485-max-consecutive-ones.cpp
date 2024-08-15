class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt=0,maxcnt=0;
        for(int num:nums){
            num?cnt++:cnt=0;
            maxcnt=max(cnt,maxcnt);
        }
        return maxcnt;
    }
};