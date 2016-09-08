package GrandContest004;

import java.util.Scanner;

public class D {
	public static Scanner sc;
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int ans=0;
		int n = sc.nextInt();
		int k = sc.nextInt();
		
		int [] city = new int[n+1];
		int [] rank = new int[n+1];
		for(int i=0; i<=n; i++){
			rank[i]=1;
		}
		
		city[1]= 1;
		rank[1] = 0;
		
		for(int i=1; i<=n; i++){
			city[i] = sc.nextInt();
		}
		
		if(city[1]!=1){
			city[1]=1;
			ans++;
		}
		
		for(int i=1; i<=n; i++){
			rank[i]=rank[city[i]]+1;
			if(rank[i]>k){
				ans++;
				rank[i]=1;
			}
		}
		
		System.out.println(ans);

	}

}
