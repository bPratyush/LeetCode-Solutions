class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        hash[0]=1;
        int cursum=0,cnt=0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            if(hash.find(cursum-k)!=hash.end())cnt+=hash[cursum-k];
            hash[cursum]++;
        }
        return cnt;
    }
};