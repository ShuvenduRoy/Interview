#if 0

#include<iostream>
#include<limits>
#include <algorithm>
using namespace std;

bool findPartition(int arr[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];

	if (sum % 2 == 1) return false;
	else
	{
		sum = sum / 2 + 1;
		bool **part = new bool*[sum];
		for (int i = 0; i < sum; i++)
		{
			part[i] = new bool[n + 1];
		}

		for (int i = 0; i < sum; i++)
			part[i][0] = false;
		for (int i = 0; i < n + 1; i++)
			part[0][i] = true;

		for (int i = 1; i < sum; i++)
		{
			for (int j = 1; j < n + 1; j++)
			{
				part[i][j] = part[i][j - 1];
				if (i >= arr[j - 1])
				{
					part[i][j] = part[i][j] || part[i - arr[j - 1]][j - 1];
				}
			}
		}
		return part[sum - 1][n];
	}

}

int main()
{
	int arr[] = { 3, 1, 1, 2, 2, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);
	if (findPartition(arr, n) == true)
		printf("Can be divided into two subsets of equal sum");
	else
		printf("Can not be divided into two subsets of equal sum");
	getchar();
	return 0;
}

#endif