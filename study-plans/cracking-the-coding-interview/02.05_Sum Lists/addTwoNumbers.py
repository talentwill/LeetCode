# 2023-08-19
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        flag = 0
        dummy = last = ListNode(0)
        while l1 or l2 or flag:
            val = flag
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            last.next = ListNode(val % 10)
            last = last.next
            flag = val // 10
        return dummy.next
