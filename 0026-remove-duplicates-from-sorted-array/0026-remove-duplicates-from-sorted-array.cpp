class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      unordered_set<int> seen;
      int ind=0;
      for(int num:nums){
        if(!seen.count(num)){
            nums[ind++]=num;
            seen.insert(num);
        }
      }  
      return seen.size();
    }
};