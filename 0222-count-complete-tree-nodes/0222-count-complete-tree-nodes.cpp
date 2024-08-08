class Solution {
public:
    int count=0;
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        dfs(root);
        return count;
    }
    
    void dfs(TreeNode* root)
    {
        if(!root) return;
        count++;
        dfs(root->left);
        dfs(root->right);
    }
};