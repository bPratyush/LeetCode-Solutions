class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> seen;
        int index = 0;
        for (int num : nums) {
            if (!seen.count(num)) {
                nums[index++] = num;
                seen.insert(num);
            }
        }
        return seen.size();
    }
};
