# 2023-08-19
class Solution:
    def partition(self, head: ListNode, x: int) -> ListNode:
        if not head: return None
        l1 = t1 = ListNode(0) # 前半分区的头、尾指针
        l2 = t2 = ListNode(0) # 后半分区的头、尾指针
        while head:
            tmp = head.next
            if head.val < x:
                # 前半分区的尾插法
                head.next = t1.next
                t1.next = head
                t1 = head
            else:
                # 后半分区的尾插法
                head.next = t2.next
                t2.next = head
                t2 = head
            head = tmp
        t1.next = l2.next # 合并两条链表
        return l1.next
        