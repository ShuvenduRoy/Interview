package CodeforcesRound_373_Div2;

import java.util.Scanner;

public class Main {
	static Scanner sc;


	public static void main(String[] args) {
		
		sc = new Scanner(System.in);
		
		int n;
		int [] data;
		
		n = sc.nextInt();
		data = new int[n];
		
		for(int i=0; i<n; i++){
			data[i] = sc.nextInt();
		}
		if(n==1){
			
			System.out.println(-1);
			
		} else if(data[n-1] == 15 || data[n-1] < data[n-2]){
			
			System.out.println("DOWN");
			
		} else if(data[n-1] == 0 || data[n-1] > data[n-2]){
			
			System.out.println("UP");
		} 
	}

}
