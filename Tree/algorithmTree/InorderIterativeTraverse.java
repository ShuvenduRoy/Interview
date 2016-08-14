package algorithmTree;

import java.util.ArrayList;
import java.util.Stack;

public class InorderIterativeTraverse {
	public ArrayList<Integer> inorderTraversal(Node root) {
	        ArrayList<Integer> list = new ArrayList<>();
	        Stack<Node> s = new Stack<>();
	        Node p = root;
	        
	        while(!s.isEmpty() || p!=null){
	        	if(p!=null){
	        		s.push(p);
	        		p=p.left;
	        	} else {
	        		p=s.peek();
	        		s.pop();
	        		list.add(p.data);
	        		p = p.right;
	        	}
	        }
	        
	        return list;
	    }
}
