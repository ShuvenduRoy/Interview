#if 0

#include<iostream>
#include<algorithm>
#include<stdio.h>
#include <limits>
using namespace std;

int maxSumIS(int arr[], int n)
{
	int *lis = new int[n + 1];
	for (int i = 0; i <= n; i++)
		lis[i] = arr[i];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j] && lis[i] < lis[j] + arr[i])
				lis[i] = lis[j] + arr[i];
		}
	}

	int ans = arr[0];
	for (int i = 0; i <= n; i++)
	{
		if (lis[i] > ans)
			ans = lis[i];
	}
	return ans;
}

int main()
{
	int arr[] = { 1, 101, 2, 3, 100, 4, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Sum of maximum sum increasing subsequence is %d\n",
		maxSumIS(arr, n));
	getchar();
	return 0;
}

#endif