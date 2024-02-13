// https://leetcode.com/problems/maximum-depth-of-binary-tree/

// 2024-02-13
class Solution {
public:
    int ans = 0;
    int maxDepth(TreeNode* root) { return dfs(root, 0); }
    int dfs(TreeNode* root, int depth) {
        if (root != nullptr) {
            ans = max(ans, depth + 1);
            dfs(root->left, depth + 1);
            dfs(root->right, depth + 1);
        }
        return ans;
    }
};
