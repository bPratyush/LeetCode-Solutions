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
    void swap(TreeNode*&a,TreeNode*&b){
        TreeNode*tmp=a;
        a=b;
        b=tmp;
    }
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return NULL;
        swap(root->left,root->right);
        root->left=invertTree(root->left);
        root->right=invertTree(root->right);
        return root;
    }
};