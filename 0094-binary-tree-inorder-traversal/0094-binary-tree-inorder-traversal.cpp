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
    vector<int> inorderTraversal(TreeNode* root) { // Morris Traversal
        vector<int> ans;
        TreeNode* curr = root;
        while(curr) // while curr is not equal to null;
        {
            if(curr->left == NULL) // case 1 : if curr-> left == NULL, then add curr to ans and move to right.
            {
                ans.push_back(curr->val);
                curr = curr->right;
            }
            // case 2 : if curr-> left != NULL, then go to rightmost node of left subtree, and check whether it is connected to root or not, if not connected
            //(it means that it's the first time the node has been visited and hence needed to be joined with root),  connect it.

            else
            { 
                TreeNode* prev = curr->left;
                while(prev->right != NULL && prev->right != curr)
                {
                    prev = prev->right;
                }
                if(prev->right == NULL)
                {
                    prev->right = curr;
                    curr = curr->left;
                }
                    
                // case 3 : else if connected break the connection, add the current node,
                //i.e root node to ans and then move the current position to right.
                else
                {
                    prev->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
                
            
        }
        return ans;
    }
};