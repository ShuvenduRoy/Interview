package algorithmTree;


import java.util.ArrayList;

public class UniqueBSTprint {
	public ArrayList<Node> tree(int n){
		return helper(1,n);
	}
	
	private ArrayList<Node> helper(int left, int right){
		ArrayList<Node> res = new ArrayList<>();
		
		if(left>right){
			res.add(null);
			return res;
		}
		
		for(int i=left; i<=right; i++){
			ArrayList<Node> leftTree = helper(left, i-1);
			ArrayList<Node> rightTree = helper(i+1, right);
			for(int j=0; j<leftTree.size(); j++){
				for(int k=0; k<rightTree.size(); k++){
					Node root = new Node(i);
					root.left = leftTree.get(j);
					root.right = rightTree.get(k);
					res.add(root);
				}
			}
		}
		
		return res;
	}
}
