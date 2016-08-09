package algorithmTree;

public class LowestCommonAncestorBinarySearchTree {
	
	public Node lca(Node root, int p, int q){
		if(root.data > Math.max(p,q)){
			return lca(root.left,p,q); 
		}else if(root.data < Math.min(p, q)){
			return lca(root.right,p,q);
		} else{
			return root;
		}	
	}
}
