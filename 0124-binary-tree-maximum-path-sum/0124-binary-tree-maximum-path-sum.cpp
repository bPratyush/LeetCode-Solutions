class Solution {
public:
    int helper(TreeNode*root,int&res){
        if(!root) return 0;
        int lsum=helper(root->left,res);
        int rsum=helper(root->right,res);
        int pathsum=max(root->val+max(lsum,rsum),root->val);
        int target=max(pathsum,root->val+lsum+rsum);
        res=max(res,target);
        return pathsum;
    }
    int maxPathSum(TreeNode* root) {
        int res=INT_MIN;
        helper(root,res);
        return res;
    }
};
