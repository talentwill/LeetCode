// https://leetcode.com/problems/path-sum-iii

// 2024-02-13
class Solution {
public:
    int ans = 0;
    int k = 0;
    map<int64_t, int> pre_sum { { 0, 1 } };
    int pathSum(TreeNode* root, int targetSum) {
        k = targetSum;
        dfs(root, 0);
        return ans;
    }
    void dfs(TreeNode* root, int64_t pathsum) {
        if (root != nullptr) {
            pathsum += root->val;
            ans += pre_sum[pathsum - k];
            pre_sum[pathsum]++;
            dfs(root->left, pathsum);
            dfs(root->right, pathsum);
            pre_sum[pathsum]--;
        }
    }
};
