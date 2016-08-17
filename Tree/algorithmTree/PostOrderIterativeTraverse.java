package algorithmTree;

//LeetCode 145

import java.util.ArrayList;
import java.util.Stack;

public class PostOrderIterativeTraverse {
	public ArrayList<Integer> PostOrder(Node root){
		ArrayList<Integer> result = new ArrayList<>();
		Stack<Node> S = new Stack<>();
		
		Node p = root;
		Node q = null;
		do{
			while(p!=null){
				S.push(p);
				p=p.left;
			}
				
			
			q=null;
			while(!S.empty()){
				
				p = S.peek();
				S.pop();
				
				if(p.right == q){
					result.add(p.data);
					q=p;
				} else {
					S.push(p);
					p = p.right;
					break;
				}
			}
		} while(!S.empty());
		
		return result;
	}
}
