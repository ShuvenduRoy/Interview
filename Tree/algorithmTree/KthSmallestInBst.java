package algorithmTree;

public class KthSmallestInBst {
    public int kthSmallest(Node root, int k) {
    	int count = 0;
    	
    	Node current = root;
        
        while(current != null){
        	if(current.left == null){
        		count++;
        		if(count==k)
        			return current.data;
        		current = current.right;
        	}else{
        		Node pre = current.left;
        		while(pre.right!=null && pre.right!=current)
        			pre = pre.right;
        		
        		if(pre.right == null){
        			pre.right = current;
        			current = current.left;
        		}else{
        			pre.right = null;
        			count++;
        			if(count == k)
        				return current.data;
        			
        			current = current.right;
        		}
        	}
        }
        return -1;
    }
    
    public static void main(String [] args){
    	KthSmallestInBst mt = new KthSmallestInBst();
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
        int ans = mt.kthSmallest(head, 2);
        System.out.println(ans);
    }
}