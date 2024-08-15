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
    void inorder(TreeNode* root, set<int>& vals) {
        if (root) {
            inorder(root->left, vals);
            vals.insert(root->val);
            inorder(root->right, vals);
        }
    }

    int findSecondMinimumValue(TreeNode* root) {
        set<int> vals;
        inorder(root, vals);
        if (vals.size() < 2) return -1;
        else {
            auto it = vals.begin();
            advance(it, 1); 
            return *it;
        }
    }
};
