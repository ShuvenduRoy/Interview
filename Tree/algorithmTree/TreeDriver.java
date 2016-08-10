package algorithmTree;

public class TreeDriver {

	public static void main(String[] args) {
		// Tree Constructor
		BinarySearchTree bt = new BinarySearchTree();
        Node root = null;
        root = bt.addNode(10, root);
        root = bt.addNode(15, root);
        root = bt.addNode(5, root);
        root = bt.addNode(7, root);
        root = bt.addNode(19, root);
        root = bt.addNode(20, root);
        root = bt.addNode(-1, root);
        root = bt.addNode(21, root);
        
        //Call the Derived Function
        
        MaximumDepth tree = new MaximumDepth();
        System.out.println(tree.Height(root));

	}

}
