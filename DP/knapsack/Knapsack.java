package knapsack;


public class Knapsack {
	
	//private static Scanner in;
	int T[][];

	int MaximumVal(int wt[],int val[], int total){
		int l=total;
		int m=val.length;
		T = new int[m+1][l+1];
		
		for (int i=0; i<=m; i++){
			for(int j=0; j<=l; j++){
				if(i==0 || j==0){
					T[i][j]=0;
					continue;
				}
				if(j-wt[i-1] >= 0){
					T[i][j]=Math.max(T[i-1][j], val[i-1]+T[i-1][j-wt[i-1]]);
				}
				else{
					T[i][j]=T[i-1][j];
				}
			}
		}
		return T[m][l];
	}
	
	void PrintPath(int wt[], int val[]){
		int i=T.length-1;
		int j=T[0].length-1;
		while(j!=0){
			if(i>0){
				while(T[i][j]==T[i-1][j]){
					i--;
				}
			}
			System.out.print(wt[i-1]+" ");
			j=j-wt[i-1];
			i--;
		}
	}
	
	
	//Main Function with test case ::
	
	public static void main(String args[]){
		int wt[]={1,3,4,5};
		int val[]={1,4,5,7};
		Knapsack K = new Knapsack();
		
		System.out.print("Enter the total value:  ");
		
		int result = K.MaximumVal(wt,val,7); // pass total
		System.out.println("Total value is "+ result);
		
		K.PrintPath(wt,val);
	} 
}
