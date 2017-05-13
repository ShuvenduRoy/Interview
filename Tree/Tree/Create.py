class Node:
    val = None
    LeftNode = None
    RightNode = None

    def __init__(self, val):
        self.val = val


class BST:
    def __init__(self):
        self.root = None

    def create(self, arr):
        for val in arr:
            if self.root == None:
                self.root = Node(val)

            else:
                current = self.root

                while 1:
                    if val<current.val:
                        if current.LeftNode:
                            current = current.LeftNode
                        else:
                            current.LeftNode = Node(val)
                            break;

                    else:
                        if current.RightNode:
                            current = current.RightNode
                        else:
                            current.RightNode = Node(val)
                            break;


arr = [4,3]
bst = BST()
bst.create(arr)
