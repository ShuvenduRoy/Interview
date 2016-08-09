package algorithmTree;

public class MorrisPreOrder {
	void PreOrder(Node root){
		if(root== null)
			return;
		
		Node current = root;
		while(current != null){
			if(current.left == null){
				System.out.print(current.data+" ");
				current = current.right;
			} else {
				Node Pre = current.left;
				while(Pre.right != null && Pre.right!=current){
					Pre = Pre.right;
				}
				
				if(Pre.right == null){
					Pre.right = current;
					System.out.print(current.data+" ");
					current = current.left;
				} else {
					Pre.right = null;
					current = current.right;
				}
			}
		}
	}
}
