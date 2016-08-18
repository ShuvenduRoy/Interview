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
        ArrayList<Integer>array = it.inorderTraversal(root);
        System.out.println("Post Traversal in iterative way: ");
        for(int i=0; i<array.size(); i++){
        	System.out.print(array.get(i)+ " ");
        }
        
        Deletion dt = new Deletion();
        root = dt.Delete(root, 19);
        
        array = it.inorderTraversal(root);
        System.out.println("\nPost Traversal in iterative way After deletion: ");
        for(int i=0; i<array.size(); i++){
        	System.out.print(array.get(i)+ " ");
        }
        
        ZigZagLevelOrderTraversal zt = new ZigZagLevelOrderTraversal();
        ArrayList<ArrayList<Integer>> arr = zt.Traversal(root);
        System.out.println("\nZigZag traversal:  ");
        for(int i=0; i<arr.size(); i++){
        	for(int j=0; j<arr.get(i).size(); j++){
        		System.out.print(arr.get(i).get(j) + " ");
        	}
        }
	}

}
