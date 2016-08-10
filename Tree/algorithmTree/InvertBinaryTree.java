package algorithmTree;

import java.util.LinkedList;
import java.util.Queue;

public class InvertBinaryTree {
	public Node Invert(Node root){
		if(root == null){
			return root;
		}
		
		Queue<Node> queue = new LinkedList<>();
		queue.add(root);
		
		while(!queue.isEmpty()){
			Node node = queue.poll();
			Node left = node.left;
			node.left = node.right;
			node.right = left;
			
			if(node.left!=null){
				queue.add(node.left);
			}
			if(node.right!=null){
				queue.add(node.right);
			}
		}
		
		return root;
	}
}
