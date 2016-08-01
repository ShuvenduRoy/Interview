package tree;

public class SameTree extends BinarySearchTree {

	public boolean sameTree(Node root1, Node root2){
		if(root1==null && root2==null){
			return true;
		}else if(root1==null || root2==null){
			return false;
		}else{
			return (root1.data==root2.data && sameTree(root1.left,root2.left) && sameTree(root1.right, root2.right));
		}
	}
	
	public static void main(String[] args) {		
		SameTree bt = new SameTree();
		Node root1 = null;
        root1 = bt.addNode(10, root1);
        root1 = bt.addNode(20, root1);
        root1 = bt.addNode(15, root1);
        root1 = bt.addNode(2, root1);

        Node root2 = null;
        root2 = bt.addNode(10, root2);
        root2 = bt.addNode(20, root2);
        root2 = bt.addNode(15, root2);
        root2 = bt.addNode(2, root2);
        
        System.out.println(bt.sameTree(root1, root2));
	}

}
