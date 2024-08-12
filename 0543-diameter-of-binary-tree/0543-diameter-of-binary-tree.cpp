class Solution {
public:
    int treesol(TreeNode* root, int& res){
        if(root==nullptr) return 0;
        int l = treesol(root->left,res);
        int r = treesol(root->right,res);
        res=max(res,l+r);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res=INT_MIN;
        treesol(root,res);
        return res;
    }
};