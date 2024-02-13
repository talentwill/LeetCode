// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// 2024-02-13
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr or root == p or root == q) {
            return root;
        }

        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);
        if (left and right) {
            return root;
        }
        return left ? left : right;
    }
};