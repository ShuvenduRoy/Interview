package CodeforcesRound_369_Div2;

import java.util.Scanner;

public class B {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int n = sc.nextInt();
		boolean flag = true;
		
		
		
		long [][] table = new long[n][n];
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				table[i][j] = sc.nextInt();
			}
		}
		
		int j;
		long ans=0;
		long total = 0;
		int problem_row=0;
		int problem_col=0;
		for(int i=0; i<n; i++){
			total = 0;
			for(j=0; j<n; j++){
				if(table[i][j] == 0){
					problem_row = i;
					problem_col = j;
					break;
				} else {
					total+=table[i][j];
				}
			}
			if (j==n){
				ans = Math.max(ans,total);
			}
				
		}
		
		long sum = 0;
		for(int i=0; i<n; i++){
			sum+=table[problem_row][i];
		}
			
		long a = (ans-sum);
		table[problem_row][problem_col] = a;
		if(a<=0)
			flag=false;
		
		long row,col;
		for(int i=0; i<n; i++){
			row=0;
			for(j=0; j<n; j++){
				row+=table[i][j];
			}
			if(row!=ans){
				flag = false;
			}
		}
		
		for(int i=0; i<n; i++){
			col=0;
			for(j=0; j<n; j++){
				col+=table[j][i];
			}
			if(col!=ans){
				flag = false;
			}
		}
		
		col=0;
		for(j=0; j<n; j++){
			col+=table[j][j];
		}
		if(col!=ans){
			flag = false;
		}
		
		col=0;
		for(j=0; j<n; j++){
			col+=table[j][n-j-1];
		}
		if(col!=ans){
			flag = false;
		}
		
		if(n==1){
			System.out.println("1");
		}
		else if(flag){
			System.out.println(a);
		}else{
			System.out.println("-1");
		}
	}
}
