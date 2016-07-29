package tree;

enum Color{
	RED,BLACK
}

public class Node {
	Node left;
	Node right;
	Node next;
	int data;
	int lis;
	int height;
	int size;
	Color color;
	
	public Node(int data){
		left = null;
		right = null;
		this.data = data;
		lis = -1;
		height = 1;
		size = 1;
		color = Color.RED;
	}
	
	public static Node newNode(int data){
		Node n = new Node(data);
		return n;
	}
	
}
