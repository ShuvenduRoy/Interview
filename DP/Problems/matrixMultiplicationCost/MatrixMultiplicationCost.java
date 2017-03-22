package matrixMultiplicationCost;

public class MatrixMultiplicationCost {
	public int findCost(int arr[]){
		int n=arr.length;
        int table[][]=new int[n][n];
        
        for(int l=2; l<n; l++){
        	for(int i=0; i<n-l; i++){
        		int j=i+l;
        		table[i][j]=Integer.MAX_VALUE;
        		for(int k=i+1; k<j; k++){
        			int q = table[i][k] + table[k][j] + arr[i]*arr[k]*arr[j];
                    if(q < table[i][j]){
                    	table[i][j] = q;
                    }
        		}
        	}
        }
        
        return table[0][n-1];
    }
	
	public static void main(String args[]){
        MatrixMultiplicationCost mmc = new MatrixMultiplicationCost();
        int arr[] = {2,3,6,4,5};
        int cost = mmc.findCost(arr);
        System.out.print(cost);
    }
}
