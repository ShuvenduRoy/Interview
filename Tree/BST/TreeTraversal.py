from Tree.BST.Create import BST,Node


def InOrder(node):
    if node is not None:
        InOrder(node.LeftNode)
        print(node.val, end=" ")
        InOrder(node.RightNode)


def preorder(node):
    if node is not None:
        print(node.val, end=" ")
        preorder(node.LeftNode)
        preorder(node.RightNode)


def postorder(node):
    if node is not None:
        postorder(node.LeftNode)
        postorder(node.RightNode)
        print(node.val, end=" ")

arr = [8,3,1,6,4,7,10,14,13]
bst = BST()
bst.create(arr)

print("In Order traversal : ")
InOrder(bst.root)

print("\nPre Order traversal : ")
preorder(bst.root)

print("\nPost Order traversal : ")
postorder(bst.root)