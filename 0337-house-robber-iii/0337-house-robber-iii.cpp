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
    vector<int> robsub(TreeNode* root){
        if(!root) return {0,0};
        vector<int> lft=robsub(root->left);
        vector<int> rgt=robsub(root->right);
        vector<int> res(2);
        res[0]=max(lft[0],lft[1])+max(rgt[0],rgt[1]);
        res[1]=root->val+lft[0]+rgt[0];
        return res;
    }
    int rob(TreeNode* root) {
        vector<int> res=robsub(root);
        return max(res[0],res[1]);
    }
};