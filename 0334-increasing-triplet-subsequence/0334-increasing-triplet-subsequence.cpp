class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int mini = nums[0];
        int mini2 = INT_MAX;
        for(int x : nums){
            if(x <= mini) mini = x;
            else if(x <= mini2) mini2 = x;
            else return true;
        }
        return false;
    }
};
