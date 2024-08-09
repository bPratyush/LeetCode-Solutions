class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int j=0; 
        for (int i=0; i<n; i++) {
            if (nums[i]) {
                nums[j] = nums[i];
                if (j != i) nums[i] = 0;
                j++;
            }
        }
    }
};
