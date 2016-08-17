package algorithmTree;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class LevelOrderTraversal {
	public ArrayList <ArrayList<Integer> > Traverse(Node root){
		ArrayList <ArrayList<Integer> > result = new ArrayList < ArrayList<Integer> >();
		Queue<Node> current = new LinkedList<>();
		Queue<Node> next = new LinkedList<>();
		
		ArrayList<Integer> level = new ArrayList<>();
		
		current.add(root);
		
		while(!current.isEmpty()){
			while(!current.isEmpty()){
				Node node = current.poll();
				level.add(node.data);
				
				if(node.left!=null) next.add(node.left);
				if(node.right!=null) next.add(node.right);
			}
			result.add(level);
			level.clear();
			
			Queue<Node> temp = current;
			current= next;
			next = temp;
			
		}
		return result;
	}
}
