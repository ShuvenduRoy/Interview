from queue import Queue

from Tree.BST.Create import BST, Node

def LevelOrder(node):
    q = Queue()
    q.put(node)

    while q.qsize() >0:
        node = q.get()
        print(node.val)

        if node.LeftNode != None:
            q.put(node.LeftNode)

        if node.RightNode != None:
            q.put(node.RightNode)

bst = BST()
bst.SampleBST()
LevelOrder(bst.root)