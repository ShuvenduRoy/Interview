package algorithmTree;

import java.util.List;
import java.util.ArrayList;

public class RootToLeatSum extends BinarySearchTree{
	public boolean printPath(Node root, int sum, List<Node> path){
		if(root==null)
			return false;
		
		if(root.left==null && root.right==null){
			if(root.data==sum){
				path.add(root);
				return true;
			}else{
				return false;
			}
		}
		if(printPath(root.left, sum-root.data, path) || printPath(root.right, sum-root.data, path)){
			path.add(root);
			return true;
		}
		return false;
	}

	public static void main(String[] args) {
		RootToLeatSum bt = new RootToLeatSum();
        Node head = null;
        head = bt.addNode(10, head);
        head = bt.addNode(15, head);
        head = bt.addNode(5, head);
        head = bt.addNode(7, head);
        head = bt.addNode(19, head);
        head = bt.addNode(20, head);
        head = bt.addNode(-1, head);
        head = bt.addNode(21, head);
        List<Node> result = new ArrayList<>();
        boolean r = bt.printPath(head, 22, result);
        if(r){
        	result.forEach(node -> System.out.print(node.data+" "));
        }else{
        	System.out.println("There is no path for sum 22");
        }
	}

}
