package quickSort;

public class qSort {
	public int pertition(int arr[], int start, int end){
		int pIndex = start;
		
		for(int i=start; i<end; i++){
			if(arr[i] <= arr[end]){
				int temp = arr[i];
				arr[i] = arr[pIndex];
				arr[pIndex] = temp;
				
				pIndex++;
			}
		}
		int temp = arr[end];
		arr[end] = arr[pIndex];
		arr[pIndex] = temp;
		
		
		return pIndex;
	}
	
	void QuickSort(int arr[], int start, int end){
		if(start<end){
			int pivot = pertition(arr,start,end);
			QuickSort(arr, start, pivot-1);
			QuickSort(arr, pivot+1, end);
		}
	}
	
	public static void main(String args[]){
		qSort qs = new qSort();
		int arr[] = {2,1,4,5};
		qs.QuickSort(arr, 0, 3);
		
		for(int i=0; i<4; i++)
			System.out.println(arr[i]);
	}
	
}
