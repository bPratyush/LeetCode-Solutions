class Solution {
public:
    void bt(int idx,vector<vector<int>>&res,vector<int>&nums){
        int n=nums.size();
        if(idx==n){
            res.push_back(nums); return;
        }
        unordered_set<int>used;
        for(int i=idx;i<nums.size();i++){
            if(used.find(nums[i])!=used.end()) continue;
            used.insert(nums[i]);
            swap(nums[idx],nums[i]);
            bt(idx+1,res,nums);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        bt(0,res,nums);
        return res;
    }
};