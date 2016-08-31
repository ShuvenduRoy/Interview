package longestCommonSubsequence;

public class LongestCommonSubsequence {
	
	int lcsDynamic(char str1[], char str2[]){
		int m=str1.length;
		int n=str2.length;
		int Table[][]=new int[str1.length+1][str2.length+1];
		
		for(int i=1; i<=m; i++){
			for(int j=1; j<=n; j++){
				if(str1[i-1]==str2[j-1]){
					Table[i][j]=Table[i-1][j-1]+1;
				}
				else 
					Table[i][j]=Math.max(Table[i-1][j],Table[i][j-1]);
			}
		}
		
		return Table[m][n];
	}
	
	//Main Function to Test
	public static void main(String args[]){
        LongestCommonSubsequence lcs = new LongestCommonSubsequence();
        String str1 = "ABCDGHLQR";
        String str2 = "AEDPHR";
        
        int result = lcs.lcsDynamic(str1.toCharArray(), str2.toCharArray());
        System.out.print(result);
    }
}
