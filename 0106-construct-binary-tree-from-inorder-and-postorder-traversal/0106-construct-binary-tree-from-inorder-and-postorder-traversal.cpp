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
    TreeNode* build(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int postart,int postend, map<int,int>&mpp){
        if(postart>postend||instart>inend) return NULL;
        TreeNode*root=new TreeNode(postorder[postend]);
        int inroot=mpp[postorder[postend]];
        int numsleft=inroot-instart;
        root->left=build(inorder,instart,inroot-1,postorder,postart,postart+numsleft-1,mpp);
        root->right=build(inorder,inroot+1,inend,postorder,postart+numsleft,postend-1,mpp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size(), m=postorder.size();
        if(n!=m) return NULL;
        map<int,int>mpp;
        for(int i=0;i<n;i++) mpp[inorder[i]]=i;
        return build(inorder,0,n-1,postorder,0,m-1,mpp);
    }
};