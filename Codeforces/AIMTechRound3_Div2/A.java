package AIMTechRound3_Div2;

import java.util.Scanner;

public class A {

	private static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int n, b, d;
		n = sc.nextInt();
		b = sc.nextInt();
		d = sc.nextInt();
	    int now = 0, cnt = 0;
	    for(int i = 1; i <= n; ++ i) {
	        int x;
	        x = sc.nextInt();
	        if(x > b) continue;
	        now += x;
	        if(now > d) {
	            ++ cnt;
	            now = 0;
	        }
	    }
	    System.out.println(cnt);
	}
}
