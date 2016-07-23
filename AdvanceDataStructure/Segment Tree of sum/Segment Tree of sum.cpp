#if 0
#include<iostream>
#include<algorithm>
using namespace std;

int getMid(int s, int e) { return s + (e - s) / 2; }

void updateValueUtil(int *st, int ss, int se, int i, int diff, int si)
{
	if (i<ss || i>se)
		return;

	st[si] += diff;
	if (ss != se)
	{
		int mid = getMid(ss, se);
		updateValueUtil(st, ss, mid, i, diff, 2 * si + 1);
		updateValueUtil(st, mid+1, se, i, diff, 2 * si + 2);
	}
}

void updateValue(int *arr, int *st, int n, int i, int newVal)
{
	int diff = newVal - arr[i];
	arr[i] = newVal;
	updateValueUtil(st, 0, n - 1, i, diff, 0);
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si)
{
	if (qs <= ss && qe >= se)
		return st[si];
	if (se<qs || ss>qe)
		return 0;
	int mid = getMid(ss, se);

	return getSumUtil(st, ss, mid, qs, qe, 2 * si + 1) + getSumUtil(st, mid + 1, se, qs, qe, 2 * si + 2);
}

int getSum(int *st, int n, int qs, int qe)
{
	return getSumUtil(st, 0, n - 1, qs, qe, 0);
}

int constructSTUtil(int arr[], int *st, int ss, int se, int si)
{
	if (ss == se)
	{
		st[si] = arr[ss];
		return arr[ss];
	}

	int mid = getMid(ss, se);

	st[si] = constructSTUtil(arr, st, ss, mid, 2 * si + 1) + constructSTUtil(arr, st, mid + 1, se, 2 * si + 2);
	return st[si];
}

int *constructST(int arr[], int n)
{
	int *st = new int[4 * n];
	constructSTUtil(arr, st, 0, n - 1, 0);
	return st;
}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 11 };
	int n = sizeof(arr) / sizeof(arr[0]);

	int *st = constructST(arr, n);

	printf("Sum of values in given range = %d\n", getSum(st, n, 1, 3));

	updateValue(arr, st, n, 1, 10);

	printf("Updated sum of values in given range = %d\n",
		getSum(st, n, 1, 3));
	getchar();
	return 0;
}

#endif