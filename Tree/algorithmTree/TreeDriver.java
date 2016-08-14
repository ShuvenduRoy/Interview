package algorithmTree;

import java.util.ArrayList;

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
        System.out.println("The tree height is "+tree.Height(root));

        InorderIterativeTraverse it = new InorderIterativeTraverse();
        ArrayList<Integer> array = it.inorderTraversal(root);
        System.out.println("PreOrder Traversal in iterative way: ");
        for(int i=0; i<array.size(); i++){
        	System.out.print(array.get(i)+ " ");
        }
        
	}

}
