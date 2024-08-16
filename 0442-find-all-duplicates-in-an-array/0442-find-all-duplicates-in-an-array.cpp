class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        vector<int> res;
        for(int num:nums){
            if(seen.find(num)!=seen.end()) res.push_back(num);
            else seen.insert(num);
        }
        return res;
    }
};