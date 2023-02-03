# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        """
        Do not return anything, modify head in-place instead.
        """
        # FIND THE MIDDLE
        slow_head = head
        fast_head = head.next
        while fast_head and fast_head.next:
            slow_head = slow_head.next
            fast_head = fast_head.next.next

        # REVERESE THE SECOND HALD
        prev = None
        curr = slow_head.next
        slow_head.next = None
        while curr:
            temp = curr.next
            curr.next = prev
            prev = curr
            curr = temp

        # MERGE THE TWO HALVES
        first = head
        second = prev
        while second:
            temp = first.next
            first.next = second
            second = second.next
            first.next.next = temp
            first = temp

s = Solution()
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
s.reorderList(head)
while head:
    print(head.val)
    head = head.next

