class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>hash;
        hash[0]=1;
        int cursum=0, cnt=0;
        for(int i=0;i<nums.size();i++){
            cursum+=nums[i];
            int rem=cursum%k;
            if(rem<0) rem+=k;
            if(hash.find(rem)!=hash.end()) cnt+=hash[rem];
            hash[rem]++;
        }
        return cnt;
    }
};