// https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree

// 2024-02-13
class Solution {
public:
    int ans = 0; // level of sum
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> p, q;
        p.push(root);
        int max_sum = root->val;
        int this_sum = root->val;
        int level = 0;
        while (not p.empty()) {
            auto x = p.front();
            this_sum += x->val;
            p.pop();
            if (x->left) {
                q.push(x->left);
            }
            if (x->right) {
                q.push(x->right);
            }
            if (p.empty()) {
                level++;
                if (this_sum > max_sum) {
                    ans = level;
                    max_sum = this_sum;
                }
                this_sum = 0;
                p.swap(q);
            }
        }
        return ans;
    }
};
