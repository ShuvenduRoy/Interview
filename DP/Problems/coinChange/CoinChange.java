package coinChange;


/**
 * @author Shuvendu Roy Bikash
 * Time complexity - O(coins.size * total)
 * Space complexity - O(coins.size * total)
 */

public class CoinChange {
	
	void printCoinCombination(int R[], int coins[]){
		if (R[R.length - 1] == -1) {
            System.out.print("No solution is possible");
            return;
        }
        int start = R.length - 1;
        System.out.print("Coins used to form total ");
        while ( start != 0 ) {
            int j = R[start];
            System.out.print(coins[j] + " ");
            start = start - coins[j];
        }
        System.out.print("\n");
	}
	
	public void minCoin(int coins[], int total){
		int T[] = new int [total+1];
		int R[] = new int [total+1];
		
		T[0]=0;
		for(int i=1; i<=total; i++){
			T[i]=Integer.MAX_VALUE-1;
			R[i]=-1;
		}
		
		for(int j=0; j<coins.length; j++){
			for(int i=1; i<=total; i++){
				if(i>=coins[j]){
					if(T[i-coins[j]]+1<T[i]){
						T[i]=1+T[i-coins[j]];
						R[i]=j;
					}
				}
			}
		}
		
		System.out.println("Total required coin number is "+T[total]);
		printCoinCombination(R,coins);
	}
	
	
	public static void main ( String args[] ) {
	     int total = 13;
	     int coins[] = {7, 3, 2, 6};
	        
	     CoinChange cc = new CoinChange();
	     cc.minCoin(coins, total);
	  }
	 
}
