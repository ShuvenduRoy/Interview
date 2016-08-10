package algorithmTree;

public class UniqueBST {
	public int[] dp;
	
	public int tree(int n){
		if(n<=1)
			return 1;
		if(dp[n]!= 0)
			return dp[n];
		
		int total =0;
		for(int i=0; i<n; i++){
			total += tree(i) * tree(n-i-1);
		}
		return total;
	}
	
	public int numTrees(int n){
		dp = new int[n+1];
		return tree(n);
	}
	
	public static void main(String []args){
		UniqueBST ut = new UniqueBST();
		System.out.println(ut.numTrees(5));
	}
}
