class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def isBalanced(self, root):
        """
        :type root: TreeNode
        :rtype: bool
        """
        def dfs(root):
            if not root:
                return True, 0
            left, left_depth = dfs(root.left)
            right, right_depth = dfs(root.right)
            max_depth = max(left_depth, right_depth) + 1
            return left and right and abs(left_depth - right_depth) <= 1, max_depth
        return dfs(root)[0]