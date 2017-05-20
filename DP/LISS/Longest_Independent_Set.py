class Node:
    def __init__(self, a):
        self.val = a
        self.liss = None
        self.left = None
        self.right = None


def LISS(root):
    if root == None:
        return 0

    if root.liss:
        return root.liss

    if root.left == None and root.right == None:
        root.liss = 1
        return 1

    liss_excl = LISS(root.right) + LISS(root.left)

    liss_incl = 1
    if root.left:
        liss_incl += LISS(root.left.left) + LISS(root.left.right)
    if root.right:
        liss_incl += LISS(root.right.left) + LISS(root.right.right)

    root.liss = max(liss_incl, liss_excl)
    return root.liss


root = Node(20)
root.left = Node(8)
root.left.left = Node(4)
root.left.right = Node(12)
root.left.right.left = Node(10)
root.left.right.right = Node(14)
root.right = Node(22)
root.right.right = Node(25)

print(LISS(root))
