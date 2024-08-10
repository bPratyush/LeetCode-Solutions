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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        TreeNode* lastVisited = nullptr;

        while (!s.empty() || cur) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                TreeNode* peekNode = s.top();
                if (peekNode->right && lastVisited != peekNode->right) {
                    cur = peekNode->right;
                } else {
                    res.push_back(peekNode->val);
                    lastVisited = s.top();
                    s.pop();
                }
            }
        }

        return res;
    }
};

