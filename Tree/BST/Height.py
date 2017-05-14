from Tree.BST.Create import BST,Node


def Height(node):
    if node is None:
        return 0
    else:
        return 1 + max(Height(node.LeftNode), Height(node.RightNode))

arr = [8,3,1,6,4,7,10,14,13]
bst = BST()
bst.create(arr)
print(Height(bst.root))