package combination;
import java.util.*;

public class Combination {
	
	public void combination(char input[]){
		Map<Character, Integer> countMap = new TreeMap<>();
		
		//Calculating number of occarance in the array
		for(char ch : input){
			countMap.compute(ch, (key,val)->{
				if(val == null){
					return 1;
				}else{
					return val+1;
				}
			});
		}
		
		char str[] = new char[countMap.size()];
		int count[] = new int[countMap.size()];
		int index = 0;
		
		for(Map.Entry<Character, Integer> entry : countMap.entrySet()){
			str[index] = entry.getKey();
			count[index] = entry.getValue();
			index++;
		}
		
		char[] output = new char[input.length];
		combination(str, count, 0 , output, 0);
		
	}
	
	private void combination(char input[], int count[], int pos, char output[], int len){
		Print(output,len);
		for(int i=pos; i<input.length; i++){
			if(count[i]==0){
				continue;
			}
			output[len] = input[i];
			count[i]--;
			combination(input, count, i, output, len+1);
			count[i]++;
		}
	}
	
	void Print(char result[], int pos){
		for(int i=0 ; i<pos; i++){
			System.out.print(result[i]+" ");
			
		}
		System.out.println();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Combination c = new Combination();
		c.combination("aabbc".toCharArray());
	}

}
