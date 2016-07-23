package AVL_Tree;

class Node{
    Node left;
    Node right;
    Node next;
    int data;
    int lis;
    int height;
    int size;
    
    public static Node newNode(int data){
        Node n = new Node();
        n.left = null;
        n.right = null;
        n.data = data;
        n.lis = -1;
        n.height = 1;
        n.size = 1;
        return n;
    }
}

class TreeTraverse
{
	public void inOrder(Node root)
	{
		if(root==null)
			return;
		System.out.print(root.data+" ");
		inOrder(root.left);
		inOrder(root.right);
	}
	
	public void preOrder(Node root)
	{
		if(root==null)
			return;
		preOrder(root.left);
		System.out.print(root.data+" ");
		inOrder(root.right);
	}
	
	public void postOrder(Node root)
	{
		if(root==null)
			return;
		
		inOrder(root.left);
		inOrder(root.right);
		System.out.print(root.data+" ");
	}
}
