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
    int ans;
    void dfs(TreeNode* root, int maxi){
        if(!root) return;
        if(root->val>=maxi) ans++;
        maxi=max(root->val,maxi);
        dfs(root->left,maxi);
        dfs(root->right,maxi);
    }
    int goodNodes(TreeNode* root) {
        int maxi=root->val;
        dfs(root,maxi);
        return ans;
    }
};