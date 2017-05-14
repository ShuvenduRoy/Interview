from Tree.BST.Create import BST,Node


def Sum(node, sum):
    if node.LeftNode==None and node.RightNode==None:
        if sum==node.val:
            return True
        else:
            return False

    if sum==0:
        return True

    elif node.LeftNode == None:
        return Sum(node.RightNode, sum-node.val)

    elif node.RightNode == None:
        return Sum(node.LeftNode, sum-node.val)

    else:
        return Sum(node.LeftNode, sum-node.val) or Sum(node.RightNode, sum-node.val)

bst = BST()
bst.SampleBST()

print(Sum(bst.root, 12))
