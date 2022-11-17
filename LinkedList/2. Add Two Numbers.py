# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        dummy_head = ListNode()
        head = dummy_head
        carry = 0
        while l1 or l2 or carry!=0:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            sum = v1 + v2 + carry
            head.next = ListNode(sum % 10)
            head = head.next
            carry = sum // 10
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummy_head.next


s = Solution()
l1 = ListNode(2)
l1.next = ListNode(4)
l1.next.next = ListNode(3)
l2 = ListNode(5)
l2.next = ListNode(6)
l2.next.next = ListNode(4)
print(s.addTwoNumbers(l1, l2))