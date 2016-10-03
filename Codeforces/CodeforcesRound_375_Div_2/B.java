package CodeforcesRound_375_Div_2;

import java.util.Scanner;

public class B {
	
	static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		String s = sc.next();
		s = sc.next();
		int n = s.length();
		
		char[] str = s.toCharArray();
		
		
		int maxLength = 0;
		int numOfWord = 0;
		int currLen = 0;
		
		for(int i=0; i<n; i++){
			
			if(str[i]=='_' || str[i]=='('){
				if(currLen>maxLength){
					maxLength = currLen;
				}
				currLen = 0;
			} else {
				currLen++;
			}
			
			if(str[i]=='('){
				int l=0;
				for(int j=i+1; j<n; j++,i++){
					if(str[j]==')'){
						if(l>0){
							numOfWord++;
							l=0;
						}
						i++;
						break;
					}
						
					
					if(str[j]=='_' || str[j]==')'){
						if(l>0){
							numOfWord++;
						}
						
						l=0;
					} else {
						l++;
					}
					
				}
			}
			
		}

		if(currLen>maxLength)
			maxLength=currLen;
		
		System.out.println(maxLength+" "+numOfWord);
	}

}
