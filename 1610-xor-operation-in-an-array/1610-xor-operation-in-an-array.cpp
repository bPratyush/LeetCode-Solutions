class Solution {
public:
    int xorOperation(int n, int start) {
        vector<int>nums(n);
        int sum=0;
        for(int i=0;i<n;i++) {
            nums[i]=2*i+start;
            sum^=nums[i];
        }
        return sum;
    }
};