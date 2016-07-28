#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int RMQUtil(int *st, int ss, int se, int qs, int qe, int index)
{
	if (qs <= ss && qe >= se)
		return st[index];

	if (se < qs || ss > qe)
		return INT_MAX;

	int mid = ss + (se - ss) / 2;
	return min( RMQUtil(st, ss, mid, qs, qe, 2 * index + 1), RMQUtil(st, mid + 1, se, qs, qe, 2 * index + 2) );
}

int RMQ(int *st, int n, int qs, int qe)
{
	if (qs<0 || qe>n - 1 || qs > qe)
	{
		cout << "Invalid Input";
		return -1;
	}

	return RMQUtil(st, 0, n - 1, qs, qe, 0);
}

int constructUtil(int arr[], int ss, int se, int *st, int si)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	int mid = ss + (se - ss) / 2;
	st[si] = min(constructUtil(arr, ss, mid, st, si * 2 + 1), constructUtil(arr,mid+1,se,st,si*2+2));
	return st[si];
}

int *constructST(int arr[], int n)
{
	int *st = new int[4 * n];
	constructUtil(arr, 0, n - 1, st, 0);

	return st;
}

int main()
{
	int arr[] = { 1, 3, 2, 7, 9, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// Build segment tree from given array
	int *st = constructST(arr, n);

	int qs = 1;  // Starting index of query range
	int qe = 5;  // Ending index of query range

				 // Print minimum value in arr[qs..qe]
	printf("Minimum of values in range [%d, %d] is = %d\n",
		qs, qe, RMQ(st, n, qs, qe));
	getchar();
	return 0;
}
#endif