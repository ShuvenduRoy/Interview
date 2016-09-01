package CodeforcesRound_369_Div2;

import java.util.Scanner;

public class C {
	public static Scanner sc;
	
	public static void main(String[] args) {
		int trees,colors,beauty;
		sc = new Scanner(System.in);
		trees=sc.nextInt();
		colors=sc.nextInt();
		beauty=sc.nextInt();
		
		int[] color = new int[trees+1];
		for(int i=1; i<=trees ;i++){
			color[i] = sc.nextInt();
		}
		
		
		long [][] cost = new long[trees+1][colors+1];
		for(int i=1; i<=trees; i++){
			for(int j=1; j<=colors; j++){
				cost[i][j] = sc.nextInt();
			}
		}
		
		
		
		long [][][]dp = new long[trees+1][beauty+1][colors+1];
		
		int i,j,k;
		for(i=0; i<=trees; i++){
			for(j=0; j<=beauty; j++){
				for(k=0; k<=colors; k++){
					dp[i][j][k] = Long.MAX_VALUE-Integer.MAX_VALUE;
				}
			}
		}
		
		
		//Setting the base condition
		if(color[1] == 0){
			for(i=1; i<=colors; i++){
				dp[1][1][i] = cost[1][i];
			}
		} else {
			dp[1][1][color[1]] = 0;
		}
		
		
		//Completing the dp table
		for(i=2; i<=trees; i++){
			for(j=1; j<=beauty; j++){
				if(color[i] == 0){
					for(int a=1; a<=colors; a++){
						dp[i][j][a] = Math.min(dp[i][j][a], dp[i-1][j][a]+cost[i][a]);
						for(int b=1; b<=colors; b++){
							if(b!=a){
								dp[i][j][a] = Math.min(dp[i][j][a],  dp[i-1][j-1][b]+cost[i][a]);
							}
						}
					}
				} else {
					dp[i][j][color[i]] = Math.min(dp[i][j][color[i]], dp[i-1][j][color[i]]);
					for(int b = 1; b <= colors; b++)
					{
						if(b != color[i]) dp[i][j][color[i]] = Math.min(dp[i][j][color[i]], dp[i-1][j-1][b]);
					}
				}
			}
		}
		
		long ans = Long.MAX_VALUE-Integer.MAX_VALUE;
		for(i=1; i<=colors ;i++){
			ans = Math.min(ans, dp[trees][beauty][i]);
		}
		if(ans >= Long.MAX_VALUE-Integer.MAX_VALUE) ans = -1;
		
		System.out.println(ans);
		
	}

}