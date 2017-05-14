from Tree.BST.Create import BST, Node


def InOrder(node):
    current = node

    while current!= None:
        if current.LeftNode == None:
            print(current.val, end=" ")
            current= current.RightNode

        else:
            predecessor = current.LeftNode

            while predecessor.RightNode != None and predecessor.RightNode != current:
                predecessor = predecessor.RightNode

            if predecessor.RightNode ==  None:
                predecessor.RightNode = current
                current = current.LeftNode

            else:
                predecessor.RightNode == None
                print(current.val, end=" ")
                current = current.RightNode

bst = BST()
bst.SampleBST()
InOrder(bst.root)