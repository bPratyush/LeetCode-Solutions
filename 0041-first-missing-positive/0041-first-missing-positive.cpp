class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        map<int, int>mp;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0){
                mp[nums[i]]++;
            }
        }
        int smallest =1;
        for(auto i: mp){
            if(i.first!=smallest){
                return smallest;
            }
            smallest++;
        }
        return smallest; //it should never reach this line
    }
};
