// https://leetcode.com/problems/binary-tree-right-side-view

// 2024-02-13
class Solution {
public:
    vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        if (not root) {
            return {};
        }
        queue<TreeNode*> q1, q2;
        q1.push(root);
        while (not q1.empty()) {
            auto x = q1.front();
            q1.pop();
            if (x->left) {
                q2.push(x->left);
            }
            if (x->right) {
                q2.push(x->right);
            }
            if (q1.empty()) {
                q1.swap(q2);
                ans.push_back(x->val);
            }
        }
        return ans;
    }
};
