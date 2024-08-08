class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> hashset(nums.begin(), nums.end());
        int ls = 0;
        for(int num : hashset) {
            if(!hashset.count(num - 1)) {
                int curnum = num;
                int curstreak = 1;
                while(hashset.count(curnum + 1)) {
                    curnum += 1;
                    curstreak += 1;
                }
                ls = max(ls, curstreak);
            }
        }
        return ls;
    }
};

