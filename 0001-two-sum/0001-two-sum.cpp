class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> hash;
       vector<int> res;
       int i=0;
       while(i<nums.size()){
        int target2=target-nums[i];
        if(hash.find(target2)!=hash.end()){
            res.push_back(hash[target2]);
            res.push_back(i);
            return res;
        }
        else hash[nums[i]]=i;
        i++;
       }
       return res;
    }
};