# 2023-08-20
class Solution:
    def removeDuplicateNodes(self, head: ListNode) -> ListNode:

        # 从头遍历，找到重复的元素
        def isDup(head, node) -> bool:
            while head != node:
                if head.val == node.val:
                    return True
                head = head.next
            return False

        pre, cur = None, head
        while cur:
            if isDup(head, cur):
                # 删除掉当前的元素，因为当前元素已经存在
                pre.next = cur.next
                cur = cur.next
            else:
                pre, cur = cur, cur.next

        return head
