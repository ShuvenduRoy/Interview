package AIMTechRound3_Div2;

import java.util.Arrays;
import java.util.Scanner;

public class B {
	private static Scanner sc;

	int fun(int x,int y,int z){
	    if(z<=x)return y-z;
	    if(z>=y)return z-x;
	    return Math.min(z-x+y-x,y-z+y-x);
	}


	public static void main(String[] args) {
		int n,a;
		sc = new Scanner(System.in);
		B m = new B();
		
	    try{
	    	while( sc.hasNextInt()){
		    	n = sc.nextInt();
				a = sc.nextInt();
				int [] aa = new int[n];
				
		        for(int i=0;i<n;i++){
		        	aa[i] = sc.nextInt();
		        }
		        Arrays.sort(aa);
		        
		        
		        if(n==1){
		            System.out.println("0");
		            continue;
		        }
		        int ans=Integer.MAX_VALUE;
		        if(a<=aa[0]){
		            ans=Math.min(ans,aa[n-2]-a);
		        }
		        else if(a>=aa[n-1]){
		            ans=Math.min(ans,a-aa[1]);
		        }
		        else {
		            ans=Math.min(ans,m.fun(aa[1],aa[n-1],a));
		            ans=Math.min(ans,m.fun(aa[0],aa[n-2],a));
		        }
		        System.out.println(ans);
		    }
	    }finally{
	        sc.close();
	    }

	}

}
