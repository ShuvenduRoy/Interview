from Tree.BST.Create import BST,Node


def size(node):
    if node is None:
        return 0
    else:
        return 1 + size(node.LeftNode) + size(node.RightNode)

arr = [8,3,1,6,4,7,10,14,13]
bst = BST()
bst.create(arr)
print(size(bst.root))