// https://leetcode.com/problems/count-good-nodes-in-binary-tree

// 2024-02-13
class Solution {
public:
    int ans = 0;
    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return ans;
    }
    void dfs(TreeNode* root, int max_value) {
        if (root != nullptr) {
            if (root->val >= max_value) {
                max_value = root->val;
                ans++;
            }
            dfs(root->left, max_value);
            dfs(root->right, max_value);
        }
    }
};
