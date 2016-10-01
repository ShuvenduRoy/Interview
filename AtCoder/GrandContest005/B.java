package GrandContest005;

import java.util.Scanner;

public class B {
	static Scanner sc;


	public static void main(String[] args) {
		
		int n = sc.nextInt();
		int [] a  = new int[n];
		
		for(int i=0; i<n; i++){
			a[i] = sc.nextInt();
		}
		
		int ans = 0;
		
		for(int l=0; l<n; l++){
			for(int r=l; r<n; r++){
				int min = a[r];
				
				for(int i = l; i<r; i++){
					if(a[i]<min){
						min = a[i];
					}
				}
				
				ans +=min;
			}
		}
		
		System.out.println(ans);
		

	}

}
