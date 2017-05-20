package subsetSum;

/*
 * Author: Shuvendu Roy Bikash
 * Date: 10 july 2016
 * The problem is on SubsetSum dynamic programming
 * The explanation is on the link  https://www.youtube.com/watch?v=s6FhG--P7z0&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=4
 */

public class SubsetSum {

    public boolean subsetSum(int input[], int n){
    	int m=input.length;
    	boolean table[][]=new boolean[m+1][n+1];
    	
    	for(int i=0; i<=m; i++)
    		table[i][0]=true;
    	
    	for(int i=1; i<=m; i++){
    		for(int j=1; j<=n; j++){
    			if(j<input[i-1])
    				table[i][j]=table[i-1][j];
    			else
    				table[i][j]=table[i-1][j] || table[i-1][j-input[i-1]];
    		}
    	}
    	
    	return table[m][n];
    }

    
    public static void main(String args[]) {
        SubsetSum ss = new SubsetSum();

        int arr1[] = {2, 3, 7, 8};
        System.out.print(ss.subsetSum(arr1, 11));
    }
}