# 2023-08-20
class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        if not head or not head.next:
            return True

        def split(head):
            slow = fast = head
            while fast.next and fast.next.next:
                fast = fast.next.next
                slow = slow.next
            l2 = slow.next
            slow.next = None
            return head, l2

        def reverse(head):
            pre, cur = None, head
            while cur:
                tmp = cur.next
                cur.next = pre
                pre, cur = cur, tmp
            return pre

        l1, l2 = split(head)
        l2 = reverse(l2)
        while l1 and l2:
            if l1.val != l2.val:
                return False
            l1, l2 = l1.next, l2.next
        return True
