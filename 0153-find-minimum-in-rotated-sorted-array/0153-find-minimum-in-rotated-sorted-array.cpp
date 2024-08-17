class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len - 1;
        int mini = nums[0];
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] < mini) {
                mini = nums[mid];
            }
            if (nums[mid] < nums[r]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return mini;
    }
};