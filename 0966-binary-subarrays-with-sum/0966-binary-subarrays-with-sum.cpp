class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>hash;
        hash[0]=1;
        int cursum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            if(hash.find(cursum-goal)!=hash.end()) cnt+=hash[cursum-goal];
            hash[cursum]++;
        }
        return cnt;
    }
};