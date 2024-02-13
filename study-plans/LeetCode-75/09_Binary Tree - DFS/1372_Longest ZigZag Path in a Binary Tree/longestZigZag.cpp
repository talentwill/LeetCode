// https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree

// 2024-02-13
class Solution {
public:
    int ans = 0;
    const int L = 0, R = 1;
    int longestZigZag(TreeNode* root) {
        dfs(root, L, 0);
        dfs(root, R, 0);
        return ans;
    }
    void dfs(TreeNode* root, int dir, int len) {
        if (root != nullptr) {
            ans = max(ans, len);
            if (dir == L) {
                dfs(root->left, R, len + 1); // 顺着zz方向走
                dfs(root->right, L, 1); // 以当前结点为起点
            } else {
                dfs(root->right, L, len + 1);
                dfs(root->left, R, 1);
            }
        }
    }
};
