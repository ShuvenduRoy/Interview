#if 0
#include <iostream>
#include <limits.h>
using namespace std;

int MatrixChainManupulation(int *arr,int n)
{
	int **temp = new int*[n ];
	for (int i = 0; i < n; i++)
		temp[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			temp[i][j] = 0;

	for (int l = 2; l < n; l++)
	{
		for (int i = 0; i < n-l; i++)
		{
			int j = i +l;
			temp[i][j] = INT_MAX;
			for (int k = i+1; k < j; k++)
			{
				int q = temp[i][k] + temp[k][j] + arr[i] * arr[k] * arr[j];
				if (q < temp[i][j])
					temp[i][j] = q;
			}
		}
	}
	return temp[0][n - 1];
}

int main()
{
	int arr[] = { 4,2,3,5,3 };
	cout<<MatrixChainManupulation(arr,5);
	getchar();
}

#endif