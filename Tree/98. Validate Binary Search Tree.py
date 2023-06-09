# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:

    def traverseTree(self, root, left, right) -> bool:
        if not root:
            return True
        if root.val <= left or root.val >= right:
            return False
        return self.traverseTree(root.left, left, root.val) and self.traverseTree(root.right, root.val, right)

    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        return self.traverseTree(root, -float('inf'), float('inf'))


s = Solution()
root = TreeNode(2)
root.left = TreeNode(1)
root.right = TreeNode(3)
print(s.isValidBST(root))

# [5,4,6,null,null,3,7]
root = TreeNode(5)
root.left = TreeNode(4)
root.right = TreeNode(6)
root.right.left = TreeNode(3)
root.right.right = TreeNode(7)
print(s.isValidBST(root))
