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
    void find(TreeNode*node,vector<string>&res,string tmp){
        tmp+=to_string(node->val);
        if(node->left) find(node->left,res,tmp+"->");
        if(node->right) find(node->right,res,tmp+"->");
        if(!node->left&&!node->right) res.push_back(tmp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root) find(root,res,"");
        return res;
    }
};