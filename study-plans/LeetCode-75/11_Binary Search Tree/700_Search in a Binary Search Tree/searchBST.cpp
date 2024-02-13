// https://leetcode.com/problems/search-in-a-binary-search-tree/

// 2024-02-13
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root) {
            if (root->val == val) {
                return root;
            }
            if (val < root->val) {
                return searchBST(root->left, val);
            } else {
                return searchBST(root->right, val);
            }
        }
        return nullptr;
    }
};
