class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(),j=0,i=0;
        while(i<n){
            if(nums[i]){
                nums[j]=nums[i];
                if(j!=i) nums[i]=0;
                j++;
            }
            i++;
        }
    }
};