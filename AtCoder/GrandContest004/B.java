package GrandContest004;
//Verdict: TIme limit exceed
import java.util.Arrays;

import java.util.Scanner;

public class B {

	public static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int x = sc.nextInt();
		
		int []a = new int[n];
		int []b = new int[n];
		
		for(int i=0; i<n; i++){
			a[i] = sc.nextInt();
			b[i] = a[i];
		}
		Arrays.sort(b);
		
		int ans = Integer.MAX_VALUE;
		int temp = 0;
		for(int k=0; k<n; k++){
			for(int i=0; i<n; i++){
				temp = k*x + b[0]*k;
				for(int j=0; j<n-k; j++){
					temp+=b[(i+j)%n];
				}
				ans = Math.min(ans, temp);
			}
		}
		
		System.out.println(ans);
	}

}
