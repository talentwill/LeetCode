// https://leetcode.com/problems/leaf-similar-trees

// 2024-02-13
class Solution {
public:
    vector<int> v1, v2;
    bool leafSimilar(TreeNode* root1, TreeNode* root2) { return dfs(root1, v1) == dfs(root2, v2); }
    vector<int> dfs(TreeNode* root, vector<int>& v) {
        if (root != nullptr) {
            if (root->left == nullptr and root->right == nullptr) {
                v.push_back(root->val);
            }
            dfs(root->left, v);
            dfs(root->right, v);
        }
        return v;
    }
};
