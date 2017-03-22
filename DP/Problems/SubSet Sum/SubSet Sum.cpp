#if 1
#include <iostream>
#include <limits.h>
using namespace std;

int SubsetSum(int *arr, int n, int sum)
{
	bool **temp = new bool*[n+1];
	for (int i = 0; i < n+1; i++)
		temp[i] = new bool[sum+1];

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <=sum; j++)
			temp[i][j] = false;

	for (int i = 0; i <= n; i++)
		temp[i][0] = true;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= sum; j++)
		{
			if (arr[i] > sum)
				temp[i][j] = temp[i - 1][j];
			else
			{
				temp[i][j] = temp[i - 1][j] || temp[i - 1][j - arr[i]];
			}
		}
	}

	return temp[n][sum];
}

int main()
{
	int arr[] = { 1, 3, 5, 5, 2, 1, 1, 6 };
	int arr1[] = { 2, 3, 7, 8 };
	cout << SubsetSum(arr,5,11) << endl;
}

#endif
