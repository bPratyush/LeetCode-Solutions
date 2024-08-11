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
    void swapTree(TreeNode* &l1, TreeNode* &l2) {
        TreeNode* a = l1;
        l1 = l2;
        l2 = a;
    }
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        swapTree(root->left, root->right);
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
};
