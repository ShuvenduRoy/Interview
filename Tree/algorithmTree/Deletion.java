package algorithmTree;

public class Deletion {
	private int findMin(Node root){
		while(root.left != null)
			root= root.left;
		
		return root.data;
	}
	
	public Node Delete(Node root, int key){
		//Base Condition for null tree
		if(root == null)
			return null;
		
		//Traverse to find the node
		if(key<root.data){
			root.left = Delete(root.left,key);
		} else if(key>root.data){
			root.right = Delete(root.right,key);
		} else if(root.data == key){
			//Now we have to check the tree condition
			// Condition 1&2 : if the ndoe has one or no child
			
			if(root.left == null){
				return root.right; //It handles even if the root node has to be deleted, we return the entire right tree when left is empty
			} else if (root.right == null){
				return root.left;
			}
			
			//Else condition is tree has both left and right child, this is the hardest part
			
			else{
				/**
				 * We have two alternate
				 * Finding the minimum is the right subtree
				 * or finding the maximum in left subtree
				 * lets do the 1st one
				 */
				int min = findMin(root.right);
				
				//Now we have minimum in right sub tree, replace it with current root data, and call delete again to delete the duplicate just created
				root.data = min;
				root.right = Delete(root.right, min);
			}

		} 
		return root;
	}
}
