package algorithmTree;

import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

public class ZigZagLevelOrderTraversal {
	public ArrayList<ArrayList<Integer>> Traversal(Node root){
		ArrayList<ArrayList<Integer>> result = new ArrayList<ArrayList<Integer>>();
		boolean leftToRight = true;
		Queue<Node> Q = new LinkedList<>();
		ArrayList<Integer> level = new ArrayList<>();
		
		
		Q.add(root);
		Q.add(null);
		
		while(!Q.isEmpty()){
			Node curr = Q.poll();
			if(curr != null){
				level.add(curr.data);
				if(curr.left!=null) Q.add(curr.left);
				if(curr.right!=null) Q.add(curr.right);
			} else {
				if(leftToRight){
					result.add(level);
				} else {
					Collections.reverse(level);
					result.add(level);
					
					level.clear();
					leftToRight = !leftToRight;
					if(Q.size()>0){
						Q.add(null);
					}
				}
			}
		}
		return result;
	}
}
