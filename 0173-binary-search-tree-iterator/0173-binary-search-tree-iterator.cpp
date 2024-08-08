class BSTIterator {
public:
    stack<int>s;
    void ino( TreeNode*root) {
        if(root==NULL) return;
        if(root->right) ino(root->right);
        s.push(root->val);
        if(root->left) ino(root->left);
    }
    BSTIterator(TreeNode* root) {
        ino(root);
    }
    
    int next() {
        int n=s.top();
        s.pop();
        return n;
    }
    
    bool hasNext() {
        if(s.size()>0) return 1;
        return 0; 
    }
};