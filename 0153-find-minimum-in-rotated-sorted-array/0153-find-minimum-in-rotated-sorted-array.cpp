class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] < nums[r]) {
                r = mid; // The minimum is in the left part (including mid)
            } else {
                l = mid + 1; // The minimum is in the right part (excluding mid)
            }
        }

        return nums[l]; // After the loop, l == r, and it points to the minimum element
    }
};