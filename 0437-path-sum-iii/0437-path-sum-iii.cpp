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
    int fxn(TreeNode* root,long int targetSum){
        int cnt=0;
        if(root->val==targetSum) cnt++;
        if(root->left) cnt+=fxn(root->left,targetSum-(root->val));
        if(root->right) cnt+=fxn(root->right,targetSum-(root->val));
        return cnt; 
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        int cnt = fxn(root,targetSum);
        cnt+=pathSum(root->left,targetSum);
        cnt+=pathSum(root->right,targetSum);
        return cnt;
    }
};