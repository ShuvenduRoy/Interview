package GrandContest005;

import java.util.Scanner;

public class A {
	static Scanner sc;
	
	

	public static void main(String[] args) {
		
		String x;
		sc = new Scanner(System.in);
		

		x = sc.next();
		long n = x.length();
		char[] X = x.toCharArray();
		long len= n;
		
		for(long i=0; i<n-1; i++){
			if(X[(int) i]=='S' && X[(int) (i+1)]=='T'){
				len-=2;
				long j=i;
				
				while(j-1>=0 && X[(int) (j-1)]=='S'){
					if(X[(int) (i+2)]=='T'){
						i++;
						j--;
						len-=2;
					} else {
						break;
					}
				}

			}
		}
		
		System.out.println(len);

	}

}
