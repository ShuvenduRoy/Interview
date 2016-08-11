package algorithmTree;

public class SortedArrayToBST {
	public Node sortedArrayToBST(int[] nums) {
	        if(nums == null || nums.length == 0){
	        	return null;
	        }
	        return helper(nums, 0, nums.length-1);
    	}
	
	Node helper(int[]nums, int left, int right){
		if(left>right)
			return null;
		
		int mid = (left+right)/2;
		Node root = new Node(nums[mid]);
		
		root.left = helper(nums,left,mid-1);
		root.right = helper(nums, mid+1, right);
		
		return root;
	}
	
	public static void main(String []args){
		int nums[] = {1,2,3,4,5,6,7};
		SortedArrayToBST sb = new SortedArrayToBST();
		Node root = sb.sortedArrayToBST(nums);
		
		MorrisPreOrder mp = new MorrisPreOrder();
		mp.PreOrder(root);
	}

}
