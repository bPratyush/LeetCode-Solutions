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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        zigzagTraversal(root, result, 0);
        return result;
    }

private:
    void zigzagTraversal(TreeNode* root, vector<vector<int>>& result, int level) {
        if (!root) return;
        if (result.size() <= level) result.push_back({});
        if (level % 2 == 0) result[level].push_back(root->val);
        else result[level].insert(result[level].begin(), root->val);
        zigzagTraversal(root->left, result, level + 1);
        zigzagTraversal(root->right, result, level + 1);
    }
};