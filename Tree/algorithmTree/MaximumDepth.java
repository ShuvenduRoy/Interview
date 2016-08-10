package algorithmTree;

public class MaximumDepth {
	public int Height(Node root){
		if (root == null)
			return 0;
		if(root.left == null && root.right == null)
			return root.height;
		
		
		if(root.left == null){
			root.height = Height(root.right) + 1;
		} else if (root.right == null){
			root.height = Height(root.left) +1;
		} else {
			root.height = Math.max(Height(root.left), Height(root.right) ) + 1;
		}
		return root.height;
	}
}
