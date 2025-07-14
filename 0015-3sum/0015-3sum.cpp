class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        set<vector<int>>tmp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int j=i+1, k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(sum==0) {
                    tmp.insert({nums[i],nums[j],nums[k]});
                    j++; k--;
                }
                else if(sum<0) j++;
                else k--;
            }
        }
        for(auto it:tmp) res.push_back(it);
        return res;
    }
};

