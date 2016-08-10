package algorithmTree;

public class UniqueBST {
	
	/* 
	 * 
	 * Got TLE in the last input, that is 19
	 * 
	 * 
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
	
	*/
	
	public int numTrees(int n){
		int []dp = new int[n+1];
		dp[0] = dp[1] = 1;
		for(int i=2; i<=n; i++){
			for(int j=0; j<i; j++){
				dp[i]+=dp[j]*dp[i-j-1];
			}
		}
		return dp[n];
	}
	
	public static void main(String []args){
		UniqueBST ut = new UniqueBST();
		System.out.println(ut.numTrees(5));
	}
}
