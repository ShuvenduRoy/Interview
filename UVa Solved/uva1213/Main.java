package uva1213;

/**
 * @author: Shuvendu Roy Bikash
 * Problem: uva 1213
 * Runtime: .140s
 * Prblem link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=24&problem=3654&mosmsg=Submission+received+with+ID+17647306
 */

import java.util.*;
import static java.util.Arrays.*;

/**
 * The idea is simple
 * We need a k(number of prime to add) * n(sum) Matrix
 * for every prime p we will fill the table in bottom up manner
 * Why from right to left? :: Because repeatation of taking any number is not allowed
 * T[j][i] = T[j-1][i-p]
 * Why?? 
 * look what is possible with one less number. this is stored in previous row and see the number-p is possible if that is possible
 * adding p will make the current j possible
 */


public class Main {
	private Scanner in;
	
	private int[][]dp;
	
	Main(){
		this.in = new Scanner(System.in);
	}
	
	void solve(){
		int n,k;
		while((n=in.nextInt())+(k=in.nextInt())>0){
			dp = new int[k+1][n+1];
			dp[0][0]=1;
			
			List<Integer> primes = sieve(n);
			
			for(int p : primes) {
				for(int i=k; i>0; i--){
					for(int j=n; j>=p; j--){
						dp[i][j]+=dp[i-1][j-p];
					}
				}
			}

			System.out.println(dp[k][n]);
		}
	}
	
	public List<Integer> sieve(int n){
		boolean[] p = new boolean[n+1];
		fill(p,true);
		p[0]=p[1]=false;
		
		for(int i=2; i*i<=n; i++){
			if(p[i]){
				for(int j=i+i; j<=n; j+=i){
					p[j]=false;
				}
			}
		}
		
		List<Integer> res = new LinkedList<Integer>();
		for(int i=2; i<=n; i++){
			if(p[i])
				res.add(i);
		}
		
		return res;
	}
	
	public static void main(String[] args){
		Main solver = new Main();
		solver.solve();
	}
}
