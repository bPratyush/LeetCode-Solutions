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
    void preorder(TreeNode* root, vector<TreeNode*>&res){
        if(!root) return;
        res.push_back(root);
        preorder(root->left,res);
        preorder(root->right,res);
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        vector<TreeNode*>nodes;
        preorder(root,nodes);
        for(auto it:nodes){
            if(it->val==val){
                return it;
            }
        }
        return nullptr;
    }
};