#if 0
#include <iostream>
using namespace std;

int Merge(int *arr, int *temp, int l, int mid, int r)
{
	int inv_counter = 0;
	int i, j, k;
	i = k = l;
	j = mid;
	while ((i <= mid - 1) && ( j <= r))
	{
		if (arr[i] <= arr[j])
			temp[k++] = arr[i++];
		else
		{
			temp[k++] = arr[j++];
			inv_counter += mid - i;
		}
			
	}
	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j<=r)
	{
		temp[k++] = arr[j++];
	}
	for (int i = l; i <= r; i++)
	{
		arr[i] = temp[i];
	}
	return inv_counter;
}

int MergeSort(int *arr, int *temp, int l, int r)
{
	int mid;
	int inv_count = 0;

	if (l < r)
	{
		mid = (l + r) / 2;
		inv_count = MergeSort(arr, temp, l, mid);
		inv_count += MergeSort(arr, temp, mid + 1, r);
		inv_count += Merge(arr, temp, l, mid+1, r);
	}

	return inv_count;
}

int mergeSort(int arr[], int n)
{
	int *temp = new int[n];
	return MergeSort(arr, temp, 0, n - 1);
}

int main(int argv, char** args)
{
	int arr[] = { 1, 20, 6, 4, 5 };
	printf(" Number of inversions are %d \n", mergeSort(arr, 5));
	getchar();
	return 0;
}

#endif