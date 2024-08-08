class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
      int low, mid, high;
      for(int i = 0; i < num.size(); ++i){
        int complement = target - num[i];
        low = i+1;
        high = num.size()-1;
        while(low <= high){
          mid = (low + high) / 2;
          if(num[mid] == complement) return {i+1, mid+1};
          else if(num[mid] > complement) high = mid - 1;
          else low = mid + 1;
        }
      }
      return {};    
    }
};