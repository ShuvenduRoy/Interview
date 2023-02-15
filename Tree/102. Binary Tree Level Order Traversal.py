from typing import Optional, List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def travelTree(self, root: Optional[TreeNode], level: int):
        if root is None:
            return
        if level not in self.values:
            self.values[level] = []
        self.values[level].append(root.val)
        self.travelTree(root.left, level + 1)
        self.travelTree(root.right, level + 1)

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.values ={}
        self.travelTree(root, 0)
        return list(self.values.values())