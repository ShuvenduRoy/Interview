package bit2D;


public class Bit {
	
	public int getSum(int binaryIndexedTree[], int index){
		index+=1;
		int sum=0;
		while(index>0){
			sum+=binaryIndexedTree[index];
			index=getParent(index);
		}
		return sum;
	}
	
	/**
	 * This function returns the next index
	 * next function is gotten from fliping the last set bit
	 * to get that we first flip all by taking 1's complement than add 1 which one is added at the
	 * position of 1st zero which was the position was 1st 1; this whole is actually 2's complement
	 * Now we operate and operation to get only one 1 at the desired bit position with all zero
	 * by adding or deletion this with current index we get the next and previous index :D
	 */
	private int getNext(int index){
		return index+(index & -index);
	}
	
	private int getParent(int index){
		return index-(index & -index);
	}
	
	//This function update the bit array
	//binaryIndexedTree[i] stored the sum till i, but not i
	public void updateBinaryIndexedTree(int binaryIndexedTree[], int value, int index){
		while(index<binaryIndexedTree.length){
			binaryIndexedTree[index]+=value;
			index=getNext(index);
		}
	}
	
	//This function creates a bit and return the array
	public int[] createTree(int input[]){
		int binaryIndexedTree[]=new int[input.length+1];
		for(int i=1; i<=input.length; i++){
			//Send to update the value in the array from 0-length-1
			updateBinaryIndexedTree(binaryIndexedTree, input[i-1], i);
		}
		return binaryIndexedTree;
	}
	
	public static void main(String args[])
	{
		int input[]={1,2,3,4,5,6,7};
		Bit ft=new Bit();
		int binaryIndexedTree[]=ft.createTree(input);
		System.out.print(ft.getSum(binaryIndexedTree, 3));
	}
}
