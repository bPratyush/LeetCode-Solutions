class Solution {
public:
    bool check(vector<int>&nums,int div,int thresh){
        int sum=0;
        for(int num:nums){
            sum+=(num+div-1)/div;
            if(sum>thresh)return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
            int l=1;
            int r=*max_element(nums.begin(),nums.end());
            while(l<=r){
                int mid=l+(r-l)/2;
                if(check(nums,mid,threshold)) r=mid-1;
                else l=mid+1;
            }
            return l;
    }
};