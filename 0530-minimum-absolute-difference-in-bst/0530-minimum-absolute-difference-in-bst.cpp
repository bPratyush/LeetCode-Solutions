/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        res.push_back(root->val);
        preorder(root->left, res);
        preorder(root->right, res);
    }

    int getMinimumDifference(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        sort(res.begin(), res.end());
        int diff = INT_MAX;
        for (int i = 1; i < res.size(); ++i) {
            diff = min(diff, res[i] - res[i - 1]);
        }

        return diff;
    }
};