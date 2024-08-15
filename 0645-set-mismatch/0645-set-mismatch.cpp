class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> res;
        for(int num:nums){
            if(seen.count(num)) res.push_back(num);
            else seen.insert(num);
        }
        for(int i=1;i<=nums.size();i++){
            if(!seen.count(i)) res.push_back(i);
        }
        return res;
    }
};