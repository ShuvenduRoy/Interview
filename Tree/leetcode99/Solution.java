package leetcode99;

import algorithmTree.*;

public class Solution {
	TreeNode node1 = null;
	TreeNode node2 = null;
	TreeNode Pre = null;
	
	public void helper(TreeNode root){
		if(root == null)
			return;
		
		helper(root.left);
		
		if(Pre!=null && Pre.val>root.val){
			if(node1 == null){
				node1 = Pre;
			}
			node2 = root;
		}
		
		Pre = root;
		helper(root.right);
	}
	
	public void recoverTree(TreeNode root){
		if(root ==null){
			return;
		}
		
		helper(root);
		
		if(node1!=null && node2!=null){
			TreeNode temp  = node1;
			node1=node2;
			node2= temp;
		}
	}
}
