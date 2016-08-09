package algorithmTree;

public class TreeDriver {

	public static void main(String[] args) {
		// Tree Constructor
		BinarySearchTree bt = new BinarySearchTree();
        Node head = null;
        head = bt.addNode(10, head);
        head = bt.addNode(15, head);
        head = bt.addNode(5, head);
        head = bt.addNode(7, head);
        head = bt.addNode(19, head);
        head = bt.addNode(20, head);
        head = bt.addNode(-1, head);
        head = bt.addNode(21, head);
        
        //Call the Derived Function
        MorrisPreOrder  mt = new MorrisPreOrder();
        mt.PreOrder(head);

	}

}
