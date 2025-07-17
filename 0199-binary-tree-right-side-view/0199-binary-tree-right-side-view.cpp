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
    void dfsr(TreeNode* root,vector<int>&res,int l){
        if(!root) return;
        if(l==res.size()) res.push_back(root->val);
        dfsr(root->right,res,l+1);
        dfsr(root->left,res,l+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfsr(root,res,0);
        return res;
    }
};