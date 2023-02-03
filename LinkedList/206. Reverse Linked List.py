# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


from typing import Optional


class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        if not head.next:
            return head

        prev_head = head
        head = head.next
        prev_head.next = None
        while head.next:
            head.next, prev_head, head = prev_head, head, head.next
        head.next = prev_head
        return head

    def printList(self, head: Optional[ListNode]):
        while head:
            print(head.val, end=' ')
            head = head.next
        print()


s = Solution()
head = ListNode(1, ListNode(2, ListNode(3, ListNode(4, ListNode(5)))))
s.printList(head)
head = s.reverseList(head)
s.printList(head)

s = Solution()
head = ListNode(1, ListNode(2))
s.printList(head)
head = s.reverseList(head)
s.printList(head)

s = Solution()
head = ListNode(1)
s.printList(head)
head = s.reverseList(head)
s.printList(head)

s = Solution()
head = None
s.printList(head)
head = s.reverseList(head)
s.printList(head)
