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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            TreeNode* node=u.first;
            int x=u.second.first;
            int y=u.second.second;
            nodes[x][y].insert(node->val);
            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }
        vector<vector<int>> res;
    // Iterate over the outer map
    for (const auto& p : nodes) {
    vector<int> col;
    // Iterate over the inner map
    for (const auto& q : p.second) {
        // Insert elements from the multiset into the column vector
        col.insert(col.end(), q.second.begin(), q.second.end());
    }
    // Add the column vector to the result
    res.push_back(col);
}
return res;
    }
};