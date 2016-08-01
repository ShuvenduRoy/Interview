package tree;

public class BinarySearchTree {
	public Node addNode(int data, Node head){
		Node n = Node.newNode(data);
		if(head == null){
			head = n;
			return head;
		}
		Node temp = head;
		Node prev = null;
		while(temp!=null){
			prev = temp;
			if(data<temp.data){
				temp=temp.left;
			}
			else{
				temp=temp.right;
			}
		}
		
		if(data<prev.data)
			prev.left = n;
		else
			prev.right = n;
	
		return head;
	}
	
	public Node search(Node root, int key){
		if(root==null)
			return null;
		if(root.data==key){
			return root;
		}else if(root.data<key){
			return search(root.right,key);
		}else{
			return search(root.left,key);
		}
	}
	
	public int height(Node root){
		if(root==null){
			return 0;
		}
		int leftHeight = height(root.left);
		int rightHeight = height(root.right);
		return Math.max(leftHeight, rightHeight) + 1;
	}
	
	public static void main(String args[]){
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
        System.out.println(bt.height(head));
        Node result = bt.search(head, 21);
        System.out.println(result.data == 21);
    }
}
