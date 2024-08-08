class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k%=n; 
        vector<int> result(n);
        for(int i=0; i<n; i++) result[(i+k)%n]=nums[i];
        nums=result;
    }
};
