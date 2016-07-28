#if 0
#include <iostream>
using namespace std;

int getSum(int BIT[], int index)
{
	index++;
	int sum = 0;

	while (index > 0)
	{
		sum += BIT[index];
		index -= (index & -index);
	}
	return sum;
}


void updateBIT(int BIT[], int n, int index, int num)
{
	index++;
	while (index <= n)
	{
		BIT[index] += num;
		index += (index & -index);
	}
}

int *constructBITree(int arr[], int n)
{
	int *BIT = new int[n + 1];

	for (int i = 0; i <= n; i++)
		BIT[i] = 0;

	for (int i =0; i <= n; i++)
	{
		updateBIT(BIT, n, i, arr[i]);
	}

	return BIT;
}


int main()
{
	int freq[] = { 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9 };
	int n = sizeof(freq) / sizeof(freq[0]);
	int *BITree = constructBITree(freq, n);
	cout << "Sum of elements in arr[0..5] is "<< getSum(BITree, 5);

	// Let use test the update operation
	freq[3] += 6;
	updateBIT(BITree, n, 3, 6); //Update BIT for above change in arr[]

	cout << "\nSum of elements in arr[0..5] after update is "<< getSum(BITree, 5);
	getchar();
	return 0;
}

#endif