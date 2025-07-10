class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int tar=0;
        set<vector<int>>tmp;
        vector<vector<int>>res;
        for(int i=0;i<nums.size();i++){
            int j=i+1, k=nums.size()-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==tar){
                    tmp.insert({nums[i],nums[j],nums[k]});
                    j++; k--;
                }
                else if(sum<tar) j++;
                else k--;
            }
        } 
        for(auto i:tmp) res.push_back(i);
        return res;
    }
};

