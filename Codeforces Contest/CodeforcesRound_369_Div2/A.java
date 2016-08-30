package CodeforcesRound_369_Div2;

import java.util.Scanner;

public class A {
	private static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		String [] seat = new String[n];
		boolean flag = false;
		

		for(int i=0; i<n; i++){
			seat[i]=sc.next();
		}
		
		for(int i=0; i<n; i++){
			char[] c = seat[i].toCharArray();
			if(c[0]=='O' && c[1]=='O'){
				c[0]='+';
				c[1]='+';
				seat[i]= String.copyValueOf(c);
				flag = true;
				break;
			} else if(c[3]=='O' && c[4]=='O'){
				c[3]='+';
				c[4]='+';
				seat[i]= String.copyValueOf(c);
				flag = true;
				break;
			}
			
		}
		
		if(flag==true){
			System.out.println("YES");
			for(int i=0; i<n; i++){
				System.out.println(seat[i]);
			}
		}
			
		else
			System.out.println("NO");

	}
}
