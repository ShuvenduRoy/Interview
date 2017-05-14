from Tree.BST.Create import BST, Node

def IsBST(node):
    if node == None:
        return True

    if node.LeftNode and node.LeftNode.val > node.val:
        return False

    if node.RightNode and node.RightNode.val< node.val:
        return False

    return IsBST(node.LeftNode) and IsBST(node.RightNode)

bst = BST()
bst.SampleBST()

print(IsBST(bst.root))