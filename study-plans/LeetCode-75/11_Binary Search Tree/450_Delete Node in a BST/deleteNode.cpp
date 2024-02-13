// https://leetcode.com/problems/delete-node-in-a-bst/

// 2024-02-13
class Solution {
public:
    TreeNode* extractMaxNode(TreeNode* root, TreeNode*& target) {
        if (root->right == nullptr) {
            target = root;
            return root->left;
        }

        TreeNode* pre = nullptr;
        TreeNode* cur = root;
        while (cur->right) {
            pre = cur;
            cur = cur->right;
        }
        // 断开，把最大结点的left接上，很重要
        pre->right = cur->left;
        target = cur;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root) {
            if (root->val == key) {
                if (root->left and root->right) {
                    TreeNode* node;
                    node->left = extractMaxNode(root->left, node);
                    node->right = root->right;
                    return node;
                }
                return root->left ? root->left : root->right;
            } else if (key < root->val) {
                root->left = deleteNode(root->left, key);
            } else {
                root->right = deleteNode(root->right, key);
            }
        }
        return root;
    }
};