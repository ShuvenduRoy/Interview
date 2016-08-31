package subString_Searching;

public class KMP {
	
	private int[] compitePemporaryArray(char pattern[]){
		int [] lps=new int[pattern.length];
		int index=0;
		for(int i=0; i<pattern.length; i++){
			if(pattern[i]==pattern[index]){
				lps[i]=index+1;
				index++;
			}
			else{
				if(index!=0){
					index=lps[index-1];
				}
				else
					lps[i]=0;
			}
		}
		return lps;
	}
	
	public boolean K(char []text, char []pattren){
		int lps[] = compitePemporaryArray(pattren);
		int i=0;
		int j=0;
		while(i<text.length && j<pattren.length){
			if(text[i]==pattren[j]){
				i++;
				j++;
			}
			else{
				if(j!=0)
					j=lps[j-1];
				else
					i++;
			}
		}
		
		return false;
	}

	public static void main(String args[]){
        
        String str = "abcxabcdabcdabcy";
        String subString = "abcdabcy";
        KMP ss = new KMP();
        boolean result = ss.K(str.toCharArray(), subString.toCharArray());
        System.out.print(result);
        
    }
}
