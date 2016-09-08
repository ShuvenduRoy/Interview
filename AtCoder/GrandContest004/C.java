//Wrong Answer

package GrandContest004;

import java.util.Scanner;

public class C {
	public static Scanner sc;
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int m = sc.nextInt();
		int n = sc.nextInt();
		
		char [][]z = new char[m][n];
		char [][]x = new char[m][n];
		char [][]y = new char[m][n];
		
		for(int i=0; i<n; i++){
			for(int j=0; j<n; j++){
				x[i][j]=y[i][j]='.';
			}
		}
		
		int r2=0,r1=0,c2=0,c1=0;
		
		for(int i=0; i<m; i++){
			String s = sc.next();
			for(int j=0; j<n; j++){
				z[i][j] = s.charAt(j);
				
				
				if(z[i][j]=='#'){
					x[i][j]='#';
					y[i][j]='#';
					
					if(r1==0){
						r1=i;
					}
					if(c1==0){
						c1=j;
					}
					if(i>r2)
						r2=i;
					if(j>c2){
						c2=j;
					}
				}
				
			}
		}
		
		
		
		
		for(int i=r1; i<=r2; i++){
			x[i][0] = '#';
		}

		
		
		int temp = 0;
		for(int i=r1; i<=r2; i++){
			for(int j=0; j<n; j++){
				if(x[i][j]=='#' && j>temp){
					temp = j;
				}
			}
			for(int j=0; j<temp; j++){
				x[i][j]='#';
			}
		}
				
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				System.out.print(x[i][j]);
			}
			System.out.println();
		}
		System.out.println();
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				System.out.print(y[i][j]);
			}
			System.out.println();
		}
		
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(x[i][j] == '.'){
					y[i][j]='#';
				}
			}
		}

		
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				System.out.print(x[i][j]);
			}
			System.out.println();
		}
		System.out.println();
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				System.out.print(y[i][j]);
			}
			System.out.println();
		}
	}

}
