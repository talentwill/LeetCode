# 2023-08-20
class Solution:
    def kthToLast(self, head: ListNode, k: int) -> int:
        fast = slow = head
        for _ in range(k):
            fast = fast.next
        while fast:
            fast = fast.next
            slow = slow.next
        return slow.val