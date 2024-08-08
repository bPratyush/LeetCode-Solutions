class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int result = 0, count = 0;
        kthSmallestRecursive(root, k, count, result);
        return result;
    }

private:
    void kthSmallestRecursive(TreeNode* node, int k, int& count, int& result) {
        if (node == nullptr) return;
        kthSmallestRecursive(node->left, k, count, result);
        count++;
        if (count == k) {
            result = node->val;
            return;
        }
        kthSmallestRecursive(node->right, k, count, result);
    }
};