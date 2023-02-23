class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def travelTree(self, root: TreeNode, max_sofar:int):
        if root is None:
            return
        if root.val >= max_sofar:
            self.count += 1
        self.travelTree(root.left, max(max_sofar, root.val))
        self.travelTree(root.right, max(max_sofar, root.val))

    def goodNodes(self, root: TreeNode) -> int:
        self.count = 0
        self.travelTree(root, root.val)
        return self.count