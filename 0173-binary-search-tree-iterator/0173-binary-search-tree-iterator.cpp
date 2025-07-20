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
class BSTIterator {
public:
    stack<int>st;
    void inorder(TreeNode*root){
        if(!root) return;
        if(root->right) inorder(root->right);
        st.push(root->val);
        if(root->left) inorder(root->left);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        int nxt=st.top();
        st.pop();
        return nxt;
    }
    
    bool hasNext() {
        return st.size()?1:0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */