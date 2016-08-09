package algorithmTree;

public class MorrisInorderTraversal {
	
	public void inorder(Node root){
		Node current = root;
		
		
		while(current!=null){
			if(current.left == null){
				System.out.print(current.data + " ");
				current = current.right;
			}else{
				Node pre  = current.left;
				
				while(pre.right != null  && pre.right!= current){
					pre = pre.right;
				}
				
				if(pre.right == null){
					pre.right = current;
					current = current.left;
				}else{
					pre.right = null;
					System.out.print(current.data + " ");
					current = current.right;
				}
			}
		}
	}
	
	public static void main(String[] args){
		BinarySearchTree bt = new BinarySearchTree();
        Node head = null;
        head = bt.addNode(10, head);
        head = bt.addNode(15, head);
        head = bt.addNode(5, head);
        head = bt.addNode(7, head);
        head = bt.addNode(19, head);
        head = bt.addNode(20, head);
        head = bt.addNode(-1, head);
        head = bt.addNode(21, head);
        
        MorrisInorderTraversal mt = new MorrisInorderTraversal();
        mt.inorder(head);
	}

}
