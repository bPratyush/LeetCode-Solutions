class Solution {
public:
    void convert(TreeNode* root, vector<int>& res) {
        if (root) {
            convert(root->left, res);
            res.push_back(root->val);
            convert(root->right, res);
        }
    }

    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        vector<int> res;
        convert(root, res);
        int left = 0, right = res.size() - 1;
        while (left < right) {
            int sum = res[left] + res[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        return false;
    }
};