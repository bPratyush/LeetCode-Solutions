class Fenwick {
    vector<int> pref_tree;
public:
    Fenwick(int n) {
        pref_tree.resize(n, 0);
    }
    void increment(int i) {
        while (i < pref_tree.size()) {
            ++pref_tree[i];
            i = i | (i + 1);
        }
    }

    int get_prefix_sum(int i) const {
        int sum = 0;
        while (i >= 0) {
            sum += pref_tree[i];
            i = (i & (i + 1)) - 1;
        }
        return sum;
    }
};

class Solution {
    static constexpr int MAX_NUM = 10'000;
public:
    vector<int> countSmaller(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
        Fenwick f(MAX_NUM*2 +2);
        for (int i = nums.size() - 1; i >= 0; --i) {
            int val = nums[i] + MAX_NUM + 1;
            nums[i] = f.get_prefix_sum(val - 1);
            f.increment(val);
        }
        return nums;
    }
};