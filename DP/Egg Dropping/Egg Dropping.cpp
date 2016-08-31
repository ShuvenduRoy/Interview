#if 0

#include <iostream>	
#include <limits.h>
#include <algorithm>

using namespace  std;

/*int eggDrop(int n, int k)
{
	if (k == 1 || k == 0)
		return k;
	if (n == 1)
		return k;

	int min = INT_MAX, res;
	for (int x = 1; x <= k; x++)
	{
		res = max(eggDrop(n - 1, x - 1), eggDrop(n, k - x));
		if (res < min)
			min = res;
	}
	return min + 1;
}*/


int eggDrop(int n, int k)
{
	int **eggFloor = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
		eggFloor[i] = new int[k + 1];
	int res;
	for (int i = 1; i <= n; i++)
	{
		eggFloor[i][1] = 1;
		eggFloor[i][0] = 0;
	}

	for (int j = 1; j <= k; j++)
		eggFloor[1][j] = j;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 2; j <= k; j++)
		{
			eggFloor[i][j] = INT_MAX;
			for (int x = 1; x <= j; x++)
			{
				res = 1 + max(eggFloor[i - 1][x - 1], eggFloor[i][j - x]);
				if (res < eggFloor[i][j])
					eggFloor[i][j] = res;
			}
		}
	}
	return eggFloor[n][k];
}

int main()
{
	int n = 2, k = 10;
	cout << eggDrop(n, k) << endl;
	getchar();
}

#endif 