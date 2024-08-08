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

    void flatten(TreeNode* root) {
        if (!root) return;
        vector<int> v;
        preorder(root, v);
        TreeNode* current = root;
        for (int i = 1; i < v.size(); ++i) {
            current->left = nullptr;
            current->right = new TreeNode(v[i]);
            current = current->right;
        }
    }
};