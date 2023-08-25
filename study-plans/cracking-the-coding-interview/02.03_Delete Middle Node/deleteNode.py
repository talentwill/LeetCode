# 2023-08-19
class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        fast = slow = head
        while fast:
            if not fast.next:
                return None
            slow = slow.next
            fast = fast.next.next
            if slow == fast:
                while head != slow:
                    head = head.next
                    slow = slow.next
                return slow
        return None