class Solution {
public:
    int dp(TreeNode* root, int &res){
        if(!root) return 0;
        int leftSum = dp(root->left, res);
        int rightSum = dp(root->right, res);
        int pathSum = max(root->val + max(leftSum, rightSum), root->val);
        int totalSum = max(pathSum, root->val + leftSum + rightSum);
        res = max(res, totalSum);
        return pathSum;
    }
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dp(root, res);
        return res;
    }
};
