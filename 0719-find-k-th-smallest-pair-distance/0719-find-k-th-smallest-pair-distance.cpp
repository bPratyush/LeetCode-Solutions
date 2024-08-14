class Solution {
public:
    bool isPossible(vector<int> &nums, int diff, int k){
        int pairs=0, j=0;
        for(int i=0;i<nums.size();i++){
            while(j<nums.size() && nums[j]-nums[i]<=diff) j++;
            pairs+=(j-i-1);
        }
        return pairs>=k;
    }
    
    int smallestDistancePair(vector<int>& nums, int k) {
        int low=0, high=1000000;
        sort(nums.begin(),nums.end());
        while(low<high){
            int mid=(low+high)/2;
            if(isPossible(nums,mid,k)==true) high=mid;
            else low=mid+1;
        }
        return low;
    }
};