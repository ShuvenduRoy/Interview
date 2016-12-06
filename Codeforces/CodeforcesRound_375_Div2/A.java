package CodeforcesRound_375_Div_2;

import java.util.Scanner;

public class A {
	static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		
		int minVal = Math.min(a, Math.min(c, b));
		int maxVal = Math.max(a, Math.max(c, b));
		
		System.out.println(maxVal-minVal);

	}

}
