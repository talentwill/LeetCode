# 2023-09-12
class Solution:
    def convertBiNode(self, root: TreeNode) -> TreeNode:
        head = pre = None

        def dfs(node):
            nonlocal pre, head
            if node:
                dfs(node.left)
                # 中序遍历的第一个节点设置head
                if head is None:
                    head = node
                else:
                    # 既然已经设置过head,
                    # 那么pre必然不为空
                    pre.right = node
                    node.left = None
                pre = node
                dfs(node.right)
        dfs(root)
        return head
